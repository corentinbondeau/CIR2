#include <iostream>
#include <vector>
#include <iterator>

template<typename Iter>
typename Iter::value_type
partial_dot(Iter first1, Iter last1, Iter first2, Iter last2) {
    typename Iter::value_type sum = 0;

    // Vérification que les deux conteneurs ont la même taille
    if (std::distance(first1, last1) != std::distance(first2, last2)) {
        std::cerr << "Erreur : Les conteneurs n'ont pas la même taille." << std::endl;
        return sum; // Retourne 0 si les tailles sont différentes
    }

    // Calcul du produit scalaire
    while (first1 != last1) {
        sum += *first1 * *first2;
        ++first1;
        ++first2;
    }

    return sum;
}

int main() {
    std::vector<int> v1 = { 1, 2, 3, 4 };
    std::vector<int> v2 = { 5, 6, 7, 8 };

    int dot_product = partial_dot(v1.begin(), v1.end(), v2.begin(), v2.end());

    std::cout << "Produit scalaire : " << dot_product << std::endl;

    return 0;
}
