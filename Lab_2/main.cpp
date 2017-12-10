//
// Created by rustam on 21.10.17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>


struct Vector {
    size_t capacity;
    size_t size;
    int* v;
};


bool vector_init(struct Vector* v) {
    v->capacity = 1;
    v->size = 0;
    v->v = (int*) malloc(sizeof(int));
    return (bool) v->v;
}


bool vector_push_back(struct Vector* v, int x) {
    if (v->size == v->capacity) {
        if (v->capacity >= SIZE_MAX / (sizeof(int) * 2) + 1) {
            return false;
        }

        int* new_v = (int*) realloc(v->v, (sizeof(int) * 2) * v->capacity);
        if (new_v) {
            v->capacity *= 2;
            v->v = new_v;
        } else {
            return false;
        }
    }

    v->v[v->size] = x;
    v->size++;
    return true;
}


const int* vector_at(const struct Vector* v, size_t index) {
    if (index >= v->size) {
        return NULL;
    }
    return &v->v[index];
}


void vector_free(struct Vector* v) {
    v->capacity = 0;
    v->size = 0;
    free(v->v);
}


int map_operation(struct Vector* v) {
    static char push_back[20] = "push_back";
    static char at[20] = "at";

    static char str[20];
    static int x;
    static size_t index;

    int res = scanf("%s", str);

    if (res == EOF) {
        return res;
    }

    if (strcmp(str, push_back) == 0) {
        res = scanf("%d", &x);
        vector_push_back(v, x);

        return res;
    }
    if (strcmp(str, at) == 0) {
        res = scanf("%zu", &index);

        const int* ptr = vector_at(v, index);
        if (ptr == NULL) {
            printf("out_of_range\n");
        } else {
            printf("%d\n", *ptr);
        }

        return res;
    }

    perror("Bad command name");
    return res;
}


int main() {
    struct Vector vector;

    if (!vector_init(&vector)) {
        return 1;
    }

    while (map_operation(&vector) != EOF);

    vector_free(&vector);
    return 0;
}