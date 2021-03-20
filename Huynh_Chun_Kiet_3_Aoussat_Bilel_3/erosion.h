#ifndef EROSION_H
#define EROSION_H

#include "image.h"

//Documentation des différents fonctions de dilatation

image_t * erosion(image_t * im);

void ero_first_line(image_t * im, unsigned int n);

void ero_last_line(image_t * im, unsigned int n);

void ero_first_column(image_t * im, unsigned int n);

void ero_last_column(image_t * im, unsigned int n);

void ero(image_t * im, unsigned int n);

#endif
