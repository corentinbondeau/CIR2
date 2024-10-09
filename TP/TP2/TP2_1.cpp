#include <iostream>
/*
// Fonction pour multiplier deux nombres
int multiplier(int x, int y) {
    return x * y;
}

int main() {
    int a;
    int b;

    std::cout << "Entrez une valeur : " << std::endl;
    std::cin >> a;

    std::cout << "Entrez une autre valeur : " << std::endl;
    std::cin >> b;

    std::cout << multiplier(a + 1, b + 1) << std::endl;

    return 0;
}
*/

// Fonction constexpr pour multiplier deux nombres
constexpr int multiplier(int x, int y) {
    return x * y;
}

int main() {
    int a;
    int b;

    std::cout << "Entrez une valeur : " << std::endl;
    std::cin >> a;

    std::cout << "Entrez une autre valeur : " << std::endl;
    std::cin >> b;

    // La multiplication est effectuée à la compilation
    std::cout << multiplier(a + 1, b + 1) << std::endl;

    return 0;
}


