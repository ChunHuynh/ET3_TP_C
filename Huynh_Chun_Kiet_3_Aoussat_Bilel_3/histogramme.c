#include "histogramme.h"

//création de l'histogramme

histogramme_t * create_histogram(image_t * im){
	histogramme_t * hist = (histogramme_t*) malloc(sizeof(histogramme_t));
	hist->val = (unsigned int*) calloc(im->vmax, sizeof(unsigned int));

	return hist;
}

//Suppression de l'histogramme

void delete_histogram(histogramme_t * hist){
	if (hist)
	{
		free(hist->val);
		free(hist);
	}
}

//Remplissage de l'histogramme en fonction des valeurs de pixels de l'image étudiée

histogramme_t * histogram_image(image_t * im){
	histogramme_t * hist = create_histogram(im);

	for (unsigned int i = 0; i < im->largeur * im->hauteur; i++)//On parcourt l'image
	{
		hist->val[im->pixel_p[i]]++; // pour ensuite augmenter de un l'incrémentation de la case correspondant à la valeur du pixel parcouru

	}

	return hist;
}


void write_histogram(histogramme_t * hist)
{
    //Inachevé
    /**/
        //Remplissage de l'histogramme ( 256 colonnes, une par valeur de pixel)
        //Ajustement du plafond de valeurs en fonction de la colonne pixel la plus remplie
        //affichage de l'histogramme
    /**/
}
