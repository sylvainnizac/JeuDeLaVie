#ifndef TYPE_H__
#define TYPE_H__

#include <stdio.h>
#include <stdlib.h>

/**
* structure utilisée pour définir chaque cas du monde
*/
struct data_indiv
{
int presence;
int nbr_voisins;
};

struct data_monde
{
int H;
int L;
int death_date;
int nbr_place_restant;
struct data_indiv** monde;
};

/**
* structure utilisée pour stockée les paramètres essentiels du monde
*/
struct data_env
{
int hauteur;
int largeur;
int nbrindiv_init;
int nbr_indiv_max;
int nbrcycles;
};


#endif
