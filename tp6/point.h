#ifndef POINT_H
#define POINT_H

typedef struct point_t
{
	double x,y;
}point_t;

void point_affiche(point_t const* p);

double point_distance(point_t const* p1, point_t const* p2);

int point_equal(point_t const* p1, point_t const* p2);

void point_translate(point_t* p, double dx, double dy);

#endif
