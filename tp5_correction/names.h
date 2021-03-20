#ifndef NAMES_H_INCLUDED
#define NAMES_H_INCLUDED 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* read_name();

char c_to_upper(char c);
char c_to_lower(char c);
char* lower_case(const char* str);
char* upper_case(const char* str);
int letter_to_num(const char c);

void swap_str_address(char** l, char** r);

int min(const int l, const int r);
int bigger(const char* l, const char* r);
int smaller(const char* l, const char* r);
int compare(const char* l, const char* r);

void quicksort(char **A, const int len);
void append(char*** tab, const size_t size, char* name);

void print_bool(const int b);


#endif