#include<stdio.h>
#include"affichage.h"

int main()
{
	/*
	int day = 4, month = 10, year = 2017;
	printf("Nous sommes le %d/%d/%d.\n", day, month, year);


	printf("     *     \n");
	printf("    ***    \n");
	printf("   *****   \n");
	printf("    ***    \n");
	printf("  *******  \n");
	printf("   *****   \n");
	printf(" ********* \n");	
	printf("***********\n");	
	printf("    |||    \n");
	printf("    |||    \n");	

	
	print_hello();
	
	int max = 10, i = 1;
	//afficher les multiples de 3 jusqu ’a la valeur de max
	while( i <= max ) 
	{
		print_my_value(i); // Appel a la fonction d’affichage ci-dessus
		i = i * 3;
	}
	

	age();

	flottant();

	motif();
	*/
	char player1[10], player2[10];

	enter_name(player1);
	enter_name(player2);		

	you_lived();	

	int moy = average();
	printf("moy = %d\n", moy);
	

	pay_motherfucker();
	
	return 0;
}
