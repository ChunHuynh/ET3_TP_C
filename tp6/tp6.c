#include <stdio.h>
#include "point.h"
#include "segment.h" 
#include "math.h"
#include <stdlib.h>

int main()
{
	/*
	point_t A;
	point_t B;
	
	point_affiche(&A);
	point_affiche(&B);
	
	double d = point_distance(&A,&B);
	printf("%f\n", d);
	
	int equal = point_egal(&A,&B);
	printf("%d\n",egal);
	
	point_translate(&A,2,3.1);
	point_affiche(&A);
	*/
	
	segment *seg1 = (segment*) malloc(2*sizeof(point_t));
	point_t *A1  = (point_t*) malloc(2*sizeof(double));
	point_t *B1  = (point_t*) malloc(2*sizeof(double));
	
	A1->x = 1;
	A1->y = 1;
	
	B1->x = 2;
	B1->y = 2;
	
	segment *seg2 = (segment*) malloc(2*sizeof(point_t));
	point_t *A2  = (point_t*) malloc(2*sizeof(double));
	point_t *B2  = (point_t*) malloc(2*sizeof(double));
	
	A2->x = 1;
	A2->y = 1;
	
	B2->x = 2;
	B2->y = 2;
	
	seg1 = segment_create(A1,B1);
	segment_affiche(seg1);
	
	seg2 = segment_create(A2,B2);
	segment_affiche(seg2);
	
	double d = segment_distance(seg1);
	
	printf("%f\n",d);
	
	int equal = segment_equal(seg1,seg2);
	printf("%d\n",equal);
	
	segment_delete(seg1);
	segment_delete(seg2);
	
	
	return 0;
}
