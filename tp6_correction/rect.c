#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "rect.h"

/************************************/
/**           rect_create          **/
/************************************/
// Attention à l'invariant qui justifie le create :
// il faut vérifier que les 4 points sont bien dans l'ordre !
rect* rect_create(point_t const* p1, point_t const* p2, point_t const* p3, point_t const* p4){
    rect* rectangle = (rect*) malloc(sizeof(rect));
    // On doit enlever les cas où au moins 2 sont les mêmes points.
    if(!point_equal(p1, p2) && !point_equal(p1, p3) &&
       !point_equal(p1, p4) && !point_equal(p2, p3) &&
       !point_equal(p2, p4) && !point_equal(p3, p4)){
        //Nous allons maintenant, partant du principe que les points sont donnés dans un ordre (Aiguille d'une montre),
        // vérifier qu'il y a bien 3 angles droits pour valider que c'est un rectangle. (Cad que les valeur du cosinus sont bien = 0)
        if(produit_scalaire(p1, p2, p3) == 0 && produit_scalaire(p2, p3, p4) == 0
           && produit_scalaire(p3, p4, p1) == 0){

            rectangle->point1 = *p1;
            rectangle->point2 = *p2;
            rectangle->point3 = *p3;
            rectangle->point4 = *p4;
        }else{
            rectangle= NULL;
            printf("Ce n'est pas un rectangle !!\n ");
        }
    }
    return rectangle;
}

// Renvoie la valeur du cosinus de l'angle AOB
double produit_scalaire(point_t const* A, point_t const* O, point_t const* B){
    double resultat = 0;

    //Calcul des vecteurs OA et OB
    double xOA = A->x - O->x;
    double xOB = B->x - O->x;
    double yOA = A->y - O->y;
    double yOB = B->y - O->y;
    // On sait que vec(OA).vec(OB) = xOA.xOB + yOA.yOB
    // et que vec(OA).vec(OB) = |OA|.|OB|.cos(theta)
    // d'où on peut déduire cos(theta).
    // si = 0 c'est que théta = 90 et donc c'est un angle droit !
    resultat = point_distance(O, A)*point_distance(O, B);
    if(resultat != 0){
        resultat = (xOA * xOB + yOA * yOB)/resultat;
    }
    return resultat;
}

/************************************/
/**           rect_delete          **/
/************************************/
void rect_delete(rect* rectangle){
    free(rectangle);
}

/************************************/
/**           rect_affiche         **/
/************************************/
void rect_affiche(rect const* rectangle){
    if(rectangle != NULL){
        printf("\n Rectangle\n");
        printf("Point 1 : {%.2f, %.2f}\n", rectangle->point1.x, rectangle->point1.y);
        printf("Point 2 : {%.2f, %.2f}\n", rectangle->point2.x, rectangle->point2.y);
        printf("Point 3 : {%.2f, %.2f}\n", rectangle->point3.x, rectangle->point3.y);
        printf("Point 4 : {%.2f, %.2f}\n", rectangle->point4.x, rectangle->point4.y);
        printf("\n");
    }else{
        printf("Ce n'est pas un rectangle. \n");
    }
}

/************************************/
/**           rect_equal           **/
/************************************/
int rect_equal(rect const* rectangle1, rect const * rectangle2){
    int resultat = point_equal(&(rectangle1->point1), &(rectangle2->point1)) || point_equal(&(rectangle1->point1), &(rectangle2->point2)) || point_equal(&(rectangle1->point1), &(rectangle2->point3)) || point_equal(&(rectangle1->point1), &(rectangle2->point4));
    resultat = resultat && (point_equal(&(rectangle1->point2), &(rectangle2->point1)) || point_equal(&(rectangle1->point2), &(rectangle2->point2)) || point_equal(&(rectangle1->point2), &(rectangle2->point3)) || point_equal(&(rectangle1->point2), &(rectangle2->point4)));
    resultat = resultat && (point_equal(&(rectangle1->point3), &(rectangle2->point1)) || point_equal(&(rectangle1->point3), &(rectangle2->point2)) || point_equal(&(rectangle1->point3), &(rectangle2->point3)) || point_equal(&(rectangle1->point3), &(rectangle2->point4)));
    resultat = resultat && (point_equal(&(rectangle1->point4), &(rectangle2->point1)) || point_equal(&(rectangle1->point4), &(rectangle2->point2)) || point_equal(&(rectangle1->point4), &(rectangle2->point3)) || point_equal(&(rectangle1->point4), &(rectangle2->point4)));
    return resultat;
}

/************************************/
/**          rect_surface          **/
/************************************/
double rect_surface(rect const* rectangle){
    double surface = point_distance(&(rectangle->point1), &(rectangle->point2)) * point_distance(&(rectangle->point2), &(rectangle->point3));
    return surface;
}

/************************************/
/**         rect_contains          **/
/************************************/
int rect_contains(rect const* rectangle, point_t const* point){
    // point est dans rectangle si et seulement si le cosinus de l'angle du produit scalaire est bien compris entre o et 1 inclus)
    int resultat = entre_deux_val(0,1,produit_scalaire(point, &(rectangle->point1), &(rectangle->point2)));
    resultat = resultat && entre_deux_val(0,1,produit_scalaire(point, &(rectangle->point2), &(rectangle->point3)));
    resultat = resultat && entre_deux_val(0,1,produit_scalaire(point, &(rectangle->point3), &(rectangle->point4)));
    resultat = resultat && entre_deux_val(0,1,produit_scalaire(point, &(rectangle->point4), &(rectangle->point1)));
    return resultat;
}

/************************************/
/**         rect_disjoint          **/
/************************************/
int rect_disjoint(rect const* rectangle1, rect const* rectangle2){
    //Il suffit de vérifier qu'il n'y a pas de sommet de l'un des triangles dans l'autre, mais aussi inversement ! (Cf cas du rectabgle complétement inclu)
    int resultat = 1;
    if(rect_equal(rectangle1, rectangle2)){
        resultat = rect_contains(rectangle2, &(rectangle1->point1)) || rect_contains(rectangle2, &(rectangle1->point2)) || rect_contains(rectangle2, &(rectangle1->point3)) || rect_contains(rectangle2, &(rectangle1->point4));
        resultat = rect_contains(rectangle1, &(rectangle2->point1)) || rect_contains(rectangle1, &(rectangle2->point2)) || rect_contains(rectangle1, &(rectangle2->point3))|| rect_contains(rectangle1, &(rectangle2->point4));
    }
    return !resultat;
}
