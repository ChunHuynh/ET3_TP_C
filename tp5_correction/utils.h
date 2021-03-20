#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

void out_of_memory(const void* ptr, const char * message);
int is_null(const void* str, const char* loc);
void print_bool(const int b);


#endif