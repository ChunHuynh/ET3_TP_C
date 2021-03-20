#include "erosion.h"

//Ici, on compare le pixel central avec son voisinage, pour prendre la valeur minsimale du voisinage
//Attention aux pixels situés aux extrémités !
image_t * erosion(image_t * im)
{
  for (unsigned int i = 0; i < im->largeur * im->hauteur; i++)
  {
    if (i < im->largeur)                        // i is on 1st line
    {
      ero_first_line(im, i);
    }
    else if (i % im->largeur == 0)              // i is on 1st column
    {
      ero_first_column(im, i);
    }
    else if (i >= im->largeur*(im->hauteur-1))  // i is on last line
    {
      ero_last_line(im, i);
    }
    else if (i % im->largeur == im->largeur-1)  // i is on last column
    {
      ero_last_column(im, i);
    }
    else
     ero(im, i);
  }

  return im;
}

//On étudie le cas où on se trouve à l'extrémité haute du tableau

void ero_first_line(image_t * im, unsigned int n)
{
  if (n == 0)
  {
    im->pixel_p[n] = min_square(im->vmax, im->vmax                  , im->vmax,
                                im->vmax, im->pixel_p[n]            , im->pixel_p[n+1],
                                im->vmax, im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
  }
  else if (n == im->largeur-1)
  {
    im->pixel_p[n] = min_square(im->vmax                    , im->vmax                  , im->vmax,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->vmax,
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->vmax);
  }
  else
    im->pixel_p[n] = min_square(im->vmax                    , im->vmax                  , im->vmax,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
}

//On étudie le cas où on se trouve à l'extrémité basse du tableau

void ero_last_line(image_t * im, unsigned int n)
{
  if (n == im->largeur * (im->hauteur-1))
  {
    im->pixel_p[n] = min_square(im->vmax, im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                im->vmax, im->pixel_p[n]            , im->pixel_p[n+1],
                                im->vmax, im->vmax                  , im->vmax);
  }
  else if (n == (im->largeur * im->hauteur) -1)
  {
    im->pixel_p[n] = min_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->vmax,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->vmax,
                                im->vmax                    , im->vmax                  , im->vmax);
  }
  else
    im->pixel_p[n] = min_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                                im->vmax                    , im->vmax                  , im->vmax);
}

//On étudie le cas où on se trouve à l'extrémité gauche du tableau

void ero_first_column(image_t * im, unsigned int n)
{
  if (n != 0 || n != im->largeur * (im->hauteur - 1))
  {
    im->pixel_p[n] = min_square(im->vmax, im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                                im->vmax, im->pixel_p[n]            , im->pixel_p[n+1],
                                im->vmax, im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
  }
}

//On étudie le cas où on se trouve à l'extrémité droite du tableau

void ero_last_column(image_t * im, unsigned int n)
{
  if (n != im->largeur-1 || n != (im->largeur * im->hauteur)-1)
  {
    im->pixel_p[n] = min_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->vmax,
                                im->pixel_p[n-1]            , im->pixel_p[n]            , im->vmax,
                                im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->vmax);
    }
}



//Eroision sans cas particulier
void ero(image_t * im, unsigned int n)
{
  im->pixel_p[n] = min_square(im->pixel_p[n-im->largeur-1], im->pixel_p[n-im->largeur], im->pixel_p[n-im->largeur+1],
                              im->pixel_p[n-1]            , im->pixel_p[n]            , im->pixel_p[n+1],
                              im->pixel_p[n+im->largeur-1], im->pixel_p[n+im->largeur], im->pixel_p[n+im->largeur+1]);
}
