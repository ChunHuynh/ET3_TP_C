#ifndef NUM_H_INCLUDED
#define NUM_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>
#include "utils.h"

void print_tab(const float *tab, const size_t size);
void fill_tab(float *tab, const size_t size, const float value);
float* arange(const size_t size);

float* add_tab(const float* tab_A, const float* tab_B, const size_t size);
float* sub_tab(const float* tab_A, const float* tab_B, const size_t size);
float* mul_tab(const float* tab_A, const float* tab_B, const size_t size);

void fill_tab_2D(float *tab, const size_t n, const size_t m, const float value);
void print_tab_2D(const float *tab, const size_t n, const size_t m);
float* add_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m);
float* sub_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m);
float* mul_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m);
float* transpose_2D(const float *tab, const size_t n, const size_t m);
float* line_sum_tab_2D(const float* tab_A, const size_t n, const size_t m);
float* column_sum_tab_2D(const float* tab_A, const size_t n, const size_t m);
float* mat_mul_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m, const size_t p);



#endif