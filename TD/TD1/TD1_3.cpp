#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

//EXO 3 Ecrire une fonction � minuscule � qui retourne le caract�re en minuscule d�un caract�re donn� en param�tre.
int main()
{
	printf("Entrez une phrase a transformer\n");
	char phrase[100];
	fgets(phrase, 100, stdin);
	for (int i = 0; i < strlen(phrase); i++)
	{
		phrase[i] = tolower(phrase[i]);
	}
	printf("La phrase en minuscule est %s\n", phrase);
	return EXIT_SUCCESS;
}
