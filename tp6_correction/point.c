#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "point.h"

/************************************/
/**          point_create          **/
/************************************/
point_t* point_create(double const abscisses, double const ordonnees){
	point_t* p = (point_t*) malloc(sizeof(point_t));
	p->x = abscisses;
	p->y = ordonnees;
	return p;
}

/************************************/
/**          point_delete          **/
/************************************/
void point_delete(point_t* p){
    free(p);
}

/************************************/
/**         point_affiche          **/
/************************************/
void point_affiche(point_t const *  p){
    printf("Point {%.2f, %.2f}\n", p->x, p->y);
}

/************************************/
/**         point_distance         **/
/************************************/
double point_distance(point_t const*  p1,  point_t const*  p2){
    double dx = (p1->x - p2->x);
    double dy = (p1->y - p2->y);
    double distance = sqrt(dx*dx + dy*dy);
    return distance;
}

/************************************/
/**          point_equal          **/
/************************************/
int point_equal(point_t const*  p1, point_t const*  p2){
    int is_equal = 0;

    if((p1->x == p2->x)&& (p1->y == p2->y)){
        is_equal = 1;

    }
    return is_equal;
}


/************************************/
/**          point_translate          **/
/************************************/
void point_translate(point_t* p, double dx, double dy){
    p->x += dx;
    p->y += dy;
}
