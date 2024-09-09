#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* EXO 8
Ecrire un programme qui permet d�allouer un tableau � deux dimensions n par m initialis� par des
valeurs al�atoires qui seront tri�s dans un ordre croissant colonne par colonne(attention �
l�agencement en m�moire des valeurs dans un tableau � deux dimensions).*/

int main() {
	printf("Entrez la taille du tableau\n");
	int n, m;
	scanf("%d %d", &n, &m);
	int** tab = (int**)malloc(n * sizeof(int*));
	if (tab == NULL) {
		printf("Erreur d'allocation de m�moire\n");
		return EXIT_FAILURE;
	}
	for (int i = 0; i < n; i++) {
		tab[i] = (int*)malloc(m * sizeof(int));
		if (tab[i] == NULL) {
			printf("Erreur d'allocation de m�moire\n");
			return EXIT_FAILURE;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			tab[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < n - 1; k++) {
				if (tab[k][j] > tab[k + 1][j]) {
					int temp = tab[k][j];
					tab[k][j] = tab[k + 1][j];
					tab[k + 1][j] = temp;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%d ", tab[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		free(tab[i]);
	}
	free(tab);
	return EXIT_SUCCESS;
}