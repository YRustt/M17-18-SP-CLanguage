//
// Created by yrustt on 11.12.17.
//

#include <stdio.h>
#include <openssl/md5.h>
#include "calc.h"
#include "models.h"


int calc_hash_from_file(const char *path, struct Hash *hash) {
    int bytes;
    FILE *in = fopen(path, "rb");
    MD5_CTX mdContext;
    unsigned char data[1024];

    if (in == NULL) {
        printf ("%s can't be opened.\n", path);
        return -1;
    }

    MD5_Init(&mdContext);
    while ((bytes = fread (data, 1, 1024, in)) != 0) {
        MD5_Update(&mdContext, data, bytes);
    }
    MD5_Final(hash->value, &mdContext);

    fclose (in);

    return 0;
}


int calc_hash_from_console(struct Hash *hash) {
    return 0;
}