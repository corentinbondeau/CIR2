#include <iostream> // Inclut l'en-t�te pour les entr�es/sorties standard (pour utiliser cout)
#include <set>     // Inclut l'en-t�te pour les conteneurs de type set et multiset

using namespace std; // Permet d'utiliser les �l�ments de l'espace de noms std sans avoir � les pr�fixer avec std::

int main() {
    int a[] = { 7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2 }; // D�clare un tableau d'entiers a contenant les valeurs donn�es

    multiset<int> s(&a[0], &a[17]); // Cr�e un multiset d'entiers nomm� s en initialisant avec les �l�ments du tableau a 
    // � partir de l'adresse du premier �l�ment (&a[0]) jusqu'� l'adresse du 18�me �l�ment (&a[17])

// Le multiset est un conteneur qui stocke des �l�ments tri�s et qui permet les doublons.

    multiset<int>::iterator p = s.begin(); // D�clare un it�rateur p de type multiset<int>::iterator et l'initialise au d�but du multiset s

    while (p != s.end()) { // Parcourt le multiset en utilisant l'it�rateur p
        cout << *p++ << " "; // Affiche la valeur point�e par l'it�rateur p (qui est un entier) et incr�mente l'it�rateur p vers l'�l�ment suivant
    }

    return 0; // Indique que le programme s'est ex�cut� avec succ�s
}
