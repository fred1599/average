#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

bool functionSorting(pair<string, double> i, pair<string, double> j);

int main(){

    string matiere;
    double moyenne;
    vector<pair<string, double> > v;
    double somme = 0;
    int counter = 0;

    while (true){

        cout << "Entrer la matière: ";
        cin >> matiere;

        cout << "Entrer la moyenne de " << matiere << ": ";
        cin >> moyenne;

        if (moyenne == -1) break; // Pour sortir de la boucle infinie

        pair<string, double> infos;
        infos.first = matiere;
        infos.second = moyenne;

        v.push_back(infos);
    }

    sort(v.begin(), v.end(), functionSorting);

    for (int i=0; i!=(int)v.size(); i++, counter++){
        pair<string, double> p = v.at(i);
        somme += p.second;
        cout << p.first << ": " << p.second << endl;
    }

    moyenne = somme/counter;

    cout << "La moyenne est de: " << moyenne << endl;

    return 1;
}

bool functionSorting(pair<string, double> i, pair<string, double> j){

    return i.second < j.second;
}
