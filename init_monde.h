#ifndef INIT_MONDE_H__
#define INIT_MONDE_H__

#include "type.h"
#include <stdio.h>
#include <stdlib.h>

/**
* création de la matrice du monde
*/

struct data_indiv** init_monde (struct data_monde* world);

/**
* peuplement aléatoire du monde en fonction du nombre d'individu initial
*/

void peuple_monde (int indiv, struct data_monde* world);

/**
* afficher le monde
*/

void affiche_monde (struct data_monde * world);

/**
* afficher le nombre de voisins
*/

void affiche_voisins (struct data_monde * world);

#endif
