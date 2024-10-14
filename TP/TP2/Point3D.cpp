#include "Point3D.hpp" // Assurez-vous d'inclure l'en-t�te Point3D.h
#include <iostream>
#include <cstdlib> // Pour rand()
#include <ctime> // Pour srand(time(NULL))

// Constructeur par d�faut (initialise avec des valeurs al�atoires)
Point3D::Point3D() {
    srand(time(NULL)); // Initialisation du g�n�rateur de nombres al�atoires
    x = rand() % 101; // Valeur al�atoire entre 0 et 100
    y = rand() % 101;
    z = rand() % 101;
}

// Constructeur avec param�tres
Point3D::Point3D(const float& newx, const float& newy, const float& newz) :
    x(newx), y(newy), z(newz) {}

// Setters
void Point3D::setXYZ(const float& newx, const float& newy, const float& newz) {
    x = newx;
    y = newy;
    z = newz;
}

void Point3D::setX(const float& newx) {
    x = newx;
}

void Point3D::setY(const float& newy) {
    y = newy;
}

void Point3D::setZ(const float& newz) {
    z = newz;
}

// Getters
float Point3D::getX() {
    return x;
}

float Point3D::getY() {
    return y;
}

float Point3D::getZ() {
    return z;
}

// M�thode pour afficher les coordonn�es
void Point3D::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// M�thode pour calculer la distance � un autre point
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
