#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"

//////// Ex1 ////////
int* createArrayInt()
{
		int* tab = (int*) calloc(10, sizeof(int)); 
		for(int i = 0; i < 10; i++)
		{	
			printf("| %d |", tab[i]);
		}
		printf("\n");

	return tab;
}

float* createArrayFloat()
{
			float* tab = (float*) calloc(10, sizeof(float));
			for(int i = 0; i < 10; i++)
			{
				printf("| %f |", tab[i]);
			}
			printf("\n");

	return tab;
}

void deleteArrayInt(int *ptr)
{
	if (ptr) free(ptr);
}

void deleteArrayFloat(float *ptr)
{
	if (ptr) free(ptr);
}

void initArrayInt(int nb, int * tab, int *length)
{	
	for(int i = 0; i < *length; i++)
	{
		tab[i] = nb;
	}
}

void initArrayFloat(float nb, float * tab)
{	
	for(int i = 0; i < 10; i++)
	{
		tab[i] = nb;
	}
}

int findInt(int nb, int * tab, int *length)
{
	for(int i = 0; i < *length; i++)
	{
		if(tab[i] == nb)
			return 1;
	}
	return 0;
}

unsigned int nbCounter(int nb, int * tab, int *length)
{
	unsigned int count = 0;
	for(int i = 0; i < *length; i++)
	{
		if(tab[i] == nb)
			count++;
	}
	return count;
}

int getRand(int min, int max)
{
	return rand() % (max - min + 1) + min;
}

int* createArrayRand(int length, int min, int max)
{
	int* tab = (int*) calloc(length, sizeof(int));

	for (int i = 0; i < length; i++)
	{
		tab[i] = getRand(min, max);
		printf("[%d]", tab[i]);
	} 

	return tab;
}

int* createArrayTotalyRand(int lengthMin, int lengthMax, int min, int max, int * length)
{
	*length = getRand(lengthMin, lengthMax);

	return createArrayRand(*length, min, max);
}