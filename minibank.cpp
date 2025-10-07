#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

struct Account {
    string name;
    int balance;

};
vector<Account> accounts;


void pridaniUctu() {
        Account novy;
        cout << "Nastav jmeno uzivatele: " << endl;
        cin >> novy.name;

        cout << "Nastav balance: " << endl;
        cin >> novy.balance;
        accounts.push_back(novy);
        cout << "Ucet byl pridan" << endl;

}

void vkladvyberPenez(){
    if (accounts.empty()) {
        cout << "Zadne ucty nejsou vytvoreny." << endl;
        return;
    }

    string jmeno;
    cout << "Zadej jmeno uctu: ";
    cin >> jmeno;

    
    for (auto &ucet : accounts) {
        if (ucet.name == jmeno) {
            int vyber;
            cout << "1. Vklad" << endl;
            cout << "2. Vyber" << endl;
            cin >> vyber;

            int castka;
            if (vyber == 1) {
                cout << "Zadej castku k vlozeni: ";
                cin >> castka;
                ucet.balance += castka;
                cout << "Vlozeno " << castka << " na ucet." << endl;
            } else if (vyber == 2) {
                cout << "Zadej castku k vybrani: ";
                cin >> castka;
                if (ucet.balance - castka < 0) {
                    cout << "Nelze jit do minusu!" << endl;
                } else {
                    ucet.balance -= castka;
                    cout << "Vybrano " << castka << " z uctu." << endl;
                }
            }
            return;
        }
    }
    cout << "Ucet nenalezen." << endl;
}


void vypsaniUctu(){

    if(accounts.empty()){
        cout << "Zadne ucty nejsou vytvoreny" << endl;
        return;
    }

    cout << "---- SEZNAM UCTU ----" << endl;
    for (auto &ucet : accounts){
        cout << "Jmeno uctu: " << ucet.name << endl;
    }
}

void hledaniUctuPodleJmena(){
    string hledac;
    cout << "Zadej jmeno uctu ktere chces najit: ";
    cin >> hledac;

    for (auto &ucet : accounts){
        if (ucet.name == hledac){
            cout << "Hledany ucet byl nalezen: " << ucet.name 
                 << " ma " << ucet.balance << endl;
            return;
        }
    }
    cout << "Hledany ucet neexistuje" << endl;
}

int vyber(){
    int vyber;
    cout << "Vyber si co chces s uctem delat: " << endl;
    cout << "--------------------------------" << endl;
    cout << "1. Pridani uctu" << endl;
    cout << "2. Vklad/vyber penez" << endl;
    cout << "3. Vypsani vsech uctu se zustatkem" << endl;
    cin >> vyber;
    switch(vyber){
        case 1:
            pridaniUctu();
            break;
        case 2:
            vkladvyberPenez();
            break;
        case 3:
            vypsaniUctu();
            break;
        case 0:
            return 0;
        default:
            cout << "Neplatna volba. Zadej 0 pro ukonceni" << endl;
    }
    return 1;
}

int main() {
    while(true){
        if(vyber() == 0) break;
    }

    return 0;
}