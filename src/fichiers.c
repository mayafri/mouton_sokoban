#include <stdio.h>
#include <dirent.h>

/* Chargement du niveau depuis un fichier texte, dans une matrice. */

/* Paramètres : la matrice et le chemin du niveau. */

void NiveauCharger(int (*matrice)[25], char nomNiveau[50]) {
	FILE *niveau = fopen(nomNiveau, "rd");

	int i;
	for (i=0 ; i < 19 ; i++) {
		int ii;
		for (ii=0 ; ii < 25 ; ii++) {
			matrice[i][ii] = 0;
		}
	}

	for (i=0 ; i < 19 ; i++) {
		int ii;
		for (ii=0 ; ii < 25 ; ii++) {
			char car = getc(niveau);
			switch(car) {
			case '#':
				matrice[i][ii] = 1;
				break;
			case '$':
				matrice[i][ii] = 2;
				break;
			case '.':
				matrice[i][ii] = 3;
				break;
			case '@':
				matrice[i][ii] = 4;
				break;
			case '*':
				matrice[i][ii] = 4;
				break;
			case '+':
				matrice[i][ii] = 4;
				break;
			case '\n':
				ii = 25;
				break;
			}
		}
	}

	fclose(niveau);
}

void NiveauSauver(int numeroNiveau) {
	FILE *fichier = fopen("avancement.txt", "w");
	fprintf(fichier, "%d", numeroNiveau);
	fclose(fichier);
}

int NiveauxAvancement() {
	int avancement;
	
	FILE *fichier = fopen("avancement.txt", "a+");
	fscanf(fichier, "%d", &avancement);
	fclose(fichier);
	
	return avancement;
}

int NiveauxNombre() {
	int nb = -2;
	
    DIR* rep = opendir("niveaux/");

	while ((readdir(rep)) != NULL)
		nb++;

    closedir(rep);
    
    return nb;
}

