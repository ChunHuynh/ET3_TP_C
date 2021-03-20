#include <stdio.h>
#include "tableau.h"
#include <stdlib.h>
#include <time.h>

int main(int argc, char **argv)
{
	printf("Nombre d'arguments : %d\n", argc);

	for (int i = 0; i < argc ; i ++)
 	{
		printf("Argument %d : %s\n", i, argv[i]);
	}
	//////// In case of errors ////////
	if (argc == 1)
	{
		printf("Inappropriate number of arguments.\n");
		return -1;
	}

	int flag = atoi(argv[1]);

	if (flag != 2 && flag != 3)
		printf("2 or 3 as arguments.\n");
	

	if (flag == 2)
	{	
		srand(time(NULL));
		int length, lengthMin = atoi(argv[5]), lengthMax = atoi(argv[6]), min = atoi(argv[7]), max = atoi(argv[8]); 
		int* array = createArrayTotalyRand(lengthMin, lengthMax, min , max, &length);

		// initialize an array to a certain number
		int nb = atoi(argv[2]);
		initArrayInt(nb, array, &length);

		// looking for a specific int in an array 
		nb = atoi(argv[3]);
		int found = findInt(nb, array, &length);
		if(found == 1)
			printf("value found\n");
		else
			printf("value not found\n");

		// count the number of times a int is in an array
		nb = atoi(argv[4]);
		unsigned int counter = nbCounter(nb, array, &length);
		printf("%u times\n", counter);

		// not forget to free
		deleteArrayInt(array);
	}
	else if (flag == 3)
	{
		float* array = (float*) calloc(10, sizeof(float));
		array = createArrayFloat();

		float nb = atof(argv[2]);
		initArrayFloat(nb, array);

		// not forget to free
		deleteArrayFloat(array);
	}

	return 0;
}