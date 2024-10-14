#include <iostream>
#include "Trajectory.hpp"

int main() {
    // Créer une trajectoire avec 5 points
    Trajectory trajectory(5);

    // Afficher les coordonnées des points initiaux (aléatoires)
    std::cout << "Points initiaux de la trajectoire :" << std::endl;
    trajectory.print();

    // Modifier les coordonnées du point 2
    trajectory.getPoint(2).setXYZ(10.0f, 20.0f, 30.0f);

    // Afficher les coordonnées des points après modification
    std::cout << "\nPoints de la trajectoire après modification :" << std::endl;
    trajectory.print();

    // Calculer et afficher la distance totale
    float distanceTotale = trajectory.getTotalDistance();
    std::cout << "\nDistance totale de la trajectoire : " << distanceTotale << std::endl;

    return 0;
}
