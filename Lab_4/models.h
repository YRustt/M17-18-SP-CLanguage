//
// Created by yrustt on 10.12.17.
//

#ifndef PROJECT_MODELS_H
#define PROJECT_MODELS_H

#include <openssl/md5.h>


struct Hash {
    unsigned char value[MD5_DIGEST_LENGTH];
};

#endif //PROJECT_MODELS_H
