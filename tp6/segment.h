#ifndef SEGMENT_H
#define SEGMENT_H
#include "point.h"

typedef struct segement_t
{
	point_t *p1,*p2;
}segment;

segment* segment_create(point_t const* begin, point_t const* end);

void segment_delete(segment* seg);

void segment_affiche(segment const* seg);

double segment_distance(segment const* seg);

int segment_equal(segment const* seg1, segment const* seg2);

#endif
