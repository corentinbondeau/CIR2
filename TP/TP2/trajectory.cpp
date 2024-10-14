#include "trajectory.hpp"
#include <iostream>
#include <cmath>

// Constructeur
Trajectory::Trajectory(size_t nbPoints) : nbPoints(nbPoints) { // Initialisation de nbPoints
    points = new Point3D[nbPoints]; // Allocation dynamique du tableau
}

// Destructeur
Trajectory::~Trajectory() {
    delete[] points; // Lib�ration de la m�moire allou�e
}

// M�thode pour afficher les coordonn�es de tous les points
void Trajectory::print() {
    for (size_t i = 0; i < nbPoints; ++i) { // Utilisation de nbPoints
        std::cout << "Point " << i << ": ";
        points[i].print();
    }
}

// M�thode pour obtenir la r�f�rence d'un point
Point3D& Trajectory::getPoint(const int& n) {
    if (n >= 0 && n < nbPoints) { // Utilisation de nbPoints
        return points[n];
    }
    else {
        std::cerr << "Erreur : Index de point invalide." << std::endl;
        // Vous pouvez choisir de retourner une r�f�rence � un point "fictif" ou de lever une exception
        return points[0]; // Retourne le premier point par d�faut
    }
}

// M�thode pour calculer la distance totale
float Trajectory::getTotalDistance() {
    float distanceTotale = 0.0f;
    for (size_t i = 1; i < nbPoints; ++i) { // Utilisation de nbPoints
        distanceTotale += points[i].distanceTo(points[i - 1]);
    }
    return distanceTotale;
}
