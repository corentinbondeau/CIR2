#include <iomanip>
#include <iostream>

int multiplier(int x, int y) {
	return x * y;
}

/*
int main(void) {
	int a;
	std::cout << "Entrez une valeur : " << std::endl;
	std::cin >> a;
	for (size_t i = 1; i < 10; i++)
	{
		std::cout << multiplier(a, i) << std::endl;
	}
}
*/
using namespace std;

int main() {
	// En-tête de la table
	cout << "      ";
	for (int i = 1; i <= 10; ++i) {
		cout << setw(4) << i; // Aligne les nombres sur 4 caractères
	}
	cout << endl;

	// Lignes de la table
	for (int i = 1; i <= 10; ++i) {
		cout << setw(4) << i << " | ";
		for (int j = 1; j <= 10; ++j) {
			cout << setw(4) << i * j;
		}
		cout << endl;
	}

	return 0;
}
