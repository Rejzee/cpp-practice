#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <set>
#include <climits>
#include <numeric>
using namespace std;


string samohlasky = "aeiouAEIOU";

bool jeSamohlaska(char c) {
    return samohlasky.find(c) != string::npos;
}

void uzivatel(){
    int pocet;
    string slova;
    vector<string> vypsaneSlova;
    cout << "Zadej kolik chces slov" << endl;
    cin >> pocet;
    for (int x = 0; x < pocet; x++){
            cout << "Zadej slova podle poctu kolik si napsal" << endl;
            cin >> slova;
            vypsaneSlova.push_back(slova);
    }


    for (auto &word : vypsaneSlova) {
        int pocetSamohlasek = 0;
        int pocetSouhlasek = 0;

        for (char c : word){
            if(jeSamohlaska(c)){
                pocetSamohlasek++;
            } else {
                    pocetSouhlasek++;
            }
        }

        cout << word << " -> samohlasky: " << pocetSamohlasek << " souhlasky: " << pocetSouhlasek << endl;

    }

}

int main() {
    uzivatel();




    return 0;
}