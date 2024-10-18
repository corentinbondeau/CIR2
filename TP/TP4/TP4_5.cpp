#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // Déclarer et remplir la map
    map<int, string> mois;
    mois[1] = "Janvier";
    mois[2] = "Février";
    mois[3] = "Mars";
    mois[4] = "Avril";
    mois[5] = "Mai";
    mois[6] = "Juin";
    mois[7] = "Juillet";
    mois[8] = "Août";
    mois[9] = "Septembre";
    mois[10] = "Octobre";
    mois[11] = "Novembre";
    mois[12] = "Décembre";

    // Imprimer la liste dans l'ordre alphabétique
    cout << "Mois dans l'ordre alphabétique : " << endl;
    for (auto it = mois.begin(); it != mois.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;

    // Conversion de date
    string date = "31 Décembre 2014";
    string jour, moisNom, annee;
    stringstream ss(date);
    getline(ss, jour, ' ');
    getline(ss, moisNom, ' ');
    getline(ss, annee, ' ');

    // Trouver le numéro de mois
    int moisNum = 0;
    for (auto it = mois.begin(); it != mois.end(); ++it) {
        if (it->second == moisNom) {
            moisNum = it->first;
            break;
        }
    }

    // Formater la date
    string dateConverti = jour + "/" + to_string(moisNum) + "/" + annee;
    cout << "Date convertie : " << dateConverti << endl;

    return 0;
}
