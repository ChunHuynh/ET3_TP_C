#include "image.h"


//////Creation Image//////////
image_t *create_image(int l, int h, int v)
{
  image_t * im  = (image_t*)malloc(sizeof(image_t));
  im->largeur   = l;
  im->hauteur   = h;
  im->vmax      = v;
  im->pixel_p   = (uint8_t*)malloc(h * l * sizeof(uint8_t));
    
  return im;
}


////////Destruction image///////////
void destroy_image(image_t * im)
{
  if (im)
  {
    free(im->pixel_p);
    free(im);
  }
}


//////////Lecture image//////////
image_t * read_image(char * f_name)
{
  FILE * fp = fopen(f_name, "r");

  /*vérification de l'existance du fichier*/
  if (!fp)
  {
    printf("ERROR: Fichier inexistant ! \n");
    return NULL;
  }


  char intro[3]; /*emplacement réservé à la vérification de l'en-tete*/
  fgets(intro,3,fp);

  char actual_char = 0; /*on initialise le curseur*/

  /*création des coordonnées de l'image*/
  char * largeur  = (char*) malloc(4*sizeof(char));
  char * hauteur  = (char*) malloc(4*sizeof(char));
  char * v        = (char*) malloc(4*sizeof(char));

  


  /*Vérification du format par comparaison avec la chaine "P2")*/
  if (intro[0] != 'P' || intro[1] != '2'|| (intro[2] != ' ' && intro[2] != '\t' && intro[2] != '\n' && intro[2] != '\0'))
  {
    printf("%s", intro);
    printf("ERROR: Fichier pas au fromat PGM !\n");
    return NULL;
  }

  while (actual_char == '\n' || actual_char == '\0' || actual_char == '\r' || actual_char == ' ')
  {
    actual_char = fgetc(fp);
  }

  /*vérification des commentaires*/
  if (actual_char == '#')
  {
    while(actual_char!='\n' && actual_char!='\0' && actual_char!='\r')
    {
      actual_char = fgetc(fp);
    }
  }

  //On relève les données de dimension de l'image, tout en faisant toujours attention aux commentaires, espaces, fins de lignes et potentielles erreurs
  char * n = fgets(largeur, 4, fp);

  while(actual_char=='\n' || actual_char=='\0' || actual_char=='\r' || actual_char == ' ')
  {
    actual_char = fgetc(fp);
  }

  ungetc(actual_char, fp);

  char * m = fgets(hauteur, 4, fp);

  //On recommence pour vmax
  while(actual_char=='\n' || actual_char=='\0' || actual_char=='\r' || actual_char == ' ')
  {
    actual_char = fgetc(fp);
  }

  char * p = fgets(v, 4, fp);

  image_t * image = create_image(atoi(n),atoi(m),atoi(p)); /*on crée l'image de sortie*/
  printf("%d\n", image->largeur);
  printf("%d\n", image->hauteur);
  printf("%d \n", image->vmax);
  

  //On passe un éventuel caractère, espacement, tabulation ou fin de ligne
  while(actual_char=='\n' || actual_char=='\0' || actual_char=='\r' || actual_char == ' ')
  {
    actual_char = fgetc(fp);
  }
  actual_char = fgetc(fp);
  printf("%c \n", actual_char);
  image->pixel_p[0] = (uint8_t)actual_char;

  /*code correct jusqu'à cette balise*/

  /*Transfert des données vers pixel_p*/
  unsigned int taille = image->largeur * image->hauteur;

  while(actual_char != EOF)
  {
    for(unsigned int i = 1; i < taille; i++)
    {
      if(actual_char == EOF)
        break;
      while(actual_char=='\n' || actual_char=='\0' || actual_char=='\r' || actual_char == ' ')
      {
        actual_char = fgetc(fp);
      }
      
      image->pixel_p[i] = (uint8_t)actual_char;
      actual_char = fgetc(fp);
    }

    printf("\n%s", image->pixel_p);
  }

  /*renvoi de l'image complète*/
  
  return image;
}


//////////Ecriture image//////////////
FILE* write_image (image_t * im)
{
    FILE* fp = NULL;
    fp = fopen("test.txt","w");

    //on commence par entrer les valeurs nécéssaires au format PGM
    fprintf(fp,"P2\n1%d %d\n%d\n",im->largeur,im->hauteur,im->vmax);

    //on rentre ensuite les valeurs des pixels au fur et à mesure
    for(int i=0; i< im->largeur ;i++)
    {
        for(int j=0; j< im->hauteur ;j++)
        {
            fprintf (fp, "%u", im->pixel_p[i*im->largeur+j]);
        }

        fprintf(fp,"\n");
    }

    /*Renvoi du fichier écrit "proprement"*/
    return fp;
}



////////// Contrast ////////
image_t * adapt_contrast_image(image_t * im, float k)
{
    for(unsigned int i = 0; i < im->largeur * im->hauteur; i++)
    {
        im->pixel_p[i] = max(min(k * im->pixel_p[i], im->vmax),0);
    }

    return im;
}



////////// Dilatation/Erosion //////////
image_t * grey_to_bw(image_t * im, unsigned int s)
{
    for (unsigned int i = 0; i < im->largeur * im->hauteur; i++)
    {
        if (im->pixel_p[i] <= s) //On compare la valeur du pixel à une valeur étalonnée, pour la passer soit tout en noir, soit tout en blanc
            im->pixel_p[i] = 0;
        else
            im->pixel_p[i] = im->vmax;
    }

    return im;
}

///////// Fonctions de comparaison entre 9 pixels d'un même carré 3x3 ///////////////////

unsigned int max_square(unsigned int a, unsigned int b, unsigned int c,
                        unsigned int d, unsigned int e, unsigned int f,
                        unsigned int g, unsigned int h, unsigned int i)
{
  return max(a, max(b, max(c, max(d, max(e, max(f, max(g, max(h, i))))))));
}


unsigned int min_square(unsigned int a, unsigned int b, unsigned int c,
                        unsigned int d, unsigned int e, unsigned int f,
                        unsigned int g, unsigned int h, unsigned int i)
{
  return min(a, min(b, min(c, min(d, min(e, min(f, min(g, min(h, i))))))));
}
