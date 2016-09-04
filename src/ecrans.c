#include <stdio.h>
#include <SDL.h>

extern void TitreAfficher(SDL_Surface *surface);
extern void NiveauCharger(int (*matrice)[25], char nomNiveau[50]);
void NiveauSauver(int numeroNiveau);
extern void NiveauAfficher(int (*matrice)[25], int *positionPerso, char dirPos, SDL_Surface *surface, int nbCoups, int nbNiveau);
extern int Deplacement(int (*m)[25], int *pos, char direction);

/* Génération de l'écran titre avec les évènements */

/* Paramètres : une surface pour l'affichage */

int EcranTitre(SDL_Surface *surface) {
	TitreAfficher(surface);

	/* Évènements */
	
	/* Depuis la réforme de l'orthographe du Français français en 1990
	   il est possible d'écrire le mot « évènement » de telle sorte. */
	
	int boucle = 1;
	SDL_Event even;
	
	while (boucle) {
		SDL_WaitEvent(&even);
		
		if (even.type == SDL_QUIT) {
			boucle = 0;
		}
		if (even.type == SDL_KEYDOWN) {
			if (even.key.keysym.sym == SDLK_ESCAPE)
				boucle = 0;
			else
				return 1;
		}
	}
	
	return 0;
}



/* Génère un écran de niveau */

/* Paramètres : une surface pour l'affichage, le chemin du niveau, son numéro */

int EcranNiveau(SDL_Surface *surface, char nomNiveau[50], int nbNiveau) {
	int BoitesRestantes(int (*matrice)[25]) {
		int restant = 0;
	
		int i;
		for (i=0 ; i < 19 ; i++) {
			int ii;
			for (ii=0 ; ii < 25 ; ii++) {
				if ((matrice[i][ii] == 3) || (matrice[i][ii] == 5))
					restant++;
			}
		}
	
		return restant;
	}

	int matrice[19][25];
	NiveauCharger(matrice, nomNiveau);
	
	int nombreCoups = 0;
	int posPerso[2];
	
	NiveauAfficher(matrice, posPerso, 'G', surface, nombreCoups, nbNiveau);

	/* Évènements */
	
	int boucle = 1;
	SDL_Event even;
	
	while (boucle) {
		SDL_WaitEvent(&even);
		
		if (even.type == SDL_QUIT) {
			boucle = 0;
		}
		if (even.type == SDL_KEYDOWN) {
			if (even.key.keysym.sym == SDLK_ESCAPE) {
				boucle = 0;
			}
			if ((even.key.keysym.sym == SDLK_LEFT) || (even.key.keysym.sym == SDLK_q)) {
				if (Deplacement(matrice, posPerso, 'G'))
					nombreCoups++;
				NiveauAfficher(matrice, posPerso, 'G', surface, nombreCoups, nbNiveau);
			}
			if ((even.key.keysym.sym == SDLK_RIGHT) || (even.key.keysym.sym == SDLK_d)) {
				if (Deplacement(matrice, posPerso, 'D'))
					nombreCoups++;
				NiveauAfficher(matrice, posPerso, 'D', surface, nombreCoups, nbNiveau);
			}
			if ((even.key.keysym.sym == SDLK_UP) || (even.key.keysym.sym == SDLK_z)) {
				if (Deplacement(matrice, posPerso, 'H'))
					nombreCoups++;
				NiveauAfficher(matrice, posPerso, 'H', surface, nombreCoups, nbNiveau);
			}
			if ((even.key.keysym.sym == SDLK_DOWN) || (even.key.keysym.sym == SDLK_s)) {
				if (Deplacement(matrice, posPerso, 'B'))
					nombreCoups++;
				NiveauAfficher(matrice, posPerso, 'B', surface, nombreCoups, nbNiveau);
			}
			if ((BoitesRestantes(matrice) == 0) || (even.key.keysym.sym == SDLK_DELETE)) {
				NiveauSauver(nbNiveau+1);
				return 1;
			}
			if (even.key.keysym.sym == SDLK_RETURN) {
				return 2;
			}
		}
	}
	
	return 0;
}

