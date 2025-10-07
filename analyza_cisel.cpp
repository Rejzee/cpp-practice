#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void vstup(){
    vector<int> zadanaCisla;
    int pocet;
    int cisla;
    cout << "Zadej pocet cisel ktere budes chtit zadat: " << endl;
    cin >> pocet;
    for(int x = 0; x < pocet; x++){
        cout << "Zadej cisla podle poctu: " << endl;
        cin >> cisla;
        zadanaCisla.push_back(cisla);
    }

    int soucet = 0;
    for (int cislo : zadanaCisla){
        soucet += cislo;
    }
    double prumer = (double)soucet / zadanaCisla.size();
    cout << "Soucet: " << soucet << ", Prumer: " << prumer << endl;


        // Max, Min
        int nejmensi = *min_element(zadanaCisla.begin(), zadanaCisla.end());
        cout << "Nejmensi cislo: " << nejmensi << endl;

        int nejvetsi = *max_element(zadanaCisla.begin(), zadanaCisla.end());
        cout << "Nejvetsi cislo: " << nejvetsi << endl;


        // Serazeni
        sort(zadanaCisla.begin(), zadanaCisla.end());
        sort(zadanaCisla.rbegin(), zadanaCisla.rend());

        // Suda, licha
        for(int cislo : zadanaCisla){
            if (cislo %2 == 0){
                cout << cislo << " je sude" << endl;
            } else{
                cout << cislo << " je liche" << endl;
            }
        }
}

int main() {
    vstup();

    return 0;
}