#ifndef INITIALISATION_H__
#define INITIALISATION_H__

#include "type.h"
#include <stdio.h>
#include <stdlib.h>


//#define VERBOSE
//#undef VERBOSE

#ifdef VERBOSE
#	define DBG_MSG(...)	printf( __VA_ARGS__);
#else
#	define DBG_MSG(...)	{}
#endif

/**
*Ensemble des fonction d'initialisation
*/
void initialisation ( char* chartab[], unsigned int tablength, struct data_env* env);

/**
* vérification de la cohérence entre le nombre d'individus initial et le nombre d'emplacements sur la carte
*/
int check_indiv_init (struct data_env* env);

/**
*Fonctions de recupération des données utilisateur
*/
void initialisation2 (struct data_env* env);

#endif
