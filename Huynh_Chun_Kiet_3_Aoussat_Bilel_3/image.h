#ifndef IMAGE_H
#define IMAGE_H


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define min(a, b)	((a) < (b) ? (a) : (b))
#define max(a, b)	((a) < (b) ? (b) : (a))

typedef struct image{

	int 			largeur;
	int 			hauteur;
	int 			vmax;
	uint8_t * pixel_p;

} image_t;

//////////Gestions basiques de l'image////////////////
image_t *create_image(int l, int h, int v);
void destroy_image (image_t * im);
image_t * read_image (char * f_name);
FILE * write_image (image_t * im);


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
