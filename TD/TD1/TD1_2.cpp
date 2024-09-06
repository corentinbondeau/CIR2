#include<stdlib.h>
#include<stdio.h>
#include<math.h> 

int main()
{ 
	//EXO 2 Ecrire le programme en C permettant le calcul des racines d'une �quation du second degr� (ax^2 + bx + c = 0)

	//On demande � l'utilisateur de saisir les valeurs de a, b et c
	float a, b, c;
	printf("Entrez les valeurs de a, b et c\n");
	scanf("%f %f %f", &a, &b, &c);


	//Calcul du discriminant
	float delta = b * b - 4 * a * c;
	//Si delta est n�gatif, il n'y a pas de solution r�elle
	if (delta < 0)
	{
		printf("Pas de solution r�elle\n");
	}
	//Si delta est nul, il y a une seul solution r�elle
	else if (delta == 0)
	{
		float x = -b / (2 * a);
		printf("La solution est %f\n", x);
	}
	//Si delta est positif, il y a deux solutions r�elles qu'on calcule 
	else
	{
		float x1 = (-b - sqrt(delta)) / (2 * a);
		float x2 = (-b + sqrt(delta)) / (2 * a);
		printf("Les solutions sont %f et %f\n", x1, x2);
	}
	return EXIT_SUCCESS;
}