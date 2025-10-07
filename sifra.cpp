#include <iostream>
#include <string>
using namespace std;

// Funkce pro šifrování textu
string vigenere_encrypt(string plaintext, string key) {
    string result = "";
    int keyIndex = 0;
    for (int i = 0; i < plaintext.length(); i++) {
        char p = plaintext[i];
        char k = key[keyIndex % key.length()];

        // Pokud je znak písmeno, šifrujeme
        if (isalpha(p)) {
            char base = islower(p) ? 'a' : 'A'; // Určení základního písmena pro malé/velké písmeno
            result += (char)((((p - base) + (tolower(k) - 'a')) % 26) + base);
            keyIndex++;
        } else {
            // Pokud není písmeno, přidáme znak bez změny
            result += p;
        }
    }
    return result;
}

// Funkce pro dešifrování textu
string vigenere_decrypt(string ciphertext, string key) {
    string result = "";
    int keyIndex = 0;
    for (int i = 0; i < ciphertext.length(); i++) {
        char c = ciphertext[i];
        char k = key[keyIndex % key.length()];

        // Pokud je znak písmeno, dešifrujeme
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A'; // Určení základního písmena pro malé/velké písmeno
            result += (char)((((c - base) - (tolower(k) - 'a') + 26) % 26) + base);
            keyIndex++;
        } else {
            // Pokud není písmeno, přidáme znak bez změny
            result += c;
        }
    }
    return result;
}

int main() {
    string text, key;
    int choice;

    cout << "Vigenèrova šifra\n";
    cout << "Zadejte text: ";
    getline(cin, text);
    cout << "Zadejte klíč: ";
    getline(cin, key);

    cout << "Vyberte akci:\n1. Šifrovat\n2. Dešifrovat\n";
    cout << "Vaše volba: ";
    cin >> choice;

    if (choice == 1) {
        cout << "Zašifrovaný text: " << vigenere_encrypt(text, key) << endl;
    } else if (choice == 2) {
        cout << "Dešifrovaný text: " << vigenere_decrypt(text, key) << endl;
    } else {
        cout << "Neplatná volba.\n";
    }

    return 0;
}
