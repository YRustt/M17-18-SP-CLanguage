//
// Created by yrustt on 4.12.17.
//

#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <ctype.h>


uint32_t number_length(uint64_t number) {
    uint32_t digit_count = 0;
    while (number != 0) {
        digit_count++;
        number /= 10;
    }
    return digit_count;
}


int main() {
    setmode(fileno(stdin), O_BINARY);
    uint64_t symbol_count = 0, word_count = 0, string_count = 0;
    uint64_t print_char_count = 0;

    int32_t symbol = 0;
    while ((symbol = getchar()) != EOF) {
        // symbols
        symbol_count++;

        // words
        if (isspace(symbol)) {
            if (print_char_count > 0) {
                word_count++;
            }
            print_char_count = 0;
        } else {
            if (isprint(symbol)) {
                print_char_count++;
            }
        }

        // strings
        if (symbol == (int32_t) '\n') {
            string_count++;
        }
    }
    if (print_char_count > 0) {
        word_count++;
    }

    uint32_t length = number_length(symbol_count);

    printf("%*" PRIu64 " ", length, string_count);
    printf("%*" PRIu64 " ", length, word_count);
    printf("%*" PRIu64, length, symbol_count);

}