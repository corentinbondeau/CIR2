#include <iostream>
#include <fstream>
#include <map>
#include <string>

using namespace std;

int main() {
    // D�clarer la map pour stocker les acronymes et leurs significations
    map<string, string> acronymes;

    // Charger la liste initiale des acronymes depuis un fichier
    ifstream fichier("acronymes.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne)) {
            // Diviser la ligne en acronyme et d�finition
            size_t position = ligne.find('=');
            string acronyme = ligne.substr(0, position);
            string definition = ligne.substr(position + 1);

            // Ajouter l'acronyme et sa d�finition � la map
            acronymes[acronyme] = definition;
        }
        fichier.close();
    }
    else {
        cout << "Erreur : Impossible d'ouvrir le fichier acronymes.txt" << endl;
    }

    // Boucle principale pour la saisie des acronymes
    string saisie;
    while (true) {
        cout << "Saisir un acronyme (ou 'fin' pour terminer) : ";
        cin >> saisie;

        // V�rifier si l'utilisateur veut terminer
        if (saisie == "fin") {
            break;
        }

        // V�rifier si l'acronyme est dans la map
        auto it = acronymes.find(saisie);
        if (it != acronymes.end()) {
            cout << "Signification : " << it->second << endl;
        }
        else {
            cout << "Acronyme inconnu. Veuillez saisir la signification : ";
            cin.ignore(); // Ignorer le caract�re de nouvelle ligne restant dans le tampon
            getline(cin, saisie);
            acronymes[saisie] = saisie;
            cout << "Acronyme ajout�." << endl;
        }
    }

    return 0;
}
