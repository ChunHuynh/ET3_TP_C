//#include "point.h"
//#include "segment.h"
#include "rect.h"
#include <stdio.h>
#include <stdlib.h>

int main() {

    /*****************/
    /**    Point    **/
    /*****************/
    // Différentes façons d'allouer un point
    point_t q = {1.65, 3.89};
    point_t* p = point_create(10, 10);
    point_affiche(p);
    point_affiche(&q);

    // Distance
    double distance = point_distance(&q, p);
    printf("Distance p-q : %.2f\n", distance);

    // Eual
    int is_equal = point_equal(&q, p);
    printf("Is equal p/q : %d\n", is_equal);

    // Translate
    double dx = 10, dy = 10;
    printf("Translate avant : point p {%.2f, %.2f} d\'eplac\'e de %.2f en x, %0.2f en y\n", q.x, q.y, dx, dy);
    point_translate(&q, dx, dy);
    printf("Translate après : %.2f, %.2f\n", q.x, q.y);

    /*****************/
    /**   segment   **/
    /*****************/
    //Create
    point_t begin1 = {1.65, 3.89};
    point_t end1 = {10.5, 7.21};
    point_t* begin2 = point_create(3.25, 2.31);
    point_t* end2 = point_create(5.67, 9.84);
    segment seg1 = {begin1, end1};
    segment* seg2 = segment_create(begin2, end2);

    // Affiche
    segment_affiche(&seg1);
    segment_affiche(seg2);

    //Longueur
    double longueur = segment_longueur(&seg1);
    printf("Longueur seg1 : %.2f\n", longueur);
    longueur = segment_longueur(seg2);
    printf("Longueur seg2 : %.2f\n", longueur);

    //Equal
    is_equal = segment_equal(seg2, seg2);
    printf("Is_Equal seg2/seg2 : %d\n", is_equal);
    is_equal = segment_equal(&seg1, seg2);
    printf("Is_Equal seg1/seg2 : %d\n", is_equal);

    // Intersect
    point_t* begin4 = point_create(2,2);
    point_t* end4 = point_create(4,4);
    point_t* begin5 = point_create(2,2);
    point_t* end5 = point_create(2,4);
    segment* seg4 = segment_create(begin4, end4);
    segment* seg5 = segment_create(begin5, end5);
    point_t* intersect = (point_t*) malloc(sizeof(point_t));
    intersect = segment_intersect(seg4, seg5);

    if(intersect != NULL){
        printf("\n L'intersection des deux segments est : \n");
        point_affiche(intersect);
    }else{
        printf("Il n'y a pas d'intersection entre les deux segments");
    }

    /******************/
    /**     Rect     **/
    /******************/
    // Create
    // Rect 1
    point_t* p1 = point_create(2,2);
    point_t* p2 = point_create(4,4);
    point_t* p3 = point_create(5,3);
    point_t* p4 = point_create(3,1);
    rect* rectangle = rect_create(p1, p2, p3, p4);
    // Rect 2
    point_t* p5 = point_create(1,1);
    point_t* p6 = point_create(1,3);
    point_t* p7 = point_create(3,3);
    point_t* p8 = point_create(3,1);
    rect* rectangle2 = rect_create(p5, p6, p7, p8);
    // Rect 3
    point_t* p9 = point_create(4,1);
    rect* rectangle3 = rect_create(p5, p6, p7, p9);
    // Affiche
    rect_affiche(rectangle);
    rect_affiche(rectangle2);
    rect_affiche(rectangle3);

    // Equal
    is_equal = rect_equal(rectangle, rectangle2);
    printf("\nrect1 et 2 are Equal = %d\n", is_equal);
    is_equal = rect_equal(rectangle, rectangle);
    printf("rect1 et 1 are Equal = %d\n", is_equal);

    // Surface
    double surface = rect_surface(rectangle);
    printf("\nSurface 1 = %.2f\n", surface);
    surface = rect_surface(rectangle2);
    printf("Surface 2 = %.2f\n", surface);

    // Contains
    int contains = rect_contains(rectangle, p9);
    printf("\nRect 1 contient {4,1} = %d\n", contains);
    contains = rect_contains(rectangle2, p7);
    printf("Rect 2 contient {3,3} = %d\n", contains);

    // Disjoints
    int disjoint = rect_disjoint(rectangle, rectangle2);
    printf("\nRect 1 disjoint rect 2 = %d\n", disjoint);

    // Seule les versions allouée nécessitent un free
    point_delete(p);
    point_delete(p1);
    point_delete(p2);
    point_delete(p3);
    point_delete(p4);
    point_delete(p5);
    point_delete(p6);
    point_delete(p7);
    point_delete(p8);
    point_delete(p9);
    segment_delete(seg2);
    rect_delete(rectangle);
    rect_delete(rectangle2);
    rect_delete(rectangle3);
    return 0;
}
