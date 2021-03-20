#include <stdio.h>
#include "functions.h"
#include <stdlib.h>
#include <time.h>

//////// Ex1 ////////
int mirror(int nb)
{
	int mirroir = 0;

	while(nb != 0)
	{
		mirroir *= 10;
		mirroir += nb % 10;
		nb /= 10;
	}

	return mirroir;
}

//////// Ex2 ////////
void convert(int sec)
{
	printf("%d seconds = ", sec);
	int day = sec / 86400;
	sec %= 86400;

	int hour = sec / 3600;
	sec %= 3600;

	int min = sec / 60;
	sec %= 60;

	printf("%dd %dh %dmin %dsec.\n", day, hour, min, sec);
}

//////// Ex3 ////////
void maximum()
{
	int n = 0, max = 0, number = 0, i = 0;

	do{

		i++;

		printf("Enter number %d : ", i);
		scanf("%d", &number);

		if(number > max)
		{
			max = number;
			n = i;
		}

	}while(number != 0);
	printf("Highest number : %d. Position : %d\n", max, n ); 
}

//////// Ex4 ////////
void euclide(int a, int b)
{
	int multi = 1, reste;

	while(b * multi <= a - b)
	{
		multi++;
	}
	reste = a - (b * multi);

 	printf("%d = %d * %d + %d.\n", a, b, multi, reste);
}

//////// Ex5 ////////
int random(int min, int max)
{
	return (rand() % (max - min +1)) + min;
}


void loto(int n, int min, int max)
{
	for(int i = 0; i < n; i++)
	{
		printf("Value number %d : %d\n", i + 1, random(min, max));
	}
}