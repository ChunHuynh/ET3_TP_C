#include "num.h"

int empty_tab(const float* tab, const size_t size, const char * loc){
  int res = 0;
  if (tab == NULL || size == 0){
    printf("Empty table in %s\n", loc);
    res = 1;
  }
  return res;
}

float* arange(const size_t size){
  float* res = calloc(size, sizeof(float));
  out_of_memory(res, "arange");
  for (size_t i = 0; i < size; ++i)
  {
    res[i] = (float) i;
  }
  return res;
}

void print_tab(const float *tab, const size_t size){
  if (tab == NULL || size == 0)
  {
    printf("Warning : Empty tab given in print_tab() !\n");
    return;
  }
  printf("[ ");
  for (size_t i = 0; i < size; ++i)
  {
    printf("%f ", tab[i]);
  }
  printf("]\n");
}


void fill_tab(float *tab, const size_t size, const float value){
  if (tab == NULL || size == 0)
  {
    printf("Warning : Empty tab given in fill_tab() !\n");
    return;
  }

  for (size_t i = 0; i < size; ++i)
  {
    tab[i] = value;
  }
}




float* add_tab(const float* tab_A, const float* tab_B, const size_t size){
  if (tab_A == NULL) 
  { 
    printf("Warning : Null pointer given (tab_A) in add_tab() !\n");
    return NULL;
  }
  if (tab_B == NULL) 
  { 
    printf("Warning : Null pointer given (tab_B) in add_tab() !\n");
    return NULL;
  }
  if (size == 0)
  {
    printf("Warning : tab size = 0 in add_tab() !\n");
    return NULL;
  }

  float* res = calloc(size, sizeof(float));
  out_of_memory(res, "add_tab");

  for (size_t i = 0; i < size; ++i)
  {
    res[i] = tab_A[i] + tab_B[i];
  }
  return res;
}

float* sub_tab(const float* tab_A, const float* tab_B, const size_t size){
  if (tab_A == NULL) 
  { 
    printf("Warning : Null pointer given (tab_A) in sub_tab() !\n");
    return NULL;
  }
  if (tab_B == NULL) 
  { 
    printf("Warning : Null pointer given (tab_B) in sub_tab() !\n");
    return NULL;
  }
  if (size == 0)
  {
    printf("Warning : tab size = 0 in sub_tab() !\n");
    return NULL;
  }

  float* res = calloc(size, sizeof(float));
  out_of_memory(res, "sub_tab");

  for (size_t i = 0; i < size; ++i)
  {
    res[i] = tab_A[i] - tab_B[i];
  }
  return res;
}

float* mul_tab(const float* tab_A, const float* tab_B, const size_t size){
  if (tab_A == NULL) 
  { 
    printf("Warning : Null pointer given (tab_A) in mul_tab() !\n");
    return NULL;
  }
  if (tab_B == NULL) 
  { 
    printf("Warning : Null pointer given (tab_B) in mul_tab() !\n");
    return NULL;
  }
  if (size == 0)
  {
    printf("Warning : tab size = 0 in mul_tab() !\n");
    return NULL;
  }

  float* res = calloc(size, sizeof(float));
  out_of_memory(res, "mul_tab");

  for (size_t i = 0; i < size; ++i)
  {
    res[i] = tab_A[i] * tab_B[i];
  }
  return res;
}


void fill_tab_2D(float *tab, const size_t n, const size_t m, float value){
  fill_tab(tab, n*m, value);
}

void print_tab_2D(const float *tab, const size_t n, const size_t m){
  if (tab == NULL || n == 0 || m == 0)
  {
    printf("Warning : Empty tab given in print_tab_2D() !\n");
    return;
  }
  for (size_t i = 0; i < n; ++i)
  {
    printf("[ ");
    for (size_t j = 0; j < m; ++j)
    {
      printf("%12.4f ", tab[i*m+j]);
    }
    printf("]\n");
  }
}

float* add_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m){
  return add_tab(tab_A, tab_B, n*m);
}

float* sub_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m){
  return sub_tab(tab_A, tab_B, n*m);
}

