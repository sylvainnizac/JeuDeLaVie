#include "toolbox.h"
#include "toolbox_matrice.h"

/**
* afficher une matrice d'int
*/

void affiche_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			printf("%i ", matrice[i][j]);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/**
* initialiser une matrice d'int
*/

void init_matrice_int (int hauteur_matrice, int largeur_matrice, int** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			matrice[i][j] = 0;
			j++;
		}
		i++;
		j = 0;
	}
}

/**
* afficher une matrice de str
*/

void affiche_matrice_str (int hauteur_matrice, int largeur_matrice, struct matrice** matrice)
{
	int i = 0;
	int j = 0;
	while ( i < hauteur_matrice )
	{
		while ( j < largeur_matrice )
		{
			printf("%i ", matrice[i][j].data1);
			j++;
		}
		printf("\n");
		i++;
		j = 0;
	}
}

/**
* parcourir une matrice et exécuter une fonction sur chacune de ses cases
*/
void parcour_matrice ( struct data_monde* world, void (*fonction)(int, int, struct data_monde*))
{
	int h = world->H;
	int l = world->L;
	for(h = 0; h < world->H; h++)
	{		
		for(l = 0; l < world->L; l++)
		{
			(*fonction)(h, l, world); //\brief fonction à exécuter
		}
	}
}

/**
* parcourir une matrice et exécuter une fonction sur chacune de ses cases v2
*/
void parcour_matrice_v2 (struct data_monde* world, void (*fonction)(int, int, struct data_monde*))
{
	int h = world->H;
	int l = world->L;
	for(h = 0; h < world->H; h++)
	{		
		for(l = 0; l < world->L; l++)
		{
			(*fonction)(h, l, world); //\brief fonction à exécuter
		}
	}
}



