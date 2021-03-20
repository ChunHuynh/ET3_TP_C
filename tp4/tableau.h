#ifndef TABLEAU_H
#define TABLEAU_H

int* createArrayInt();

float* createArrayFloat();

void deleteArrayInt(int *ptr);

void deleteArrayFloat(float *ptr);

void initArrayInt(int nb, int * tab, int *length);

void initArrayFloat(float nb, float * tab);

int findInt(int nb, int * tab, int *length);

unsigned int nbCounter(int nb, int * tab, int *length);

int getRand(int min, int max);

int* createArrayRand(int length, int min, int max);

int* createArrayTotalyRand(int lengthMin, int lengthMax, int min, int max, int * length);



#endif