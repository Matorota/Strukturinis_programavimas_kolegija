/*
Likusios Uzd
1.Pridėti pasirinkimą, kurio metu vartotojas šifravimui naudos tik ASCII koduotę vietoj masyve saugomų elementų.
Tam bus reikalinga patobulintas šifravimo/dešifravimo metodas.
2. Localizacija sutvarkyti
*/
#include <iostream>
#include <string>


//char abc[26] = { 'A','B','C','D','E','F','G','H', 'I','Y','J','K','L','M','N','O','P','R','S','T','U','V','Z' }; // PRIRASYTI
char abc[32] = { 'A','Ą','B','C','Č','D','E','Ę','Ė','F','G','H', 'I','Į','Y','J','K','L','M','N','O','P','R','S','Š','T','U','Ų','Ū','V','Z','Ž' };

using namespace std;

int findIndex(char c, bool useASCII);
string Encrypt(string text, string key, bool useASCII);
string Decrypt(string text, string key, bool useASCII);


int main() {

    setlocale(LC_ALL, "Lithuanian"); // neveikia
    bool useASCII;
    string text;
    cout << "Norite naudoti ASCII koduotæ? (1 - taip, 0 - ne): \n";
    cin >> useASCII;
    cout << "Parasykit zody: \n";
    cin >> text;
    string key;
    cout << "Parasykit rakta: \n";
    cin >> key;
    string encrypted = Encrypt(text, key, useASCII);
    string decrypted = Decrypt(encrypted, key, useASCII);
    cout << "Pradinis tekstas: " << text << endl;
    cout << "Užšifruotas tekstas: " << encrypted << endl;
    cout << "Dešifruotas tekstas: " << decrypted << endl;

    return 0;
}

int findIndex(char c, bool useASCII) {
    if (useASCII) return (int)c;
    for (int i = 0; i < 32; i++) {
        if (abc[i] == c) return i;
    }
    return -1;
}

string Encrypt(string text, string key, bool useASCII = false) {
    int n = useASCII ? 128 : 32;
    string encrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        char mi = text[i];
        char ki = key[j % key.length()];

        int miIndex = findIndex(mi, useASCII);
        int kiIndex = findIndex(ki, useASCII);

        if (miIndex == -1 || kiIndex == -1) continue;

        if (useASCII) {
            encrypted += char((miIndex + kiIndex) % n);
        }
        else {
            encrypted += abc[(miIndex + kiIndex) % n];
        }

        j++;
    }
    return encrypted;
}

string Decrypt(string text, string key, bool useASCII = false) {
    int n = useASCII ? 128 : 32;
    string decrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        char ci = text[i];
        char ki = key[j % key.length()];

        int ciIndex = findIndex(ci, useASCII);
        int kiIndex = findIndex(ki, useASCII);

        if (ciIndex == -1 || kiIndex == -1) continue;

        if (useASCII) {
            decrypted += char((ciIndex - kiIndex + n) % n);
        }
        else {
            decrypted += abc[(ciIndex - kiIndex + n) % n];
        }

        j++;
    }
    return decrypted;
}
