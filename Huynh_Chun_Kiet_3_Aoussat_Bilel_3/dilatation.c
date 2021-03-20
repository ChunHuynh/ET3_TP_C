#include "dilatation.h"


//Ici, on compare le pixel central avec son voisinage, pour prendre la valeur maximale du voisinage
//Attention aux pixels situ�s aux extr�mit�s !
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

//On �tudie le cas o� on se trouve � l'extr�mit� haute du tableau

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


//On �tudie le cas o� on se trouve � l'extr�mit� basse du tableau

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

//On �tudie le cas o� on se trouve � l'extr�mit� gauche du tableau

void dil_first_column(image_t * im, unsigned int n)
{
  if (n != 0 || n != im->largeur * (im->hauteur - 1))
  {
    im->pixel_p[n] = max_square(0, im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                0, im->pixel_p[n]            , im->pixel_p[n+1],
                                0, im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
  }
}

//On �tudie le cas o� on se trouve � l'extr�mit� droite du tableau

void dil_last_column(image_t * im, unsigned int n)
{
  if (n != im->largeur-1 || n != (im->largeur * im->hauteur)-1)
  {
    im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], 0,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , 0,
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], 0);
  }
}

//dilatation sans cas particulier
void dil(image_t * im, unsigned int n)
{
  im->pixel_p[n] = max_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                              im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                              im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
}
