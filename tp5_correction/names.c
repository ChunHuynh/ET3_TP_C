#include "names.h"
#include "utils.h"

// Read a string from terminal, allocate memory to store it then return the string
char* read_name()
{
  char str[256]; // Buffer
  int good = 0; // Reading flag
  do
  {
    printf("Give me a name :\n>"); // scanf() => printf() !
    good = scanf("%s", str);
  }
  while(!good); // Tant que l'utilisateur n'a pas entré de string correcte, on lui en redemande
  
  const int size = strlen(str);
  char* name = malloc(sizeof(char) * size);
  out_of_memory(name, "in read_name() function");

  for (int i=0; i < size; i++)
  {
    name[i] = str[i];
  }
  return name;
}

// Return the given char after lower case conversion
char c_to_lower(char c){
  if ( c >= 'A' && c <= 'Z')
    c = c + ('a' - 'A');
  return c;
}


// Return a copy of the given string after lower case conversion
char* lower_case(const char* str){
  if (is_null(str, "lower_case"))
    return NULL;
  int length = strlen(str);
  char* lower = malloc(sizeof(char)*length);
    out_of_memory(lower, "in lower_case() function");

  for (int i = 0; i < length; ++i)
  {
    lower[i] = c_to_lower(str[i]);
  }
  return lower;
}


// Return the given char after upper case conversion
char c_to_upper(char c){
  if ( c >= 'a' && c <= 'z')
    c = c - ('a' - 'A');
  return c;
}

// Return a copy of the given string after upper case conversion
char* upper_case(const char* str){
  if (is_null(str, "upper_case"))
    return NULL;
  int length = strlen(str);
  char* upper = malloc(sizeof(char)*length);
    out_of_memory(upper, "in upper_case() function");
    
  for (int i = 0; i < length; ++i)
  {
    upper[i] = c_to_upper(str[i]);
  }
  return upper;
}

// Give the rank (1-26) in alphabet if c is a letter, -1 otherwise
int letter_to_num(const char c){
  int res = - 1;
  if ( c >= 'a' && c <= 'z')
    res = c - 'a' + 1;
  else if( c >= 'A' && c <= 'Z')
    res = c - 'A' + 1;
  return res;
}

// Append given string to the given table of strings.
void append(char*** tab, const size_t size, char* name)
{
  char** new_tab = realloc(*tab, (size+1)*sizeof(char*));
  out_of_memory(new_tab, "in append() function");
  new_tab[size] = name;
  *tab = new_tab;
}


// Return the minimum between 2 integers
int min(const int l, const int r){
  if (l <= r)
    return l;
  else
    return r;
}

// Return : l > r
int bigger(const char* l, const char* r){
  if (l == NULL || r == NULL)
  {
    printf("Warning : Null pointer in bigger() !\n");
    return 0;
  }
  int len_l = strlen(l);
  int len_r = strlen(r);
  int len = min(len_l, len_r);
  for (int i = 0; i < len; ++i)
  {
    if (l[i] > r[i])
      return 1;
  }
  if (len_l > len_r)
    return 1;
  else
    return 0;
}

// Return : l < r
int smaller(const char* l, const char* r){
  int len_l = strlen(l);
  int len_r = strlen(r);
  int len = min(len_l, len_r);
  for (int i = 0; i < len; ++i)
  {
    if (l[i] < r[i])
      return 1;
  }
  if (len_l < len_r)
    return 1;
  else
    return 0;
}

int compare(const char* l, const char* r){
  if (smaller(l, r)) return -1;
  else if (bigger(l, r)) return 1;
  else return 0;
}

// Swap the given strings. References to char* must be given.
void swap_str_address(char** l, char** r)
{
  char* tmp = *l;
  *l = *r;
  *r = tmp;
}

// Source : https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
void quicksort(char **A, const int len)
{
  if (len < 2) return;

  char* pivot = A[len / 2];

  int i, j;
  for (i = 0, j = len - 1; ; i++, j--)
  {
    while (smaller(A[i], pivot)) i++;
    while (bigger(A[j], pivot)) j--;

    if (i >= j) break;

    swap_str_address(&A[i], &A[j]);
  }

  quicksort(A, i);
  quicksort(A + i, len - i);
}
