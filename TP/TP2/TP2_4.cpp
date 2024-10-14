#include <iostream>
#include "Point3D.hpp"

int main() {
    // Cr�er un point avec des valeurs al�atoires
    Point3D point1;
    std::cout << "Point 1 (al�atoire): ";
    point1.print();

    // Cr�er un point avec des valeurs d�finies
    Point3D point2(5.0f, 10.0f, 15.0f);
    std::cout << "Point 2 (d�fini): ";
    point2.print();

    // Modifier les coordonn�es de point1
    point1.setXYZ(2.0f, 4.0f, 6.0f);
    std::cout << "Point 1 (modifi�): ";
    point1.print();

    // Calculer la distance entre les deux points
    float distance = point1.distanceTo(point2);
    std::cout << "Distance entre point1 et point2: " << distance << std::endl;

    return 0;
}
