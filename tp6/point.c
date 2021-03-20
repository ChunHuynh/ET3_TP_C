#include "point.h"
#include <stdio.h>
#include "math.h"

void point_affiche(point_t const* p)
{
	printf("x = %f\ny = %f\n", p->x, p->y);
}

double point_distance(point_t const* p1, point_t const* p2)
{
	return sqrt(pow(p2->x - p1->x,2) + pow(p2->y - p1->y,2));
}

int point_equal(point_t const* p1, point_t const* p2)
{
	if(p1->x == p2->x && p1->y == p2->y) return 1;
	else return 0;
}

void point_translate(point_t* p, double dx, double dy)
{
	p->x += dx;
	p->y += dy;
}
