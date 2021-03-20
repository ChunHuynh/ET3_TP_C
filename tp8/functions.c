#include <stdio.h>
#include "functions.h"

//////// Ex1 ////////
FILE * open_file(char * filename, char * mode)
{
	FILE * f;
	f = fopen(filename, mode);
	if (!f)
	{
		printf("Erreur ouverture");
		return NULL;
	}
	
	return f;
}

void close_file(FILE ** f)
{
	if (*f)
	{
		fclose(*f);
		*f = NULL;
	}
}

//////// Ex2 ////////
int * init_mat(int n)
{
	int * tab = (int*) calloc(n*n,sizeof(int));
	
	for (int i = 0; i < n*n; i++)
	{
		tab[i] = 0;
	}
	
	return tab;
}

void delete_mat(int * ptr)
{
	if (ptr) free(ptr);
}

read_matrix()
{
	
}

// for fgets() and fscanf("%d;") not forget ';' at the end 
