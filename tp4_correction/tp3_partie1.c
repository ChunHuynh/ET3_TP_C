#include "tableau.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void tester_exos_1();
void tester_exos_2();
void tester_exos_3();
void tester_exos_4();
void tester_exos_5();


int main() {

  /* N.B. Initialiser srand pour l'utilisation de rand() ! */
  srand(time(NULL));
  
  tester_exos_1();
  tester_exos_2();
  tester_exos_3();
  tester_exos_4();
  tester_exos_5();
  
  return 0;
}


/* Tester les exos de la section 1 */
void tester_exos_1() {

  int tab1[5] = {1, 4, 6, 3, 5};
  int tab2[] = {};
  int tab3[3] = {1, 3, 8};
  float tab4[4] = {2., 5.4, 3.2, 1.2};

  /* 1) Affichage */
  afficherTableauInt(tab1, 5);
  afficherTableauInt(tab2, 0);
  afficherTableauFloat(tab4, 4);

  /* 2) Reinitialisation de valeurs (exemple donné pour un tableau de
	 ints) */
  reinitialiserTableau(tab1, 5, 23);
  afficherTableauInt(tab1, 5);

  /* 3) Chercher une valeur dans un tableau */

  /* valeur non trouvable */
  if (chercherTableau(tab3, 3, 2)) {
	printf("Valeur trouvée!\n");
  }
  else {
	printf("Valeur non trouvée!\n");
  }

  /* valeur trouvable */
  if (chercherTableau(tab3, 3, 8)) {
	printf("Valeur trouvée!\n");
  }
  else {
	printf("Valeur non trouvée!\n");
  }
  
  /* 4) Compter le nombre d'occurrences d'une valeur */
  int nbr = compterDansTableau(tab1, 5, 23);
  printf("La valeur 23 apparaît %d fois\n", nbr);

  /* 5) Génération d'un tableau aléatoire */
  
  int *tabAleatoire = creerTableauAleatoire(6, 1, 10);
  afficherTableauInt(tabAleatoire, 6);
  free(tabAleatoire);

  /* 6) Génération d'un tableau totalement aléatoire */
  int longueur;
  int *tabTotAleatoire = creerTableauTotalementAleatoire(1, 100, 6, 10, &longueur);
  afficherTableauInt(tabTotAleatoire, longueur);
  free(tabTotAleatoire);

}


/* Tester les exos de la section 2 */
void tester_exos_2() {
    int a = 5, b = 10;
    swap(&a, &b);
    printf("a = %d, b = %d\n", a, b);
}


/* Tester les exos de la section 3 */
void tester_exos_3() {
  int *tab1 = creerTableauAleatoire(6, 1, 10);
  triABulle(tab1, 6);
  afficherTableauInt(tab1, 6);
  free(tab1);

  int tab2[] = {};
  triABulle(tab2, 0);
  afficherTableauInt(tab2, 0);

  int tab3[] = {2, 2, 2};
  triABulle(tab3, 3);
  afficherTableauInt(tab3, 3);
  
}

/* Tester les exos de la section 4 */
void tester_exos_4() {

  printf("Avant le tri\n");
  int longueur1;
  int *tab1 = creerTableauTotalementAleatoire(1, 100, 6, 10, &longueur1);
  afficherTableauInt(tab1, longueur1);

  int longueur2;
  int *tab2 = creerTableauTotalementAleatoire(1, 100, 6, 10, &longueur2);
  afficherTableauInt(tab2, longueur2);

  printf("Chaque tableau est trié\n");
  triABulle(tab1, longueur1);
  triABulle(tab2, longueur2);
  afficherTableauInt(tab1, longueur1);
  afficherTableauInt(tab2, longueur2);

  printf("La fusion des deux tableaux\n");
  int *tab3 = fusionTab(tab1, longueur1, tab2, longueur2);
  afficherTableauInt(tab3, longueur1 + longueur2);  

}


/* Tester les exos de la section 5 */
void tester_exos_5() {

  printf("Tirage sans remise (6 tirages dans [1, 49]) \n");
  int* resultat = tirage_sans_remise(6, 1, 49);
  afficherTableauInt(resultat, 6);

}



