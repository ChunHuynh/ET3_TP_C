#include<stdio.h>
	
void print_hello()
{
	printf("Hello\n");
}

void print_my_value( int value ) 
{
	printf("Valeur suivante = %d\n", value);
} 

void age()
{
	int age, year, nextYear;	
	printf("Entrez votre age :\n");
	scanf("%d", &age);
	year 	 = 2017 - age;
	nextYear = year - 1;
	printf("Vous avez %d ans. Vous etes donc né(e) en %d ou %d.\n",age, year, nextYear);
}

void flottant()
{
	float virgule;
	printf("Entrez un nombre à virgule :\n");
	scanf("%f", &virgule);
	printf("%f\n", virgule);
	printf("%.5f\n", virgule);
	printf("%7.2f\n", virgule);
}

void motif()
{
	int x = 1;
	printf("%d\n", x);
	printf("%02d\n", x);
	printf("%03d\n", x);
	printf("%04d\n", x);	
}

void enter_name(char player[])
{
	printf("Entrez votre nom : \n");
	scanf("%s", player);
	printf("Hello, %s.\n", player);
}

void you_lived()
{
    	float age;
   	printf("Entrez votre age : \n");
    	scanf("%f", &age);
    	printf("Felicitations, vous avez vecu au moins %f ans\n", age);
}

int average()
{
	int x_0 = 3, x_1 = 5, x_2 = 9, x_3 = 1;
	return (x_0+x_1+x_2+x_3)/4;
}

void pay_motherfucker()
{
	int prix, prix_1, prix_2, prix_3, total, encaisse, rendu;
	printf("Veuillez entrer le prix de l'achat 1 :\n");
	scanf("%d", &prix);
	printf("Veuillez entrer le prix de l'achat 2 :\n");
	scanf("%d", &prix_1);
	printf("Veuillez entrer le prix de l'achat 3 :\n");
	scanf("%d", &prix_2);
	printf("Veuillez entrer le prix de l'achat 4 :\n");
	scanf("%d", &prix_3);
	
	total = prix + prix_1 + prix_2 + prix_3;
	printf("Le prix total est : %d\n", total);
	
	printf("Combien voulez-vous donner ? :\n");
	scanf("%d", &encaisse);
	
	while( encaisse < total )
	{
		printf("N'essayez pas de me gruger, bonobo des montagnes ! \n");
		scanf("%d", &encaisse);
	}
	
	rendu = encaisse - total;				
	printf("Malheureusement je dois vous rendre %d euro(s)\n", rendu);	
	
	int dix = 0, cinq = 0, deux = 0;
	
	if(rendu == 0){}
	else
	{
		dix = rendu / 10;
		rendu %= 10;			
		if(dix > 0){printf("%d billet(s) de 10 euros,",dix);}

		cinq = rendu / 5;
		rendu %= 5;
		if(cinq > 0){printf("%d billet de 5 euros,",cinq);}

		deux = rendu / 2;
		rendu %= 2;
		if(deux > 0){printf("%d piece(s) de 2 euros,",deux);}
		

		if(rendu >0){printf("%d piece de 1 euro,",rendu);}
	}
		
}









