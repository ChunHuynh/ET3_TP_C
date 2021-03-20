
/* Afficher un tableau d'entiers */
void afficherTableauInt(int *tab, int longueurTab);

/* Afficher un tableau de nombres flottants */
void afficherTableauFloat(float *tab, int longueurTab);

/* (Ré)-initialiser toutes les cases d'un tableau d'entiers avec une
   valeur donnée */  
void reinitialiserTableau(int *tab, int longueurTab, int valeur);

  
/* Chercher une valeur dans un tableau d'entiers. Renvoyer 1 si elle
   est trouvée, 0 sinon */  
int chercherTableau(int *tab, int longueurTab, int valeur);

  
/* Compter le nombre d'occurrences d'une valeur entière donnée dans un
   tableau d'entiers. Renvoyer ce nombre d'occurrences. */  
int compterDansTableau(int *tab, int longueurTab, int valeur);

  
/* Générer un entier aléatoire entre une valeur minimale et maximale
   (valeur maximale comprise) */  
int valeurAleatoire(int min, int max);


/* Créer un tableau d'entiers aléatoires dont les valeurs seront
   comprises entre les valeurs minimales et maximales fournies */  
int* creerTableauAleatoire(int longueurTab, int min, int max);


/* Créer un tableau d'entiers aléatoires dont les valeurs seront
   comprises entre les valeurs minimales et maximales fournies et la
   longueur du tableau sera aussi générée aléatoirement entre une
   longueur minimum de longueurMin et une longueur maximum de longueurMax */
int* creerTableauTotalementAleatoire(int min, int max, int longueurMin, int longueurMax, int *ptrVersLongueur);

/* Tri à bulles */
void triABulle(int *tab, int longueurTab);

/* Permuter deux valeurs */
void swap(int* ptrSurA, int* ptrSurB);


/* Fusion de tableaux triés */
int* fusionTab(int *tab1, int longueur1, int *tab2, int longueur2);

/* Tirage sans remise */
int* tirage_sans_remise(int nbTirages, int min, int max);
