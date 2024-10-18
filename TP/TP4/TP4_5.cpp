#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
    // D�clarer et remplir la map
    map<int, string> mois;
    mois[1] = "Janvier";
    mois[2] = "F�vrier";
    mois[3] = "Mars";
    mois[4] = "Avril";
    mois[5] = "Mai";
    mois[6] = "Juin";
    mois[7] = "Juillet";
    mois[8] = "Ao�t";
    mois[9] = "Septembre";
    mois[10] = "Octobre";
    mois[11] = "Novembre";
    mois[12] = "D�cembre";

    // Imprimer la liste dans l'ordre alphab�tique
    cout << "Mois dans l'ordre alphab�tique : " << endl;
    for (auto it = mois.begin(); it != mois.end(); ++it) {
        cout << it->second << " ";
    }
    cout << endl;

    // Conversion de date
    string date = "31 D�cembre 2014";
    string jour, moisNom, annee;
    stringstream ss(date);
    getline(ss, jour, ' ');
    getline(ss, moisNom, ' ');
    getline(ss, annee, ' ');

    // Trouver le num�ro de mois
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
