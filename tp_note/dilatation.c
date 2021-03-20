#include "dilatation.h"

image_t * dilatation(image_t * im)
{
  for (unsigned int i = 0; i < im->largeur * im->hauteur; i++)
  {
    if (i < im->largeur)              					// i is on 1st line
  	{
    	dil_first_line(im, i);
  	}
  	else if (i % im->largeur == 0)    					// i is on 1st column
  	{
   		dil_first_column(im, i);
  	}
  	else if (i >= im->largeur*(im->hauteur-1))  // i is on last line
  	{
  	  dil_last_line(im, i);
  	}
  	else if (i % im->largeur == im->largeur-1)	// i is on last column
	  {
	    dil_last_column(im, i);
  	}
  	else
  	  dil(im, i);        
  }

	return im;
}


void dil_first_line(image_t * im, unsigned int n)
{
  if (n == 0)
  {
    im->pixel_p[n] = max_square(0,      0                    ,      0,
                                0, im->pixel_p[n]            , im->pixel_p[n+1],
                                0, im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
  }
  else if (n == im->largeur-1)
  {
    im->pixel_p[n] = max_square(0                           ,      0                    , 0,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , 0,
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], 0);
  }
  else
    im->pixel_p[n] = max_square(0                           ,      0                    , 0,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
}

void dil_last_line(image_t * im, unsigned int n)
{
  if (n == im->largeur * (im->hauteur-1))
  {
    im->pixel_p[n] = max_square(0, im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                0, im->pixel_p[n]            , im->pixel_p[n+1],
                                0,      0                    ,      0);
  }
  else if (n == (im->largeur * im->hauteur) -1)
  {
    im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], 0,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , 0,
                                0                           ,      0                    , 0);
  }
  else
    im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                                0                           ,      0                    , 0);
}

void dil_first_column(image_t * im, unsigned int n)
{
  if (n != 0 || n != im->largeur * (im->hauteur - 1))
  {
    im->pixel_p[n] = max_square(0, im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                0, im->pixel_p[n]            , im->pixel_p[n+1],
                                0, im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
  }
}

void dil_last_column(image_t * im, unsigned int n)
{
  if (n != im->largeur-1 || n != (im->largeur * im->hauteur)-1)
  {
    im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], 0,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , 0,
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], 0);
  }
}

void dil(image_t * im, unsigned int n)
{
  im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                              im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                              im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
}