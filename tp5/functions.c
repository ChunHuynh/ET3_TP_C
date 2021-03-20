#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

char* read_name()
{
	char *name = (char*) malloc(20*sizeof(char));
	printf("Enter a name: ");
	scanf("%s", name);
	printf("Name: %s.\n",name); 
	
	return name;
}



void delete_str(char* ptr)
{
	if(ptr) free(ptr);	
}



char* lower_case(char* str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] <= 'Z' && str[i] >= 'A') str[i] += 32;
	}
	return str; 
}



char* upper_case(char* str)
{
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] <= 'z' && str[i] >= 'a') str[i] -= 32;
	}
	return str; 
}



int letter_to_name(char c)
{
	if(c <= 'Z' && c >= 'A') {c = c - 'A' + 1 ; return c;}
	if(c <= 'z' && c >= 'a') {c = c - 'a' + 1 ; return c;}
	else return -1;
}



void append(char* str, char** tab, const size_t size)
{
	tab = (char**) realloc(tab, (size+1)*sizeof(char*));
	tab[size] = str;
}



int bigger(char* left, char*right)
{
	if(strcmp(left, right) > 0) return 1;
	else return 0;
}



int smaller(char* left, char*right)
{
	if(strcmp(left,right) < 0) return 1;
	else return 0;
}



int compare(char* left, char*right)
{
	if(bigger(left, right) == 1) return  1;
	if(smaller(left,right) == 1) return -1;
	else return 0;
}



void swap_str(char* left, char* right)
{
	char buffer = *left;
	*left  = *right;
	*right = buffer;
}



void sort_out(char** tab)
{
	
}
