#ifndef FONCTIONNEMENT_H__
#define FONCTIONNEMENT_H__

#include "type.h"
#include <stdio.h>
#include <stdlib.h>

/**
* initialisation du nombre de voisins
*/

void initnbrvoisins ( struct data_monde* world);

void init (int pos_h, int pos_l, struct data_monde* world);

/**
* fonction de comptage du nombre de voisins
*/

void comptnbrvoisins (struct data_monde * world);

void cmpt ( int h_pos, int l_pos, struct data_monde * world);

/**
* fonction de mort
*/

void mort (struct data_monde * world);

void checkmort ( int h, int l, struct data_monde * world);

#endif
