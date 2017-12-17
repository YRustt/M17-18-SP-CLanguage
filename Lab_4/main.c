//
// Created by yrustt on 11.12.17.
//

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "models.h"
#include "print.h"
#include "calc.h"


int main(int argc, char* argv[]) {
    int return_code = 0;
    if (argc == 1) {
        return_code = 2;
        fprintf(stderr, "No files paths are passed\n");
    } else {
        char *path;
        struct Hash hash;
        for (uint32_t i = 1; i < argc; ++i) {
            path = argv[i];
            int result;
            if (!strcmp(path, "-")) {
                result = calc_hash_from_console(&hash);
            } else {
                result = calc_hash_from_file(path, &hash);
            }
            if (result) {
                return_code = 1;
            } else {
                print_hash(&hash);
                printf(" %s\n", path);
            }
        }
    }

    return return_code;
}
