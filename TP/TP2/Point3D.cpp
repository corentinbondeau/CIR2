#include "Point3D.hpp" // Assurez-vous d'inclure l'en-tête Point3D.h
#include <iostream>
#include <cstdlib> // Pour rand()
#include <ctime> // Pour srand(time(NULL))

// Constructeur par défaut (initialise avec des valeurs aléatoires)
Point3D::Point3D() {
    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires
    x = rand() % 101; // Valeur aléatoire entre 0 et 100
    y = rand() % 101;
    z = rand() % 101;
}

// Constructeur avec paramètres
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

// Méthode pour afficher les coordonnées
void Point3D::print() {
    std::cout << "(" << x << ", " << y << ", " << z << ")" << std::endl;
}

// Méthode pour calculer la distance à un autre point
float Point3D::distanceTo(const Point3D& otherPoint3D) {
    float dx = x - otherPoint3D.x;
    float dy = y - otherPoint3D.y;
    float dz = z - otherPoint3D.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
