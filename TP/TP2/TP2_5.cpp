#include <iostream>
#include "Trajectory.hpp"

int main() {
    // Cr�er une trajectoire avec 5 points
    Trajectory trajectory(5);

    // Afficher les coordonn�es des points initiaux (al�atoires)
    std::cout << "Points initiaux de la trajectoire :" << std::endl;
    trajectory.print();

    // Modifier les coordonn�es du point 2
    trajectory.getPoint(2).setXYZ(10.0f, 20.0f, 30.0f);

    // Afficher les coordonn�es des points apr�s modification
    std::cout << "\nPoints de la trajectoire apr�s modification :" << std::endl;
    trajectory.print();

    // Calculer et afficher la distance totale
    float distanceTotale = trajectory.getTotalDistance();
    std::cout << "\nDistance totale de la trajectoire : " << distanceTotale << std::endl;

    return 0;
}
