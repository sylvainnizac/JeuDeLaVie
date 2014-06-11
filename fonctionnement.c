#include "toolbox.h"
#include "toolbox_matrice.h"
#include "fonctionnement.h"
#include "type.h"
#include "init_monde.h"

/**
* Ensemble des fonctions de fonctionnement du jeu
*/

/**
* fonctions d'initialisation du nombre de voisins
*/

void initnbrvoisins (struct data_monde* world)
{
	void (*ptrinit)(int, int, struct data_monde*);
	ptrinit = init;
//\brief création et initialisation du pointeur sur la fonction init de façon à l'appeler das parcour_matrice et exécuter la fonction "à distance"

	parcour_matrice (world, ptrinit);
}

void init (int pos_h, int pos_l,  struct data_monde* world)
{
	world->monde[pos_h][pos_l].nbr_voisins = 0;
}

/**
* fonctions de comptage du nombre de voisins
*/

void comptnbrvoisins ( struct data_monde* world)
{
	void (*ptrcmpt)(int, int, struct data_monde*);
	ptrcmpt = cmpt;
//\brief création et initialisation du pointeur sur la fonction cmpt de façon à l'appeler das parcour_matrice et exécuter la fonction "à distance"

	parcour_matrice_v2 (world, ptrcmpt);
}

void cmpt ( int h, int l, struct data_monde* world)
{
	int i;
	int j;
	int h_mod = 0;
	int l_mod = 0;
	for(i = -1; i <= 1; i++)
	{
		for(j = -1; j <= 1; j++)
		{
			h_mod = h + i;
			l_mod = l + j;
			if(i == 0 && j == 0)
			{
				continue;
			}
			else if(0 <= h_mod && h_mod < world->H && 
				0 <= l_mod && l_mod < world->L && 
				world->monde[h_mod][l_mod].presence != 0)
			{
				world->monde[h][l].nbr_voisins++;
			}
		}
	}
}

/**
* fonctions de mort
*/

void mort ( struct data_monde* world)
{
	void(*ptrcheckmort)(int, int, struct data_monde*);
	ptrcheckmort = checkmort;
//\brief création et initialisation du pointeur sur la fonction checkmort de façon à l'appeler das parcour_matrice_v2 et exécuter la fonction "à distance"

	parcour_matrice_v2 (world, ptrcheckmort);
}

void checkmort ( int h, int l, struct data_monde* world)
{
	int i;
	int m = 0;
	int n = 0;

	if((world->monde[h][l].presence == 0) && (world->monde[h][l].nbr_voisins >= 3))
	{
		world->monde[h][l].presence = 1;
		world->nbr_place_restant--;
	}
	else if(world->monde[h][l].presence > 0)
	{
		if(world->monde[h][l].nbr_voisins >= 2)
		{
			world->monde[h][l].presence++;

			if(world->monde[h][l].nbr_voisins >= 3 && world->monde[h][l].presence < 10)
			{
				for(i = 0; i < 1; )
				{
							if (world->nbr_place_restant == 0)
							{
								printf("plus de place disponible, fin de la simulation.\n");
								affiche_monde (world); //\brief init_monde.c
								exit(EXIT_SUCCESS);
							}
					n = random() % world->H;
					m = random() % world->L;
					if (world->monde[n][m].presence == 0)
					{
						world->monde[n][m].presence = 1;
						world->nbr_place_restant--;
						i++;
					}
				}
			}
		}
		else
		{
			world->monde[h][l].presence = 0;
			world->nbr_place_restant++;
		}
	}


}

/* autre version des fonctions d'initialisation
for (int i = 0; i < H; ++i)
	for (int j = 0; j < L; ++j)
		ptr_f(&(monde[i][j].nbr_voisin));

void init_daft (int *x)
{
	*x = 0;
}
//*/
