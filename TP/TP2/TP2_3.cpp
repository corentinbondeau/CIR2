#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream fichier("exo3.txt");
    if (!fichier.is_open()) {
        cerr << "Erreur : Impossible d'ouvrir le fichier texte.txt" << endl;
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

    cout << "Nombre de lignes : " << nbLignes << endl;
    cout << "Nombre de mots : " << nbMots << endl;
    cout << "Nombre de lettres : " << nbLettres << endl;

    cout << "Occurrences des lettres :" << endl;
    for (int i = 0; i < 26; i++) {
        cout << static_cast<char>(i + 'a') << ": " << occurrencesLettres[i] << endl;
    }

    return 0;
}