float* mul_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m){
  return mul_tab(tab_A, tab_B, n*m);
}

float* transpose_2D(const float *tab, const size_t n, const size_t m){
  if (tab == NULL) 
  { 
    printf("Warning : Null pointer given in transpose_2D() !\n");
    return NULL;
  }
  if (n*m == 0)
  {
    printf("Warning : tab size = 0 in transpose_2D() !\n");
    return NULL;
  }

  float* res = calloc(m*n, sizeof(float));
  out_of_memory(res, "transpose_2D");

  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      res[j*n+i] = tab[i*m+j];
    }
  }
  return res;
}

// Cette version utilise un accumulateur (acc) afin de calculer la somme des lignes.
float* line_sum_tab_2D(const float* tab, const size_t n, const size_t m){
  if (tab == NULL) 
  { 
    printf("Warning : Null pointer given in line_sum_tab_2D() !\n");
    return NULL;
  }
  if (n*m == 0)
  {
    printf("Warning : tab size = 0 in line_sum_tab_2D() !\n");
    return NULL;
  }

  float* res = calloc(n, sizeof(float));
  out_of_memory(res, "line_sum_tab_2D");
  for (size_t i = 0; i < n; ++i)
  {
    float acc = 0.0;
    for (size_t j = 0; j < m; ++j)
    {
      acc += tab[i*m+j];
    }
    res[i] = acc;
  }
  return res;
}

// Cette version accumule directement dans le tableau de résultat. 
// Il faut bien utiliser calloc() pour s'assurer que le tableau (res) est initialisé avec des zéros.
float* column_sum_tab_2D(const float* tab, const size_t n, const size_t m){
  if (tab == NULL) 
  { 
    printf("Warning : Null pointer given in column_sum_tab_2D() !\n");
    return NULL;
  }
  if (n*m == 0)
  {
    printf("Warning : tab size = 0 in column_sum_tab_2D() !\n");
    return NULL;
  }

  float* res = calloc(m, sizeof(float));
  out_of_memory(res, "column_sum_tab_2D");
  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < m; ++j)
    {
      res[j] += tab[i*m+j];
    }
  }
  return res;
}

// Dans les 2 questions sur les sommes (de lignes ou colonnes) on a pris soin de parcourir les tableaux dans l'ordre.
// Ceci permet d'optimiser la mémoire cache. C'est un détail qui permet d'assurer un temps d'exécution plus court.

// La fonction help_mat_mul() n'est pas présente dans le fichier num.h car on n'en a besoin que pour simplifier le code de multiplication des matrices.
// Ceci permet d'éviter d'écrire les tests de pointeur NULL car on sait que les pointeurs ne sont pas NULL puisque seul nous pouvons utiliser cette fonction.
float help_mat_mul(const float* tab_A, const float* tab_B, const size_t m, const size_t p, const size_t i, const size_t j){
  float acc = 0.0;
  for (size_t k = 0; k < m; ++k)
  {
    acc += tab_A[i*m+k] * tab_B[k*p+j];
  }
  return acc;
}

float* mat_mul_tab_2D(const float* tab_A, const float* tab_B, const size_t n, const size_t m, const size_t p){
  if (tab_A == NULL) 
  { 
    printf("Warning : Null pointer given (tab_A) in mat_mul_tab_2D() !\n");
    return NULL;
  }
  if (tab_B == NULL) 
  { 
    printf("Warning : Null pointer given (tab_B) in mat_mul_tab_2D() !\n");
    return NULL;
  }
  if (n*m == 0)
  {
    printf("Warning : tab_A size = 0 in mat_mul_tab_2D() !\n");
    return NULL;
  }
  if (m*p == 0)
  {
    printf("Warning : tab_B size = 0 in mat_mul_tab_2D() !\n");
    return NULL;
  }

  float* res = calloc(n*p, sizeof(float));
  out_of_memory(res, "mat_mul_tab_2D");

  for (size_t i = 0; i < n; ++i)
  {
    for (size_t j = 0; j < p; ++j)
    {
      res[i*p+j] = help_mat_mul(tab_A, tab_B, m, p, i, j);
    }
  }
  return res;
}

