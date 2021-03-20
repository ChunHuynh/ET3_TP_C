#include <stdio.h>
#include "segment.h"
#include <stdlib.h>

segment* segment_create(point_t const* begin, point_t const* end)
{
	point_t *pA  = (point_t*) malloc(2*sizeof(double));
	point_t *pB  = (point_t*) malloc(2*sizeof(double));
	segment *seg = (segment*) malloc(2*sizeof(point_t));
	
	pA->x = begin->x;
	pA->y = begin->y;
	pB->x = end->x;
	pB->y = end->y;
	
	seg->p1 = pA;
	seg->p2 = pB; 
	
	return seg;
}

void segment_delete(segment* seg)
{
	if(seg) free(seg);
	seg = NULL;
}

void segment_affiche(segment const* seg)
{
	point_affiche(seg->p1);
	point_affiche(seg->p2);
}

double segment_distance(segment const* seg)
{
	return point_distance(seg->p1,seg->p2);
}

int segment_equal(segment const* seg1, segment const* seg2)
{
	int e1 = point_equal(seg1->p1,seg2->p1);
	int e2 = point_equal(seg1->p2,seg2->p2);
	if(e1 == 1 && e2 == 1) return 1;
	else return 0;
}
