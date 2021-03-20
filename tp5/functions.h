#ifndef FUNCTIONS_H
#define FUNCTIONS_H

char* read_name();

void delete_str(char* ptr);

char* lower_case(char* str);

char* upper_case(char* str);

int letter_to_name(char c);

void append(char* str, char** tab, const size_t size);

int bigger(char* left, char*right);

int smaller(char* left, char*right);

int compare(char* left, char*right);

void swap_str(char* left, char* right);

void sort_out(char** tab);

#endif
