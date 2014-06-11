#include "toolbox.h"
#include "toolbox_matrice.h"
#include "initialisation.h"
#include "type.h"

/**
*Ensemble des fonction d'initialisation
*/

void initialisation ( char* chartab[], unsigned int tablength, struct data_env* env)
{
	int i = tablength - 1;
	char * Nbrcycles = chartab[i];
	--i;
	char * Nbrindiv_init = chartab[i];
	--i;
	char * Dim_monde = chartab[i];

//définir longueur Str des dimensions du monde

	int lenghtStrDim_monde = lenghtStr (Dim_monde);

//définir longueur Str du nbr individus initial

	int lenghtStrnbrindiv = lenghtStr (Nbrindiv_init);	

//définir longueur Str du nbr de cycles

	int lenghtStrnbrcycles = lenghtStr (Nbrcycles);

//Copier la hauteur du monde dans un int

	int hauteur = convStrIntdebut (Dim_monde);
	assert(hauteur != -1); //vérification d'erreur, -1 est la valeur d'erreur

//Copier la largeur du monde dans un int

	int largeur = convStrIntfin (Dim_monde, lenghtStrDim_monde);
	assert(largeur != -1); //vérification d'erreur, -1 est la valeur d'erreur

//copier nombre individu dans un int
	int nbrindiv_init = convStrIntfin (Nbrindiv_init, lenghtStrnbrindiv);
	assert(nbrindiv_init != -1); //vérification d'erreur, -1 est la valeur d'erreur

//copier nombre de cycles dans un int
	int nbrcycles = convStrIntfin (Nbrcycles, lenghtStrnbrcycles);
	assert(nbrcycles != -1); //vérification d'erreur, -1 est la valeur d'erreur

//reporter les valeurs calculées dans la struct data_env globale (pointeur)
	env->hauteur = hauteur;
	env->largeur = largeur;
	(*env).nbrindiv_init = nbrindiv_init;
	env->nbrcycles = nbrcycles;

//vérification de la cohérence entre le nombre d'individus initial et le nombre d'emplacements sur la carte
	int check = check_indiv_init (env);
	assert(check != -1); //vérification d'erreur, -1 est la valeur d'erreur

/**
	DBG_MSG("TEST\n")
	DBG_MSG("TEST : %s\n", "HELLO")
	DBG_MSG("Nbrindiv_init = %s\n", Nbrindiv_init)
	DBG_MSG("Dim_monde = %s\n", Dim_monde);
	DBG_MSG("Nbrcycles = %s\n", Nbrcycles);
	DBG_MSG("lenghtStrDim_monde = %i\n", lenghtStrDim_monde);
	DBG_MSG("lenghtStrnbrindiv = %i\n", lenghtStrnbrindiv);
	DBG_MSG("lenghtStrnbrcycles = %i\n", lenghtStrnbrcycles);
	DBG_MSG("hauteur = %i\n", hauteur);
	DBG_MSG("largeur = %i\n", largeur);
	DBG_MSG("nbrindiv_init = %i\n", nbrindiv_init);
	DBG_MSG("nbrcycles = %i\n", nbrcycles);
*/

}

/**
 * vérification de la cohérence entre le nombre d'individus initial et le nombre d'emplacements sur la carte
 */
int check_indiv_init (struct data_env* env)
{
	int i = env->hauteur * env->largeur;
	int j = env->nbrindiv_init;
	env->nbr_indiv_max = i;

	if(i <= j)
	{
		printf("trop d'individus sur la carte pas d'évolution possible/n");
		return -1;
	}
	else
	{
		return 0;
	}
}
