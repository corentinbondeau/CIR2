#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    // Ouvrir le fichier contenant le texte
    ifstream fichier("texte.txt");
    if (!fichier.is_open()) {
        cout << "Erreur : Impossible d'ouvrir le fichier texte.txt" << endl;
        return 1;
    }

    // D�clarer les maps pour les lettres et les mots
    map<char, int> occurrencesLettres;
    map<string, int> occurrencesMots;

    // Lire le texte caract�re par caract�re
    char caractere;
    string mot;
    while (fichier.get(caractere)) {
        // Convertir en minuscule et supprimer les s�parateurs et ponctuations
        caractere = tolower(caractere);
        if (isalpha(caractere)) {
            // Compter les occurrences des lettres
            occurrencesLettres[caractere]++;

            // Construire le mot
            mot += caractere;
        }
        else if (!mot.empty()) {
            // Compter les occurrences des mots
            occurrencesMots[mot]++;
            mot.clear();
        }
    }

    // Fermer le fichier
    fichier.close();

    // Afficher les r�sultats dans l'ordre alphab�tique
    cout << "Occurrences des lettres (ordre alphab�tique) :" << endl;
    for (auto it = occurrencesLettres.begin(); it != occurrencesLettres.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Occurrences des mots (ordre alphab�tique) :" << endl;
    for (auto it = occurrencesMots.begin(); it != occurrencesMots.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    // Afficher les r�sultats dans l'ordre d'apparition
    cout << "Occurrences des lettres (ordre d'apparition) :" << endl;
    for (auto it = occurrencesLettres.begin(); it != occurrencesLettres.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    cout << "Occurrences des mots (ordre d'apparition) :" << endl;
    for (auto it = occurrencesMots.begin(); it != occurrencesMots.end(); ++it) {
        cout << it->first << ": " << it->second << endl;
    }

    return 0;
}
