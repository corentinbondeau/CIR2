#include <iostream.h>
#define multiplier (x,y) (x * y)

int main(void)
{
	int a;
	int b;
	cout << "Entrez une valeur :" << endl;
	cin << a;
	cout << "Entrez une autre valeur :" << endl;
	cin << b;
	cout << multiplier(a + 1, b + 1) << endl;
}// b) Au regard de (a), explorez la possibilité d’utiliser les mots clés constexpr et consteval vus en cours pour remplacer la macro « multiplier » ci - dessus..