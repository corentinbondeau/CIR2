#include <iostream> // Inclut l'en-tête pour les entrées/sorties standard (pour utiliser cout)
#include <set>     // Inclut l'en-tête pour les conteneurs de type set et multiset

using namespace std; // Permet d'utiliser les éléments de l'espace de noms std sans avoir à les préfixer avec std::

int main() {
    int a[] = { 7, 4, 9, 1, 3, 4, 8, 2, 7, 5, 3, 6, 10, 4, 8, 10, 1, 2 }; // Déclare un tableau d'entiers a contenant les valeurs données

    multiset<int> s(&a[0], &a[17]); // Crée un multiset d'entiers nommé s en initialisant avec les éléments du tableau a 
    // à partir de l'adresse du premier élément (&a[0]) jusqu'à l'adresse du 18ème élément (&a[17])

// Le multiset est un conteneur qui stocke des éléments triés et qui permet les doublons.

    multiset<int>::iterator p = s.begin(); // Déclare un itérateur p de type multiset<int>::iterator et l'initialise au début du multiset s

    while (p != s.end()) { // Parcourt le multiset en utilisant l'itérateur p
        cout << *p++ << " "; // Affiche la valeur pointée par l'itérateur p (qui est un entier) et incrémente l'itérateur p vers l'élément suivant
    }

    return 0; // Indique que le programme s'est exécuté avec succès
}
