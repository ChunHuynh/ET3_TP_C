#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>

int main()
{
	int nb = 123, mirroir;
	mirroir = mirror(nb);
	printf("Number : %i\nHis mirror : %i\n", nb, mirroir );

	printf("\n******** Convesion of seconds ********\n\n");
	convert(86400);

	printf("\n******** Max of a serie, ending by 0 ********\n\n");
	maximum();

	printf("\n******** Euclide division ********\n\n");
	euclide(46, 7);

	printf("\n******** Loto ********\n\n");
	srand(time(NULL));
	loto(6, 1, 49);

	return 0;
}