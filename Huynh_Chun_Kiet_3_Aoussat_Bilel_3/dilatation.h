#ifndef DILATATION_H
#define DILATATION_H

#include "image.h"

//Documentation des différents fonctions de dilatation

image_t * dilatation(image_t * im);

void dil_first_line(image_t * im, unsigned int n);

void dil_last_line(image_t * im, unsigned int n);

void dil_first_column(image_t * im, unsigned int n);

void dil_last_column(image_t * im, unsigned int n);

void dil(image_t * im, unsigned int n);

#endif
