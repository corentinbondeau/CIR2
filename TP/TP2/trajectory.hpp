#include "Point3D.hpp" 

class Trajectory {
private:
    Point3D* points; // Pointeur vers un tableau de points
    size_t nbPoints; // Nombre de points dans la trajectoire

public:
    // Constructeur
    Trajectory(size_t nbPoints);

    // Destructeur
    ~Trajectory();

    // Méthodes
    void print();
    Point3D& getPoint(const int& n);
    float getTotalDistance();
};
