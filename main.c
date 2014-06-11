#include "toolbox.h"
#include "toolbox_matrice.h"
#include "initialisation.h"
#include "init_monde.h"
#include "fonctionnement.h"
#include "type.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // \brief pour utiliser time()

/**
*	Programme usage : ./a.out HxL #initial #cycles
*/
int main(int argc, char* argv[]) // \brief argc nombre d'arguments dans le main, argv tableau des arguments contient des chaines de caractères
{
	struct data_env env = {-1,-1,-1,-1,-1};
	struct data_monde world = {0,0,10,0,0};
	struct data_indiv** monde = {0};
	srand(time (NULL)); //\brief génère une nouvelle "graine" pour random()

	initialisation ( argv, argc, &env); //\brief initialisation.c

	world.H = env.hauteur;
	world.L = env.largeur;
	world.nbr_place_restant = env.nbr_indiv_max;
	
	monde = init_monde (&world); //\brief init_monde.c

	peuple_monde (env.nbrindiv_init, &world); //\brief init_monde.c

	affiche_monde (&world); //\brief init_monde.c

	while(env.nbrcycles != 0)
	{

		comptnbrvoisins (&world); //\brief fonctionnement.c

		mort (&world); //\brief fonctionnement.c

		initnbrvoisins (&world); //\brief fonctionnement.c

		printf("---------------------------------------------------------------------\n");

		affiche_monde (&world); //\brief init_monde.c
			
		env.nbrcycles --;
	}

	free(monde);

	return 0;
}
