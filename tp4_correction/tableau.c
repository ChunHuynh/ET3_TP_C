#include <stdio.h>
#include <stdlib.h>

void afficherTableauInt(int *tab, int longueurTab) {
    int i;

    printf("[");
    for (i = 0; i < longueurTab; i++) {
        printf("%d, ", tab[i]);
    }
    printf("]\n");
}

void afficherTableauFloat(float *tab, int longueurTab) {
    int i;

    printf("[");
    for (i = 0; i < longueurTab; i++) {
        printf("%f, ", tab[i]);
    }
    printf("]\n");
}


void reinitialiserTableau(int *tab, int longueurTab, int valeur) {
    int i;

    for (i = 0; i < longueurTab; i++) {
        tab[i] = valeur;
    }
}


int chercherTableau(int *tab, int longueurTab, int valeur) {
    int i;

    for (i = 0; i < longueurTab; i++) {
        if (tab[i] == valeur){
            return 1;
        }
    }
    return 0;
}


int compterDansTableau(int *tab, int longueurTab, int valeur) {
    int i, compteur=0;

    for (i = 0; i < longueurTab; i++) {
        if (tab[i] == valeur){
            compteur++;
        }
    }
    return compteur;
}


int valeurAleatoire(int min, int max) {
    return rand() % (max - min + 1) + min;
}


int* creerTableauAleatoire(int longueurTab, int min, int max) {
    int *tab = malloc(longueurTab * sizeof(int));
    int i;

    for (i = 0; i < longueurTab; i++){
        tab[i] = valeurAleatoire(min, max);
    }
    return tab;
}


int* creerTableauTotalementAleatoire(int min, int max, int longueurMin, int longueurMax, int *ptrVersLongueur) {
    *ptrVersLongueur = valeurAleatoire(longueurMin, longueurMax);
	
    return creerTableauAleatoire(*ptrVersLongueur, min, max);
}


void swap(int* ptrSurA, int* ptrSurB) {
    int temp;
    temp = *ptrSurA;

    *ptrSurA = *ptrSurB;
    *ptrSurB = temp;
}

void triABulle(int *tab, int longueurTab) {
  int i, action = 1;

  while (action) {
    action = 0;
    for (i=0; i<longueurTab-1; i++) {

      /* Echange la valeur courante avec la suivante
         si elles ne sont pas dans le bon ordre */
      if (tab[i] > tab[i+1]){
        swap(tab+i, tab+i+1);
        action = 1;
        break;
      }
    }
  }
}


int* fusionTab(int *tab1, int longueur1, int *tab2, int longueur2) {
  int longueur3 = longueur1+longueur2;
  int *tab3 = malloc(longueur3 * sizeof(int));
  int i1 = 0, i2 = 0, i3;

  for (i3 = 0; i3 < longueur3; i3++) {
    if (i1 < longueur1 && i2 < longueur2 && tab1[i1] < tab2[i2]){
      tab3[i3] = tab1[i1];
      i1++;
    }
    else if (i2 < longueur2){
      tab3[i3] = tab2[i2];
      i2++;
    }
    else {
      tab3[i3] = tab1[i1];
      i1++;
    }
  }
  return tab3;
}


int* tirage_sans_remise(int nbTirages, int min, int max) {

  int i, indice, longueur = max - min;
  int *possibles = malloc((longueur + 1) * sizeof(int));
  int *resultat = malloc(nbTirages * sizeof(int));

  /* initialiser le tableau des valeurs possibles */
  for (i = 0; i < longueur + 1; i++) {
    possibles[i] = i + 1;
  }

  /* choisir un indice aleatoire du tableau "possibles"
     et prendre la valeur stockee a cette indice */
  for (i = 0; i < nbTirages; i++) {
    indice = valeurAleatoire(0, longueur + 1 - i);
    resultat[i] = possibles[indice];
    possibles[indice] = possibles[longueur - i];
  }

  free(possibles);

  return resultat;
}
