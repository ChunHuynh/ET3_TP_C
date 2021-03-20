#ifndef FUNCTIONS_H
#define FUNCTIONS_H

FILE * open_file(char * filename, char * mode);

void close_file(FILE ** f);

int * init_mat(int n);

void delete_mat(int * ptr);

#endif
