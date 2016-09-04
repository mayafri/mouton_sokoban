#include <stdio.h>
#include <SDL.h>

extern int EcranTitre(SDL_Surface *surface);
extern int EcranNiveau(SDL_Surface *surface, char nomNiveau[50], int nbNiveau);
extern int NiveauxAvancement();
extern int NiveauxNombre();

int main() {
	/* Initialisation SDL et affichage */
	
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Surface *ecran = SDL_SetVideoMode(800, 600, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Mouton Sokoban", 0);
	SDL_EnableKeyRepeat(100, 100);

	/* On récupère des infos */

	int nombreNiveaux = NiveauxNombre();
	int avancement = NiveauxAvancement();

	if ((avancement < 1) || (avancement > nombreNiveaux))
		avancement = 1;
	
	/* On boucle pour chaque niveau */
	
	int reussite = EcranTitre(ecran);
		
	if (reussite == 1) {
		int i;
		for (i=avancement ; i<=nombreNiveaux ; i++) {
			char chemin[50];
			sprintf(chemin, "niveaux/%d.xsb", i);
			if (reussite == 1) {
				do {
					reussite = EcranNiveau(ecran, chemin, i);
				} while (reussite == 2);
			}
		}
	}

	/* Libération des ressources et sortie */
	
	SDL_Quit();
	
	return 0;
}

