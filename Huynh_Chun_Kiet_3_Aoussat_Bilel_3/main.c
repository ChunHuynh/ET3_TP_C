#include "image.h"   //.h en console linux
#include "dilatation.h"
#include "erosion.h"
#include "histogramme.h"


int main(int argc, char ** argv)
{

	printf("Nombre d'arguments : %d\n", argc);

	for (int i = 0; i < argc ; i++)
	{
		printf (" Argument %d: %s\n", i, argv [i]) ;
	}

	


	/*Tests*/
	/*
 	image_t * image;
 	FILE * file = NULL;

 	//image = read_image("Wrong_magic_numberA8.pgm");
  //image = read_image("baboon.pgm");
  //image = read_image("baboon-commentairemilieu.pgm");
 	image = read_image("FEEP.pgm");

 	file = write_image(image);

 	//////// contrast ////////
	image_t * im = (image_t*) malloc(sizeof(image_t));
	image_t * im_contrast = (image_t*) malloc(sizeof(image_t));

	im = read_image(argv[1]); 														 	// argv[1] is fileName
	im_contrast = adapt_contrast_image(im, atof(argv[2]));	// argv[2] is k

	file = write_image(image);
	//////////////////////////

	/////// erosion //////////
	image = grey_to_bw(image, 10);
  image = erosion(image);
  file = write_image(image);
  //////////////////////////

  /////// dilatation ///////
  image = grey_to_bw(image, 10);
  image = dilatation(image);
  file = write_image(image);
  //////////////////////////

  destroy_image(im);
  destroy_image(im_contrast);
  destroy_image(image);
  */

	return 0;
}
