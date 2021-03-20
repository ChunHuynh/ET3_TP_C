#include "point.h"
/************************************/
/**        Structure segment       **/
/************************************/
typedef struct segment{
	point_t begin, end;
}segment;

// segment_create
// Renvoie un pointeur vers un segment contenant les points passés en argument
segment* segment_create(point_t const* begin, point_t const* end);

// segment_delete
// Libère le segment
void segment_delete(segment* seg);

// segment_affiche
// Affiche les coordonnées d'un segment
void segment_affiche(segment const* p);

// segment_longueur
// Calcule la longueur du segment
double segment_longueur(segment const* seg);

// segment_equal
// Vérifie si les segments seg1 et seg2 ont les mêmes coordonnées et renvoie 0 si non n'importequoi si oui.
int segment_equal(segment const* seg1, segment const* seg2);

// segment_intersect
// Calcule l'intersection de deux segment s'il existe.
point_t* segment_intersect(segment const* seg1, segment const* seg2);
// renvoie 1 si valentre est bien entre les deux valeurs val1/val2
int entre_deux_val(double val1, double val2, double valentre);
