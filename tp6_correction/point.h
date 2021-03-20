
/************************************/
/**         Structure point        **/
/************************************/
typedef struct point_t{
	double x, y;
}point_t;

// point_create
// Renvoie un pointeur vers un point contenant les valeurs passées en argument
point_t* point_create(double const x, double const y);

// point_delete
// Libère la place du point
void point_delete(point_t* p);

// point_affiche
// Affiche les coordonnées d'un point
void point_affiche(point_t const* p);

// point_distance
// Calcule la distance entre les deux points p1 et p2
double point_distance( point_t const*  p1,  point_t const* p2);

// point_equal
// Vérifie si les points p1 et p2 ont les mêmes coordonnées et renvoie 0 si non n'importequoi si oui.
int point_equal( point_t const* p1,  point_t const* p2);

// point_translate
// déplace le point p d'une distance dx et dy sur l'axe correspondant
void point_translate(point_t* p, double dx, double dy);

