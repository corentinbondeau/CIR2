#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* EXO 5
Ecrire un programme qui permet de jouer au jeu du pendu :
● Le mot caché sera saisi par un autre joueur et stocké dans un tableau de type « char ».
● Après chaque proposition de lettre, on affiche de nouveau le mot en remplaçant les lettres
cachées par un caractère spécial (« . », « _ », « * », ... ), Par exemple: si le mot caché est
« PROGRAMME » et que le joueur a trouvé le « P » et le « M », on affiche « P_____MM_ ».
● Si la lettre proposée n’appartient pas au mot caché, alors le nombre de tentatives restantes
est décrémenté, dans la limite de 10 tentatives erronées possibles.
● Le jeu se termine lorsque le mot est trouvé ou quand le nombre de tentatives erronées est atteint.

*/

int main()
{
	char mot[100];
	char mot_cache[100];
	int nb_essais = 10;
	int mot_trouve = 0;
	printf("Entrez le mot a deviner\n");
	fgets(mot, 100, stdin);
	mot[strcspn(mot, "\n")] = '\0'; // Remove newline character from input
	for (int i = 0; i < strlen(mot); i++)
	{
		mot_cache[i] = '.';
	}
	mot_cache[strlen(mot)] = '\0'; // Ensure mot_cache is null-terminated
	while (nb_essais > 0 && mot_trouve == 0)
	{
		printf("Entrez une lettre\n");
		char lettre;
		int ret = scanf(" %c", &lettre); // Added space before %c to consume any leftover newline
		int lettre_trouvee = 0;
		for (int i = 0; i < strlen(mot); i++)
		{
			if (mot[i] == lettre)
			{
				mot_cache[i] = lettre;
				lettre_trouvee = 1;
				nb_essais--;
			}
		}
		if (lettre_trouvee == 0)
		{
			nb_essais--;
		}
		printf("Il vous reste %d essais\n", nb_essais);
		printf("Mot cache : %s\n", mot_cache);
		if (strcmp(mot, mot_cache) == 0)
		{
			mot_trouve = 1;
		}
	}
	if (mot_trouve == 1)
	{
		printf("Bravo, vous avez trouve le mot\n");
	}
	else
	{
		printf("Vous avez perdu, le mot etait %s\n", mot);
	}
	return EXIT_SUCCESS;
}

	
