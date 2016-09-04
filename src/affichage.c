#include <stdio.h>
#include <SDL.h>
#include <SDL/SDL_ttf.h>

/* Affichage de l'écran titre */

/* La fonction nécessite une surface pour l'affichage. */

void TitreAfficher(SDL_Surface *surface) {
	SDL_Surface *sol = SDL_LoadBMP("sprites/titre.bmp");
	SDL_BlitSurface(sol, NULL, surface, NULL);
	SDL_Flip(surface);
}



/* Affichage du niveau stocké dans la matrice */

/* Paramètres : la matrice, la position du personnage, sa direction, une surface
   pour l'affichage, le nombre de coups à afficher, et le numéro de niveau. */

void NiveauAfficher(int (*matrice)[25], int *positionPerso, char dirPerso, SDL_Surface *surface, int nbCoups, int nbNiveau) {
	SDL_Surface *ext = SDL_LoadBMP("sprites/ext.bmp");
	SDL_Surface *sol = SDL_LoadBMP("sprites/sol.bmp");
	SDL_Surface *mur = SDL_LoadBMP("sprites/mur.bmp");
	SDL_Surface *boite = SDL_LoadBMP("sprites/boite.bmp");
	SDL_Surface *cible = SDL_LoadBMP("sprites/cible.bmp");
	SDL_Surface *boitecible = SDL_LoadBMP("sprites/boitecible.bmp");
	SDL_Surface *persog = SDL_LoadBMP("sprites/persog.bmp");
	SDL_Surface *persod = SDL_LoadBMP("sprites/persod.bmp");
	SDL_Surface *persoh = SDL_LoadBMP("sprites/persoh.bmp");
	SDL_Surface *persob = SDL_LoadBMP("sprites/persob.bmp");
	
	SDL_SetColorKey(mur, SDL_SRCCOLORKEY, SDL_MapRGB(mur->format, 0, 0, 255));
	SDL_SetColorKey(boite, SDL_SRCCOLORKEY, SDL_MapRGB(boite->format, 0, 0, 255));	
	SDL_SetColorKey(cible, SDL_SRCCOLORKEY, SDL_MapRGB(cible->format, 0, 0, 255));
	SDL_SetColorKey(boitecible, SDL_SRCCOLORKEY, SDL_MapRGB(boitecible->format, 0, 0, 255));
	SDL_SetColorKey(persog, SDL_SRCCOLORKEY, SDL_MapRGB(persog->format, 0, 0, 255));
	SDL_SetColorKey(persod, SDL_SRCCOLORKEY, SDL_MapRGB(persod->format, 0, 0, 255));
	SDL_SetColorKey(persoh, SDL_SRCCOLORKEY, SDL_MapRGB(persoh->format, 0, 0, 255));
	SDL_SetColorKey(persob, SDL_SRCCOLORKEY, SDL_MapRGB(persob->format, 0, 0, 255));
			
	SDL_Rect spritesPos;
	spritesPos.x = 0;
	spritesPos.y = 0;
	
	/* Placement du fond */
	
	int i;
	for (i=0 ; i < 19 ; i++) {
		spritesPos.x = 0;
		int ii;
		for (ii=0 ; ii < 25 ; ii++) {
			SDL_BlitSurface(sol, NULL, surface, &spritesPos);
			spritesPos.x += 32;
		}
		spritesPos.y += 32;
	}
	
	/* Placement des objets */
	
	spritesPos.y = 0;
		
	for (i=0 ; i < 19 ; i++) {
		spritesPos.x = 0;
		int ii;
		for (ii=0 ; ii < 25 ; ii++) {
			if (matrice[i][ii] == 1) {
				SDL_BlitSurface(mur, NULL, surface, &spritesPos);
			}
			else if (matrice[i][ii] == 2) {
				SDL_BlitSurface(boite, NULL, surface, &spritesPos);
			}
			else if (matrice[i][ii] == 3) {
				SDL_BlitSurface(cible, NULL, surface, &spritesPos);
			}
			else if ((matrice[i][ii] == 4) || (matrice[i][ii] == 5)) {
				positionPerso[0] = ii;
				positionPerso[1] = i;
				if (dirPerso == 'G')
					SDL_BlitSurface(persog, NULL, surface, &spritesPos);
				else if (dirPerso == 'D')
					SDL_BlitSurface(persod, NULL, surface, &spritesPos);
				else if (dirPerso == 'H')
					SDL_BlitSurface(persoh, NULL, surface, &spritesPos);
				else if (dirPerso == 'B')
					SDL_BlitSurface(persob, NULL, surface, &spritesPos);
			}
			else if (matrice[i][ii] == 6) {
				SDL_BlitSurface(boitecible, NULL, surface, &spritesPos);
			}
			spritesPos.x += 32;
		}
		spritesPos.y += 32;
	}
	
	/* Placement du contour */
	
	/*
	spritesPos.y = 0;
	
	for (i=0 ; i < 19 ; i++) {
		spritesPos.x = 0;
		int ii;
		for (ii=0 ; (ii < 25) ; ii++) {
			if (matrice[i][ii] == 1)
				ii = 25;
			else
				SDL_BlitSurface(ext, NULL, surface, &spritesPos);
			spritesPos.x += 32;
		}
		spritesPos.x = 800;
		for (ii=25 ; (ii > 0) ; ii--) {
			if (matrice[i][ii] == 1)
				ii = 0;
			else
				SDL_BlitSurface(ext, NULL, surface, &spritesPos);
			spritesPos.x -= 32;
		}
		spritesPos.y += 32;
	}
	*/
	
	/* Informations en texte */
	
	char sNbCoups[30];
	sprintf(sNbCoups,"Coups : %d",nbCoups);
	
	char sNbNiveau[80];
	sprintf(sNbNiveau,"Niveau %d",nbNiveau);
		
	TTF_Init();
	TTF_Font *police = TTF_OpenFont("polices/FreeSansBold.ttf", 20);
	
	SDL_Color noir = {255, 255, 255};
	
	SDL_Surface *niveau = TTF_RenderText_Blended(police, sNbNiveau, noir);
	SDL_Surface *coups = TTF_RenderText_Blended(police, sNbCoups, noir);
		
	SDL_Rect textePos;
	textePos.x = 32;
	textePos.y = 32;
	
	SDL_BlitSurface(niveau, NULL, surface, &textePos);
	textePos.y += 32;
	SDL_BlitSurface(coups, NULL, surface, &textePos);
		
	SDL_FreeSurface(coups);
	TTF_CloseFont(police);
	TTF_Quit();
	
	SDL_Flip(surface);
	
	SDL_FreeSurface(ext);
	SDL_FreeSurface(sol);
	SDL_FreeSurface(mur);
	SDL_FreeSurface(boite);
	SDL_FreeSurface(cible);
	SDL_FreeSurface(boitecible);
	SDL_FreeSurface(persog);
	SDL_FreeSurface(persod);
	SDL_FreeSurface(persoh);
	SDL_FreeSurface(persob);
}

