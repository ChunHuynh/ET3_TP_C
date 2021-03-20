#ifndef HISTOGRAMME_H
#define HISTOGRAMME_H

#include "image.h"

//Documentation sur l'histogramme


typedef struct histogramme{

	unsigned int * val;

}	histogramme_t;

histogramme_t * create_histogram(image_t * im);

void delete_histogram(histogramme_t * hist);

histogramme_t * histogram_image(image_t * im);

void write_histogram(histogramme_t * hist); /* TODO */


#endif
