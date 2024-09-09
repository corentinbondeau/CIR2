#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* EXO 6
Qu'imprime le programme suivant ?
*/

int main()
{
	printf("Programme 1 affiche 4\n");
	int a = 14, b = 13;
	if (a > b)
	{
		if (a < 20)
		{
			a -= 10;
		}
		else
		{
			a += 10;
		}
	}
	printf("%d\n", a);

	printf("Programme 2 affiche 4\n");
	int x = 4, y = 3;
	x = x + y;
	y = x - y;
	printf("%d\n", y);

	printf("Programme 3 tourne 11 fois\n");
	int m = 0, n = 100;
	int i = 0;
	while (m * m <= n)
	{
		m += 1;
		i++;
	}
	printf("%d\n", i);
	return EXIT_SUCCESS;


}
