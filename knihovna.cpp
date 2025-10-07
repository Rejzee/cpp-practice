#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Kniha {
    string nazev;
    string autor;
    int rokVydani;
    bool vypujcena = false;
};

vector<Kniha> knihovna;

void pridatKnihu(){
    Kniha novaKniha;

    cout << "Zadej nazev knihy" << endl;
    cin >> novaKniha.nazev;

    cout << "Zadej nazev autora: " << endl;
    cin >> novaKniha.autor;

    cout << "Zadej rok vydani: " << endl;
    cin >> novaKniha.rokVydani;

    cout << "Kniha: " << novaKniha.nazev << " byla pridana do knihovny." << endl;
    knihovna.push_back(novaKniha);
}

void vypsaniKnih(){

    if (knihovna.empty()){
        cout << "Knihovna je prazdna" << endl;
        return;
    }
    cout << "---- LIST KNIHY ----" << endl;
    for (auto &kniha : knihovna){
    cout << "Nazev: " << kniha.nazev << endl;
    }
}

void vyhledatKnihu(){
    string hledam;
    cout << "Zadej knihu kterou chces najit: " << endl;
    cin >> hledam;

    for (auto &kniha : knihovna){
        if (kniha.nazev == hledam) {
            cout << "Hledany ucet byl nalezen." << endl;
            return;
        } 
    }
    cout << "Kniha nebyla nalezena." << endl;
}

bool pujcitKnihu(string nazev){
    for (auto &kniha : knihovna){
        if(kniha.nazev == nazev) {
            if (kniha.vypujcena){
                cout << "Kniha uz je pujcena." << endl;
                return false;
            }
            cout << "Kniha byla uspesne vypujcena." << endl;
            kniha.vypujcena = true;
            return true;
        }
    }
    // not found
    return false;
}

bool vratitKnihu(string nazev){
    for (auto &kniha : knihovna){
        if(kniha.nazev == nazev){
            if(!kniha.vypujcena){
                return true;
            }
            kniha.vypujcena = false;
            return true;
        }
    }
    // not found
    return false;

}


void menu(){
    cout << "\n--- MENU KNIHOVNY ---\n";
        cout << "1. Pridat knihu\n";
        cout << "2. Vypsat knihy\n";
        cout << "3. Vyhledat knihu\n";
        cout << "4. Pujcit knihu\n";
        cout << "5. Vratit knihu\n";
        cout << "0. Konec\n";
        cout << "Vyber akci: ";
}
int main() {
    int volba;
    string nazev;

    do{
        menu();
        cin >> volba;

        switch (volba){
            case 1:
            pridatKnihu();
            break;
            case 2:
            vypsaniKnih();
            break;
            case 3:
            vyhledatKnihu();
            break;
            case 4:
            cout << "Zadej nazev knihy k pujceni: " << endl;
            cin >> nazev;
            if(pujcitKnihu(nazev)){
                cout << "Kniha byla pujcena" << endl;
            } else{
                cout << "Knihu se nepodarilo najit" << endl;
            }
            break;
            case 5:
            cout << "Zadej nazev knihy k vraceni: " << endl;
            if(vratitKnihu(nazev)){
                cout << "Kniha byla vracena" << endl;
            }else{
                cout << "Knihu se nepodarilo vratit" << endl;
            }
            case 0:
            cout << "Ukoncuji program." << endl;
            break;
            default:
            cout << "Neplatna volba" << endl;
             
        }
    } while (volba != 0);

    return 0;
}
