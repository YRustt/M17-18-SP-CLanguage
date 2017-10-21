//
// Created by rustam on 21.10.17.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>


struct Vector {
    size_t capacity;
    size_t size;
    int* v;
};


void vector_init(struct Vector* v) {
    v->capacity = 1;
    v->size = 0;
    v->v = (int*) malloc(sizeof(int));
}


bool vector_push_back(struct Vector* v, int x) {
    if (v->size == v->capacity) {
        int* new_v = (int*) realloc(v->v, sizeof(int) * (2 * v->capacity));
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


void map_operation(struct Vector* v, char str[20], int num) {
    char push_back[20] = "push_back";
    char at[20] = "at";

    if (strcmp(str, push_back) == 0) {
        vector_push_back(v, num);
        return;
    }
    if (strcmp(str, at) == 0) {
        const int* ptr = vector_at(v, (size_t) num);
        if (ptr == NULL) {
            printf("out_of_range\n");
        } else {
            printf("%d\n", *ptr);
        }
        return;
    }

    perror("Bad command name");
}


int main() {
    struct Vector vector;
    vector_init(&vector);


    char str[20] = {'\0'};
    int num;

    while (scanf("%s %d", str, &num) != EOF) {
        map_operation(&vector, str, num);
    }

    vector_free(&vector);
    return 0;
}