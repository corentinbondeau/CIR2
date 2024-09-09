#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* EXO 7
Ecrire un programme qui permet de remplir al�atoirement un tableau de n valeurs enti�res et de les
afficher par la suite dans un ordre croissant.
*/

int main() {
    printf("Entrez la taille du tableau\n");
    int n;
    int ret = scanf("%d", &n);
    int* tab = (int*)malloc(n * sizeof(int));
    if (tab == NULL) {
        printf("Erreur d'allocation de m�moire\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++) {
        tab[i] = rand() % 100;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    free(tab);
    return EXIT_SUCCESS;
}
