#include "toolbox.h"
#include "toolbox_matrice.h"
#include "init_monde.h"
#include "type.h"

/**
* création de la matrice du monde, sous forme d'un tableau de tableaux
*/

struct data_indiv** init_monde (struct data_monde* world)
{
	int i = 0;

	world->monde = calloc(world->H, sizeof(struct data_indiv*));
/**
*calloc est une allocation dynamique de tableau préinitialisé. ici monde est un tableau de H cases de la taille d'un pointeur sur struct data_indiv
*/
	while ( i < world->H )
	{
		world->monde[i] = calloc(world->L, sizeof(struct data_indiv));
/**
*chaque case de monde (monde[i]) contient L cases de la taille d'une struct data_indiv
*/
		i++;
	}
	return world->monde;
}

/**
* peuplement aléatoire du monde en fonction du nombre d'individu initial, N et M coordonnées de l'élément du monde considéré
*/
void peuple_monde (int indiv, struct data_monde* world)
{
	int i;
	int N = 0;
	int M = 0;
	for (i = 0; i < indiv; )
	{
		N = random() % world->H;
		M = random() % world->L;
		if (world->monde[N][M].presence == 0)
		{
			world->monde[N][M].presence = 1;
			world->nbr_place_restant--;
			i++;
		}
	}
}


/**
* afficher le monde
*/

void affiche_monde (struct data_monde* world)
{
	int i = 0;
	int j = 0;
	while ( i < world->H )
	{

		while ( j < world->L )
		{
			printf("%i ", world->monde[i][j].presence); //affiche la variable présence de la case [i][j] de la matrice du monde
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/**
* afficher le nombre de voisins
* fonction utilisée en cours de développement pour vérifier le fonctionnement des autes fonctions
*/

void affiche_voisins (struct data_monde* world)
{
	int i = 0;
	int j = 0;
	while ( i < world->H )
	{
		while ( j < world->L )
		{
			printf("%i ", world->monde[i][j].nbr_voisins);  //affiche la variable nbr_voisins de la case [i][j] de la matrice du monde
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}
