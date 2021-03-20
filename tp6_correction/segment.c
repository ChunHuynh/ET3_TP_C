#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "segment.h"

/************************************/
/**         segment_create         **/
/************************************/
segment* segment_create(point_t const* begin, point_t const* end){
	segment* seg = (segment*) malloc(sizeof(segment));
	seg->begin = *begin;
	seg->end = *end;
	return seg;
}

/************************************/
/**         segment_delete         **/
/************************************/
void segment_delete(segment* seg) {
    free(seg);
}

/************************************/
/**        segment_affiche         **/
/************************************/
void segment_affiche(segment const *  seg) {
    printf("\nSegment\n");
    point_affiche(&(seg->begin));
    point_affiche(&(seg->end));
}

/************************************/
/**        segment_longueur        **/
/************************************/
double segment_longueur(segment const* seg){
    double distance = point_distance(&(seg->begin), &(seg->end));
    return distance;
}

/************************************/
/**         segment_equal          **/
/************************************/
int segment_equal(segment const* seg1, segment const* seg2){
    int is_equal = 0;

    if(point_equal(&(seg1->begin), &(seg2->begin))
       && point_equal(&(seg1->end), &(seg2->end))){
        is_equal = 1;
    }
    return is_equal;
}

/************************************/
/**       segment_intersect        **/
/************************************/
point_t* segment_intersect(segment const* seg1, segment const* seg2){
    point_t* intersect = NULL;
    // Si les dorites ne sont pas égales
    if(segment_equal(seg1, seg2) == 0){
        // Calcule des équations des droites
        // Pour seg 1 :
        // on a y = a1x + b1
        // Ou a1 = (x end - x begin) / (y end - y begin)
        // /!\ si ybegin = yend -> a tout de suite à 0
        double a1 = seg1->end.x - seg1->begin.x;
        double denominateur = seg1->end.y - seg1->begin.y;
        if(denominateur != 0){
           a1 = a1 / denominateur;
        }else{
            a1 = 0;
        }
        // et b = y begin - a1 * x begin
        double b1 = seg1->begin.y - a1 * seg1->begin.x;
        // Pour seg 2 :
        //on a y = a2 * x + b2 sur le même schéma :
        double a2 = seg2->end.x - seg2->begin.x;
        denominateur = seg2->end.y - seg2->begin.y;
        if(denominateur != 0){
           a2 = a2 / denominateur;
        }else{
            a2 = 0;
        }
        double b2 = seg2->begin.y - a2 * seg2->begin.x;
        // Si a != a' (Sinon, elles sont parallèles -> pas d'intersection)
        if(a1 != a2){
            double x_inter;
            double y_inter;
            // l'intersection est alors au point :
            // xj = (b' - b) / (a - a')
            x_inter = (b2 - b1);
            denominateur = a1 - a2;
            if(denominateur != 0){
                x_inter = x_inter / denominateur;
            }else{
                x_inter = 0;
            }
            // yj = a * xj + b
            y_inter = a1 * x_inter + b1;
            //printf("%f, %f", x_inter, y_inter);

            // Et à la fin, le point d'intersection doit bien être entre les 4 points !!
            // Sinon pas d'intersection
            // Pour se faire, il faut vérifier que le x_inter et le y_inter sont bien entre respectivement les x begin et les x end, les y begin et les y end :
            if(entre_deux_val(seg1->begin.x, seg1->end.x, x_inter) == 1 && entre_deux_val(seg1->begin.y, seg1->end.y, y_inter) == 1){
                if(entre_deux_val(seg2->begin.x, seg2->end.x, x_inter) == 1 && entre_deux_val(seg2->begin.y, seg2->end.y, y_inter) == 1){
                    intersect = (point_t*) malloc(sizeof(point_t));
                    intersect->x = x_inter;
                    intersect->y = y_inter;
                }
            }
         }
    }
    return intersect;
}

int entre_deux_val(double val1, double val2, double valentre){
    if((val1<=valentre && valentre<=val2) || (val2<=valentre && valentre<=val1)){
        return 1;
    }else{
        return 0;
    }
}


