//
// Created by yrustt on 11.12.17.
//

#include <stdio.h>
#include <openssl/md5.h>
#include "calc.h"
#include "models.h"


void calc_hash(FILE *file, struct Hash *hash) {
    MD5_CTX mdContext;
    unsigned char data[1024];

    MD5_Init(&mdContext);
    int bytes;
    while ((bytes = fread(data, 1, 1024, file)) != 0) {
        MD5_Update(&mdContext, data, bytes);
    }
    MD5_Final(hash->value, &mdContext);
}


int calc_hash_from_file(const char *path, struct Hash *hash) {
    int bytes;
    FILE *in = fopen(path, "rb");

    if (in == NULL) {
        printf ("%s can't be opened.\n", path);
        return 1;
    }

    calc_hash(in, hash);

    fclose(in);
    return 0;
}


int calc_hash_from_console(struct Hash *hash) {
    calc_hash(stdin, hash);

    return 0;
}
