#include <iostream>
#include <cmath>

// Classe Point (suppos�e d�j� d�finie)
class Point {
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }

private:
    double x;
    double y;
};

// Classe Polygon
class Polygon {
public:
    Polygon(const Point* points, int numPoints) : numPoints(numPoints) {
        vertices = new Point[numPoints + 1]; // +1 pour cl�turer le polygone
        for (int i = 0; i < numPoints; ++i) {
            vertices[i] = points[i];
        }
        vertices[numPoints] = points[0]; // Cl�ture du polygone
    }

    double getArea() const {
        double area = 0;
        for (int i = 0; i < numPoints; ++i) {
            area += vertices[i].getX() * vertices[i + 1].getY() - vertices[i + 1].getX() * vertices[i].getY();
        }
        return abs(area) / 2; // Aire positive
    }

    ~Polygon() {
        delete[] vertices;
    }

private:
    Point* vertices;
    int numPoints;
};

int main() {
    // Triangle
    Point trianglePoints[] = {
        Point(0, 0),
        Point(3, 0),
        Point(1.5, 2.5)
    };
    Polygon triangle(trianglePoints, 3);
    std::cout << "Aire du triangle: " << triangle.getArea() << std::endl;

    // Carr�
    Point squarePoints[] = {
        Point(0, 0),
        Point(2, 0),
        Point(2, 2),
        Point(0, 2)
    };
    Polygon square(squarePoints, 4);
    std::cout << "Aire du carr�: " << square.getArea() << std::endl;

    // Rectangle
    Point rectanglePoints[] = {
        Point(0, 0),
        Point(4, 0),
        Point(4, 1.5),
        Point(0, 1.5)
    };
    Polygon rectangle(rectanglePoints, 4);
    std::cout << "Aire du rectangle: " << rectangle.getArea() << std::endl;

    return 0;
}
