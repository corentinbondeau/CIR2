#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fichier("../../exo3.txt");
    if (!fichier.is_open()) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier exo3.txt" << std::endl;
        return 1;
    }

    int nbLignes = 0;
    int nbMots = 0;
    int nbLettres = 0;
    int occurrencesLettres[26] = { 0 }; // Tableau pour compter les occurrences de chaque lettre

    string ligne;
    while (getline(fichier, ligne)) {
        nbLignes++;
        stringstream ss(ligne);
        string mot;
        while (getline(ss, mot, ' ')) {
            nbMots++;
            for (char c : mot) {
                if (isalpha(c)) {
                    nbLettres++;
                    occurrencesLettres[tolower(c) - 'a']++; // Incrémente le compteur pour la lettre correspondante
                }
            }
        }
    }

    fichier.close();

    std::cout << "Nombre de lignes : " << nbLignes << std::endl;
    std::cout << "Nombre de mots : " << nbMots << std::endl;
    std::cout << "Nombre de lettres : " << nbLettres << std::endl;

    std::cout << "Occurrences des lettres :" << std::endl;
    for (int i = 0; i < 26; i++) {
        std::cout << static_cast<char>(i + 'a') << ": " << occurrencesLettres[i] << std:: endl;
    }

    return 0;
}
