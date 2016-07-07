#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <limits>

using namespace std;

bool functionSorting(pair<string, double> i, pair<string, double> j);

int main(){

    int counter = 0;
    double moyenne, somme=0.0;

    string matiere;

    vector<pair<string, double> > v;

    pair<string, double> p;

    while (true){

        cout << "Entrer la matière: ";
        getline(cin, matiere);

        cin.clear();

        if (matiere.empty()) break;

        cout << "Entrer la moyenne de " << matiere << ": ";
        cin >> moyenne;

        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

        p.first = matiere;
        p.second = moyenne;

        v.push_back(p);
    }

    sort(v.begin(), v.end(), functionSorting);

    for (int i=0; i!=(int)v.size(); i++, counter++){
        p = v.at(i);
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
