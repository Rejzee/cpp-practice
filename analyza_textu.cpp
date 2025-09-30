#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

void uzivatel(){
    string vstup;
    int pismeno = 0;
    int mezera = 0;
    int cislo = 0;
    int specialniZnak = 0;

    cout << "Zadej random vetu: " << endl;
    getline(cin, vstup);
    for (auto& znak : vstup){
        if (isspace(znak)){
            mezera++;
        } else if (isdigit(znak)){
            cislo++;
        } else if (isalpha(znak)){
            pismeno++;
        }
        else {
            specialniZnak++;
        }
        
    }
        cout << "Pocet mezer: " << mezera << endl;
        cout << "Pocet pismen: " << pismeno << endl;
        cout << "Pocet cisel: " << cislo << endl;
        cout << "Pocet specialnich znaku: " << specialniZnak << endl;

        if (vstup.find("ahoj") != string::npos){
            cout << "Veta obsahuje slovo ahoj" << endl;
        }

    reverse(vstup.rbegin(), vstup.rend());
    cout << "Otocena veta: " << vstup << endl;

}


int main(){
    uzivatel();



    return 0;
}