#include <iostream>
#include <cmath>
#include <random>

// Méthode de Monte Carlo
double piMonteCarlo(int iterations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    int pointsInsideCircle = 0;
    for (int i = 0; i < iterations; ++i) {
        double x = dist(gen);
        double y = dist(gen);
        if (x * x + y * y <= 1) {
            pointsInsideCircle++;
        }
    }

    return 4.0 * pointsInsideCircle / iterations;
}

// Somme des inverses des carrés
double piInverseSquares(int terms) {
    double sum = 0;
    for (int i = 1; i <= terms; ++i) {
        sum += 1.0 / (i * i);
    }
    return sqrt(6 * sum);
}

// Calcul de pi à la compilation
constexpr double piCompileTime(int terms) {
    double sum = 0;
    for (int i = 1; i <= terms; ++i) {
        sum += 1.0 / (i * i);
    }
    return sqrt(6 * sum);
}

int main() {
    // Estimation de pi par Monte Carlo
    std::cout << "Estimation de pi par Monte Carlo (1 million d'itérations): " << piMonteCarlo(1000000) << std::endl;

    // Estimation de pi par la somme des inverses des carrés
    std::cout << "Estimation de pi par la somme des inverses des carrés (100 termes): " << piInverseSquares(100) << std::endl;

    // Calcul de pi à la compilation
    constexpr double piValue = piCompileTime(100);
    std::cout << "Calcul de pi à la compilation (100 termes): " << piValue << std::endl;

    return 0;
}
