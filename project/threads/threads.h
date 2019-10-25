#ifndef PROJECT_THREADS_THREADS_H_
#define PROJECT_THREADS_THREADS_H_

#include <stdio.h>
#include <stdlib.h>

#include "DynArray.h"

#define MAX_CHARS 50
#define MAX_THREADS 4

typedef struct {
    char* filename;
    char* sequence;
    DynArray* array;
} thread_args;

int check_file(const char* filename);
void collect_garbage(DynArray **array_2d, size_t len_2d, thread_args *args);

void* my_strstr(void* args);

int find_indices(char* const filename, const size_t seqs_amount, char **sequences);

#endif  //  PROJECT_THREADS_THREADS_H_
