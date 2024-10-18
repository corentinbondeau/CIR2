#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// D�finition de la classe fraction
class Fraction {
public:
    int num�rateur;
    int d�nominateur;

    // Constructeur
    Fraction(int num�rateur, int d�nominateur) : num�rateur(num�rateur), d�nominateur(d�nominateur) {}

    // Surcharge de l'op�rateur < pour la comparaison
    bool operator<(const Fraction& other) const {
        return (num�rateur * other.d�nominateur) < (other.num�rateur * d�nominateur);
    }

    // Surcharge de l'op�rateur + pour l'addition
    Fraction operator+(const Fraction& other) const {
        return Fraction(num�rateur * other.d�nominateur + other.num�rateur * d�nominateur, d�nominateur * other.d�nominateur);
    }

    // Surcharge de l'op�rateur << pour l'affichage
    friend ostream& operator<<(ostream& os, const Fraction& fraction) {
        os << fraction.num�rateur << "/" << fraction.d�nominateur;
        return os;
    }
};

int main() {
    // Ouverture du fichier en lecture
    ifstream fichier("fractions.txt");

    // V�rification de l'ouverture du fichier
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier fractions.txt" << endl;
        return 1;
    }

    // Lecture des fractions du fichier
    vector<Fraction> fractions;
    int num�rateur, d�nominateur;
    while (fichier >> num�rateur >> d�nominateur) {
        fractions.push_back(Fraction(num�rateur, d�nominateur));
    }

    // Fermeture du fichier
    fichier.close();

    // Affichage des fractions dans l'ordre croissant
    sort(fractions.begin(), fractions.end());
    cout << "Fractions tri�es : " << endl;
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

    // Suppression des valeurs r�p�t�es
    set<Fraction> fractionsUniques(fractions.begin(), fractions.end());
    fractions.assign(fractionsUniques.begin(), fractionsUniques.end());
    cout << "Fractions sans doublons : " << endl;
    for (const Fraction& fraction : fractions) {
        cout << fraction << " ";
    }
    cout << endl;

    // Suppression des valeurs n�gatives
    fractions.erase(remove_if(fractions.begin(), fractions.end(), [](const Fraction& fraction) { return fraction.num�rateur < 0; }), fractions.end());
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
