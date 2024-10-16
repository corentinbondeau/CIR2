#include <iostream>
#include <cmath>
#include <random>

// Classe Point2D
class Point2D {
public:
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

// Classe Shape (abstraite)
class Shape {
public:
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
};

// Classe Circle (dérive de Shape)
class Circle : public Shape {
public:
    Circle(const Point2D& center, double radius) : center(center), radius(radius) {}
    double getArea() const override { return M_PI * radius * radius; }
    void draw() const override {
        std::cout << "Cercle de rayon " << radius << " centré en (" << center.getX() << ", " << center.getY() << ")\n";
    }

private:
    Point2D center;
    double radius;
};

// Classe Rectangle (dérive de Shape)
class Rectangle : public Shape {
public:
    Rectangle(const Point2D& topLeft, const Point2D& bottomRight) : topLeft(topLeft), bottomRight(bottomRight) {}
    double getArea() const override {
        double width = bottomRight.getX() - topLeft.getX();
        double height = topLeft.getY() - bottomRight.getY();
        return width * height;
    }
    void draw() const override {
        std::cout << "Rectangle de coin supérieur gauche (" << topLeft.getX() << ", " << topLeft.getY() << ") et coin inférieur droit (" << bottomRight.getX() << ", " << bottomRight.getY() << ")\n";
    }

private:
    Point2D topLeft;
    Point2D bottomRight;
};

// Classe Triangle (dérive de Shape)
class Triangle : public Shape {
public:
    Triangle(const Point2D& point1, const Point2D& point2, const Point2D& point3) : point1(point1), point2(point2), point3(point3) {}
    double getArea() const override {
        // Formule de Héron pour l'aire d'un triangle
        double a = distance(point1, point2);
        double b = distance(point2, point3);
        double c = distance(point3, point1);
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
    void draw() const override {
        std::cout << "Triangle de points (" << point1.getX() << ", " << point1.getY() << "), (" << point2.getX() << ", " << point2.getY() << "), (" << point3.getX() << ", " << point3.getY() << ")\n";
    }

private:
    Point2D point1;
    Point2D point2;
    Point2D point3;

    // Fonction auxiliaire pour calculer la distance entre deux points
    double distance(const Point2D& p1, const Point2D& p2) const {
        return sqrt(pow(p1.getX() - p2.getX(), 2) + pow(p1.getY() - p2.getY(), 2));
    }
};

int main() {
    // Création d'objets Shape
    Point2D center(2, 3);
    Circle circle(center, 5);
    Point2D topLeft(1, 4);
    Point2D bottomRight(6, 1);
    Rectangle rectangle(topLeft, bottomRight);
    Point2D point1(0, 0);
    Point2D point2(5, 0);
    Point2D point3(2, 4);
    Triangle triangle(point1, point2, point3);

    // Affichage des informations des formes
    std::cout << "Affichage des formes:\n";
    circle.draw();
    std::cout << "Aire du cercle: " << circle.getArea() << std::endl;
    rectangle.draw();
    std::cout << "Aire du rectangle: " << rectangle.getArea() << std::endl;
    triangle.draw();
    std::cout << "Aire du triangle: " << triangle.getArea() << std::endl;

    return 0;
}
