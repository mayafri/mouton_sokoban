#include <stdio.h>

/* Déplace le perso dans la direction souhaitée si possible. */

/* Paramètres : matrice, tableau de position du perso,
   direction souhaitée (G,D,H,B) */

/* Test de possibilité : (vide OU cible) OU
   ((case OU case sur cible) ET (vide derrière OU cible derrière)) */

int Deplacement(int (*m)[25], int *pos, char direction) {
	int retour = 0;
	
	/* POUR LA DIRECTION GAUCHE */
	if (direction == 'G') {
		if (((m[pos[1]][pos[0]-1] == 0) || (m[pos[1]][pos[0]-1] == 3)) || (((m[pos[1]][pos[0]-1] == 2) || (m[pos[1]][pos[0]-1] == 6)) && ((m[pos[1]][pos[0]-2] == 0) || (m[pos[1]][pos[0]-2] == 3)))) {
			// Si boite, on la déplace
			if ((m[pos[1]][pos[0]-1] == 2) || (m[pos[1]][pos[0]-1] == 6)) {
				// Si on la pose sur une cible
				if (m[pos[1]][pos[0]-2] == 3)
					m[pos[1]][pos[0]-2] = 6;
				else
					m[pos[1]][pos[0]-2] = 2;
			}
				
			// Si on se pose sur une cible
			if ((m[pos[1]][pos[0]-1] == 3) || (m[pos[1]][pos[0]-1] == 6))
				m[pos[1]][pos[0]-1] = 5;
			else
				m[pos[1]][pos[0]-1] = 4;
				
			// Si on quitte une cible
			if (m[pos[1]][pos[0]] == 5)
				m[pos[1]][pos[0]] = 3;
			else
				m[pos[1]][pos[0]] = 0;
				
			retour = 1;
		}
	}
	
	/* POUR LA DIRECTION DROITE */
	if (direction == 'D') {
		if (((m[pos[1]][pos[0]+1] == 0) || (m[pos[1]][pos[0]+1] == 3)) || (((m[pos[1]][pos[0]+1] == 2) || (m[pos[1]][pos[0]+1] == 6)) && ((m[pos[1]][pos[0]+2] == 0) || (m[pos[1]][pos[0]+2] == 3)))) {
			// Si boite, on la déplace
			if ((m[pos[1]][pos[0]+1] == 2) || (m[pos[1]][pos[0]+1] == 6)) {
				// Si on la pose sur une cible
				if (m[pos[1]][pos[0]+2] == 3)
					m[pos[1]][pos[0]+2] = 6;
				else
					m[pos[1]][pos[0]+2] = 2;
			}
				
			// Si on se pose sur une cible
			if ((m[pos[1]][pos[0]+1] == 3) || (m[pos[1]][pos[0]+1] == 6))
				m[pos[1]][pos[0]+1] = 5;
			else
				m[pos[1]][pos[0]+1] = 4;
			
			// Si on quitte une cible
			if (m[pos[1]][pos[0]] == 5)
				m[pos[1]][pos[0]] = 3;
			else
				m[pos[1]][pos[0]] = 0;
				
			retour = 1;
		}
	}
	
	/* POUR LA DIRECTION HAUT */
	if (direction == 'H') {
		if (((m[pos[1]-1][pos[0]] == 0) || (m[pos[1]-1][pos[0]] == 3)) || (((m[pos[1]-1][pos[0]] == 2) || (m[pos[1]-1][pos[0]] == 6)) && ((m[pos[1]-2][pos[0]] == 0) || (m[pos[1]-2][pos[0]] == 3)))) {
			// Si boite, on la déplace
			if ((m[pos[1]-1][pos[0]] == 2) || (m[pos[1]-1][pos[0]] == 6)) {
				// Si on la pose sur une cible
				if (m[pos[1]-2][pos[0]] == 3)
					m[pos[1]-2][pos[0]] = 6;
				else
					m[pos[1]-2][pos[0]] = 2;
			}
				
			// Si on se pose sur une cible
			if ((m[pos[1]-1][pos[0]] == 3) || (m[pos[1]-1][pos[0]] == 6))
				m[pos[1]-1][pos[0]] = 5;
			else
				m[pos[1]-1][pos[0]] = 4;
			
			// Si on quitte une cible
			if (m[pos[1]][pos[0]] == 5)
				m[pos[1]][pos[0]] = 3;
			else
				m[pos[1]][pos[0]] = 0;
				
			retour = 1;
		}
	}
	
	/* POUR LA DIRECTION BAS */
	if (direction == 'B') {
		if (((m[pos[1]+1][pos[0]] == 0) || (m[pos[1]+1][pos[0]] == 3)) || (((m[pos[1]+1][pos[0]] == 2) || (m[pos[1]+1][pos[0]] == 6)) && ((m[pos[1]+2][pos[0]] == 0) || (m[pos[1]+2][pos[0]] == 3)))) {
			// Si boite, on la déplace
			if ((m[pos[1]+1][pos[0]] == 2) || (m[pos[1]+1][pos[0]] == 6)) {
				// Si on la pose sur une cible
				if (m[pos[1]+2][pos[0]] == 3)
					m[pos[1]+2][pos[0]] = 6;
				else
					m[pos[1]+2][pos[0]] = 2;
			}
				
			// Si on se pose sur une cible
			if ((m[pos[1]+1][pos[0]] == 3) || (m[pos[1]+1][pos[0]] == 6))
				m[pos[1]+1][pos[0]] = 5;
			else
				m[pos[1]+1][pos[0]] = 4;
			
			// Si on quitte une cible
			if (m[pos[1]][pos[0]] == 5)
				m[pos[1]][pos[0]] = 3;
			else
				m[pos[1]][pos[0]] = 0;
			
			retour = 1;
		}
	}
	
	return retour;
}

