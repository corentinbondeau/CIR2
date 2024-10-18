#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
    std::vector<int> vec = { 1, -2, 3, -4, 5 };

    // 1. Déterminer si toutes les valeurs sont positives ou nulles
    bool toutesPositives = std::all_of(vec.begin(), vec.end(), [](int val) { return val >= 0; });

    if (toutesPositives) {
        std::cout << "Toutes les valeurs sont positives ou nulles." << std::endl;
    }
    else {
        std::cout << "Il existe des valeurs négatives." << std::endl;
    }

    // 2. Remplacer toutes les valeurs négatives par 0
    std::replace_if(vec.begin(), vec.end(), [](int val) { return val < 0; }, 0);

    // 3. Afficher toutes les valeurs positives
    std::cout << "Valeurs positives : ";
    std::copy_if(vec.begin(), vec.end(), std::ostream_iterator<int>(std::cout, " "), [](int val) { return val > 0; });
    std::cout << std::endl;

    // 4. Déterminer la position du premier et du dernier élément négatif
    auto itPremierNegatif = std::find_if(vec.begin(), vec.end(), [](int val) { return val < 0; });
    auto itDernierNegatif = std::find_if_not(vec.rbegin(), vec.rend(), [](int val) { return val < 0; });

    if (itPremierNegatif != vec.end()) {
        std::cout << "Position du premier élément négatif : " << std::distance(vec.begin(), itPremierNegatif) << std::endl;
    }
    else {
        std::cout << "Aucun élément négatif trouvé." << std::endl;
    }

    if (itDernierNegatif != vec.rend()) {
        std::cout << "Position du dernier élément négatif : " << std::distance(vec.begin(), itDernierNegatif.base() - 1) << std::endl;
    }
    else {
        std::cout << "Aucun élément négatif trouvé." << std::endl;
    }

    return 0;
}
