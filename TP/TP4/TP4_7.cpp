#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>
#include <cctype> // Pour la fonction tolower

using namespace std;

// Fonction pour crypter un mot de passe (simplification pour l'exemple)
string crypterMotDePasse(const string& motDePasse) {
    string motDePasseCrypte = motDePasse;
    for (char& c : motDePasseCrypte) {
        c = tolower(c); // Convertir en minuscule
        c += 3; // D�caler les caract�res de 3 positions
    }
    return motDePasseCrypte;
}

// Fonction pour d�crypter un mot de passe (simplification pour l'exemple)
string decrypterMotDePasse(const string& motDePasseCrypte) {
    string motDePasse = motDePasseCrypte;
    for (char& c : motDePasse) {
        c -= 3; // D�caler les caract�res de 3 positions
        c = toupper(c); // Convertir en majuscule
    }
    return motDePasse;
}

int main(int argc, char* argv[]) {
    // V�rifier les arguments de la ligne de commande
    if (argc < 2) {
        cout << "Erreur : Veuillez sp�cifier un argument ('create' ou 'login')." << endl;
        return 1;
    }

    string mode = argv[1];

    // D�clarer la map pour stocker les utilisateurs
    map<string, string> utilisateurs;

    // Charger les utilisateurs depuis le fichier
    ifstream fichier("utilisateurs.txt");
    if (fichier.is_open()) {
        string ligne;
        while (getline(fichier, ligne)) {
            // Diviser la ligne en username et password crypt�
            size_t position = ligne.find(':');
            string username = ligne.substr(0, position);
            string passwordCrypte = ligne.substr(position + 1);

            // Ajouter l'utilisateur � la map
            utilisateurs[username] = passwordCrypte;
        }
        fichier.close();
    }
    else {
        cout << "Erreur : Impossible d'ouvrir le fichier utilisateurs.txt" << endl;
        return 1;
    }

    // Cr�er un nouvel utilisateur
    if (mode == "create") {
        string username, password, confirmation;
        cout << "Saisir un nom d'utilisateur : ";
        cin >> username;
        cout << "Saisir un mot de passe : ";
        cin >> password;
        cout << "Confirmer le mot de passe : ";
        cin >> confirmation;

        if (password == confirmation) {
            // Crypter le mot de passe
            string passwordCrypte = crypterMotDePasse(password);

            // Ajouter l'utilisateur � la map
            utilisateurs[username] = passwordCrypte;

            // Enregistrer l'utilisateur dans le fichier
            ofstream fichier("utilisateurs.txt", ios::app);
            if (fichier.is_open()) {
                fichier << username << ":" << passwordCrypte << endl;
                fichier.close();
                cout << "Utilisateur cr�� avec succ�s." << endl;
            }
            else {
                cout << "Erreur : Impossible d'ouvrir le fichier utilisateurs.txt" << endl;
            }
        }
        else {
            cout << "Erreur : Les mots de passe ne correspondent pas." << endl;
        }
    }

    // Effectuer l'authentification
    if (mode == "login") {
        string username, password;
        int tentatives = 0;
        while (tentatives < 3) {
            cout << "Saisir un nom d'utilisateur : ";
            cin >> username;
            cout << "Saisir un mot de passe : ";
            cin >> password;

            // V�rifier si l'utilisateur existe
            auto it = utilisateurs.find(username);
            if (it != utilisateurs.end()) {
                // D�crypter le mot de passe stock�
                string passwordCrypte = it->second;
                string passwordDecrypte = decrypterMotDePasse(passwordCrypte);

                // Comparer les mots de passe
                if (password == passwordDecrypte) {
                    cout << "Authentification r�ussie." << endl;
                    return 0;
                }
                else {
                    cout << "Mot de passe incorrect." << endl;
                }
            }
            else {
                cout << "Utilisateur introuvable." << endl;
            }

            tentatives++;
        }
        cout << "Trop de tentatives d'authentification. Fin du programme." << endl;
    }

    return 0;
}
