#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include "functions.h"

//////// Ex1 ////////
void get_string(char* word)
{
	printf("Write something : ");
	fgets(word, 100*sizeof(char), stdin);
	// use of fgets instead of gets(dangerous) to get full sentence
}

//////// Ex2 ////////
char add_char(char word, int key) // TODO: manage Upper letter 
{
	key %= 26; // to keep the addition between 'a' and 'z'
	if(word+key > 'z')
		return (word+key) - 26;
	else
		return word+key;
}


char* add_string(char* word, int key) // TODO: manage the ponctuation
{
	char* coded_word = (char*) malloc(sizeof(word));
	for(int i = 0; i < strlen(word); i++)
	{
		if(isspace(word[i])) // isspace() from ctype.h library
			coded_word[i] = word[i];
		else 
			coded_word[i] = add_char(word[i], key);
	}
	return coded_word;
}


void string_delete(char* str)
{
	if(str) {free(str); str = NULL;}
}

//////// Ex3 ////////
long long int rice_seed(int slot)
{
	long long int seed = 0;
	for(int i = 0; i < slot*slot; i++)
	{
		seed += pow(2,i);
		printf("%lli\n", seed);
	}
	return seed;
}

// TODO : use of assert to check eventual errors
// even with long long int, not enough

