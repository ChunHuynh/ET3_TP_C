#ifndef IMAGE_H
#define IMAGE_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) < (b) ? (b) : (a))

typedef struct image{

	int largeur;
	int hauteur;
	unsigned int vmax;
	unsigned short int * pixel_p;

} image_t;


image_t *create_image(int l, int h);
void destroy_image (image_t * im);
image_t * read_image ();


//////// Contrast ////////
image_t * adapt_contrast_image(image_t * im, float k);


//////// Dilatation/Erosion ////////
image_t * grey_to_bw(image_t * im, unsigned int s);

unsigned int max_square(unsigned int a, unsigned int b, unsigned int c,
					    unsigned int d, unsigned int e, unsigned int f,
					    unsigned int g, unsigned int h, unsigned int i);

unsigned int min_square(unsigned int a, unsigned int b, unsigned int c,
					    unsigned int d, unsigned int e, unsigned int f,
					    unsigned int g, unsigned int h, unsigned int i);

#endif