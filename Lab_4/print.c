//
// Created by yrustt on 11.12.17.
//

#include <stdio.h>
#include <stdint.h>
#include "print.h"
#include "models.h"


void print_hash(const struct Hash *hash) {
    uint8_t length = sizeof(hash->value);
    for (uint8_t i = 0; i < length; ++i) {
        printf("%02x", hash->value[i]);
    }
}