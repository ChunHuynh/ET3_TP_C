#include "segment.h"
/************************************/
/**         Structure Rect         **/
/************************************/
typedef struct rect{
	point_t point1, point2, point3, point4;
}rect;

// rect_create
// Renvoie un pointeur vers un quadrilatere contenant les points passés en argument
rect* rect_create(point_t const* p1, point_t const* p2, point_t const* p3, point_t const* p4);
// Vérifie s'il y a un angle droit
double produit_scalaire(point_t const* A, point_t const* O, point_t const* B);

// rect_delete
// Libère la place
void rect_delete(rect* rectangle);

// rect_affiche
// Affiche les informations du rectangle
void rect_affiche(rect const*  rectangle);

// rect_equal
// Renvoie 1 si les deux rectangles sont égaux
int rect_equal(rect const* rectangle1, rect const* rectangle2);

// rect_surface
// Calcule la surface
double rect_surface(rect const* rectangle);

// rect_contains
// Vérifie si le point est dans le quadrilatère, renovie 1 si c'est le cas, sinon
int rect_contains(rect const* rectangle, point_t const* point);

// int rect_disjoint
// Vérifie si deux rectangles sont bien disjoints et renvoie 1 si c'est le cas, 0 sinon
int rect_disjoint(rect const* rectangle1, rect const* rectangle2);
