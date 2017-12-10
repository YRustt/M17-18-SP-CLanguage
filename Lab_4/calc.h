//
// Created by yrustt on 11.12.17.
//

#ifndef PROJECT_CALC_H
#define PROJECT_CALC_H

#include "models.h"

int calc_hash_from_file(const char *path, struct Hash *hash);
int calc_hash_from_console(struct Hash *hash);

#endif //PROJECT_CALC_H
