#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(int argc, char ** argv)
{
	printf("Nombre d'arguments : %d\n", argc);

	for (int i = 0; i < argc ; i++) 
	{
		printf (" Argument %d: %s\n", i, argv [i]) ;
	}
	
	if (argc == 1)
	{
		printf("Mauvais nombre de paramètres.\n");
		return 1;
	}
	int flag = atoi(argv[1]);
	if (flag != 2 && flag != 3)
	{
		printf("2 ou 3 en paramètres.\n");
	}
	if (flag == 2)
	{
		// read and write a float in a file
		FILE * p = open_file(argv[3], "w"); // "w": write mode
		
		float val = atof(argv[2]);
		fprintf(p, "%f\n", val);
		
		// close the file
		close_file(&p);
	}
	else if (flag == 3)
	{
		FILE * file1 = open_file(argv[3], "r"); // "r":read mode
		FILE * file2 = open_file(argv[4], "a"); // "a":append mode
		
		float val  = atof(argv[2]);
		float val1 = 0;
		fscanf(file1, "%f", &val);
		
		val += val1;
		
		fprintf(file2, "%f\n", val);
				
		// close files
		close_file(&file1);
		close_file(&file2);
	}
	
	return 0;
}
