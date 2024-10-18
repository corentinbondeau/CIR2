#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// Définition de la classe fraction
class Fraction {
public:
    int numérateur;
    int dénominateur;

    // Constructeur
    Fraction(int numérateur, int dénominateur) : numérateur(numérateur), dénominateur(dénominateur) {}

    // Surcharge de l'opérateur < pour la comparaison
    bool operator<(const Fraction& other) const {
        return (numérateur * other.dénominateur) < (other.numérateur * dénominateur);
    }

    // Surcharge de l'opérateur + pour l'addition
    Fraction operator+(const Fraction& other) const {
        return Fraction(numérateur * other.dénominateur + other.numérateur * dénominateur, dénominateur * other.dénominateur);
    }

    // Surcharge de l'opérateur << pour l'affichage
    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.numérateur << "/" << fraction.dénominateur;
        return os;
    }
};

int main() {
    // Ouverture du fichier en lecture
    ifstream fichier("fractions.txt");

    // Vérification de l'ouverture du fichier
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier fractions.txt" << endl;
        return 1;
    }

    // Lecture des fractions du fichier
    vector<Fraction> fractions;
    int numérateur, dénominateur;
    while (fichier >> numérateur >> dénominateur) {
        fractions.push_back(Fraction(numérateur, dénominateur));
    }

    // Fermeture du fichier
    fichier.close();

    // Affichage des fractions dans l'ordre croissant
    sort(fractions.begin(), fractions.end());
    cout << "Fractions triées : " << endl;
    for (const Fraction& fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    // Calcul de la somme totale des fractions
    Fraction somme(0, 1);
    for (const Fraction& fraction : fractions) {
        somme = somme + fraction;
    }
    cout << "Somme totale : " << somme << endl;

    // Suppression des valeurs répétées
    set<Fraction> fractionsUniques(fractions.begin(), fractions.end());
    fractions.assign(fractionsUniques.begin(), fractionsUniques.end());
    cout << "Fractions sans doublons : " << endl;
    for (const Fraction& fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    // Suppression des valeurs négatives
    fractions.erase(remove_if(fractions.begin(), fractions.end(), [](const Fraction& fraction) { return fraction.numérateur < 0; }), fractions.end());
    cout << "Fractions positives : " << endl;
    for (const Fraction& fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    // Affichage de la valeur minimale
    if (!fractions.empty()) {
        cout << "Valeur minimale : " << *min_element(fractions.begin(), fractions.end()) << endl;
    }
    else {
        cout << "Liste vide." << endl;
    }

    // Affichage de la valeur maximale
    if (!fractions.empty()) {
        cout << "Valeur maximale : " << *max_element(fractions.begin(), fractions.end()) << endl;
    }
    else {
        cout << "Liste vide." << endl;
    }

    return 0;
}
