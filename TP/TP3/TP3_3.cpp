#include <iostream>
#include <cmath>

// Classe Point3D (supposée déjà définie)
class Point3D {
public:
    Point3D(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

private:
    double x;
    double y;
    double z;
};

// Classe Point2D (supposée déjà définie)
class Point2D {
public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

// Classe Vecteur
class Vecteur {
public:
    // Constructeurs
    Vecteur(double x = 0, double y = 0, double z = 0) : x(x), y(y), z(z) {}
    Vecteur(const Point3D& p1, const Point3D& p2) : x(p2.getX() - p1.getX()), y(p2.getY() - p1.getY()), z(p2.getZ() - p1.getZ()) {}
    Vecteur(const Point2D& p1, const Point2D& p2) : x(p2.getX() - p1.getX()), y(p2.getY() - p1.getY()), z(0) {}

    // Méthodes
    Vecteur operator+(const Vecteur& other) const {
        return Vecteur(x + other.x, y + other.y, z + other.z);
    }

    Vecteur operator*(double scalar) const {
        return Vecteur(x * scalar, y * scalar, z * scalar);
    }

    bool operator==(const Vecteur& other) const {
        return (x == other.x && y == other.y && z == other.z);
    }

    // Accesseurs
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

private:
    double x;
    double y;
    double z;
};

int main() {
    // Exemples d'utilisation
    Point3D p1(1, 2, 3);
    Point3D p2(4, 5, 6);
    Vecteur v1(p1, p2);

    Point2D p3(1, 2);
    Point2D p4(4, 5);
    Vecteur v2(p3, p4);

    Vecteur v3(2, 3, 4);
    Vecteur v4 = v1 + v3;

    Vecteur v5 = v2 * 2.5;

    std::cout << "Vecteur v1: (" << v1.getX() << ", " << v1.getY() << ", " << v1.getZ() << ")\n";
    std::cout << "Vecteur v2: (" << v2.getX() << ", " << v2.getY() << ", " << v2.getZ() << ")\n";
    std::cout << "Vecteur v4 (v1 + v3): (" << v4.getX() << ", " << v4.getY() << ", " << v4.getZ() << ")\n";
    std::cout << "Vecteur v5 (v2 * 2.5): (" << v5.getX() << ", " << v5.getY() << ", " << v5.getZ() << ")\n";

    if (v1 == v2) {
        std::cout << "Les vecteurs v1 et v2 sont égaux\n";
    }
    else {
        std::cout << "Les vecteurs v1 et v2 ne sont pas égaux\n";
    }

    return 0;
}
