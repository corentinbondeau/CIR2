#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* Exercice 4 :
Ecrire un programme permettant, via trois fonctions différentes, le calcul de « n!» :
	● En itératif avec une boucle « for »
	● En itératif avec une boucle « while »
	● En récursif */

int fact_iter_for(int n)
{
	int fact = 1;
	for (int i = 1; i <= n; i++)
	{
		fact *= i;
	}
	return fact;
}

int fact_iter_while(int n)
{
	int fact = 1;
	int i = 1;
	while (i <= n)
	{
		fact *= i;
		i++;
	}
	return fact;
}

int fact_recursif(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * fact_recursif(n - 1);
	}
}