/*
Likusios Uzd
1.Pridėti pasirinkimą, kurio metu vartotojas šifravimui naudos tik ASCII koduotę vietoj masyve saugomų elementų.
Tam bus reikalinga patobulintas šifravimo/dešifravimo metodas.
2. Localizacija sutvarkyti
*/
#include <iostream>
#include <string>


//char abc[32] = { 'A','Ą','B','C','Č','D','E','Ę','Ė','F','G','H', 'I','Į','Y','J','K','L','M','N','O','P','R','S','Š','T','U','Ų','Ū','V','Z','Ž' };
char abc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

using namespace std;

int findIndex(char c);
string Encrypt(string text, string key, bool useASCII);
string Decrypt(string encrypted, string key, bool useASCII);

int main() {
    bool useASCII;
    string text, key;
    cout << "Norite naudoti ASCII? (1 - taip, 0 - ne): \n";
    cin >> useASCII;
    cin.ignore();
    cout << "Parasykit zody: \n";
    getline(cin, text);
    cout << "Parasykit rakta: \n";
    getline(cin, key);
    string encrypted = Encrypt(text, key, useASCII);
    string decrypted = Decrypt(encrypted, key, useASCII);
    cout << "Pradinis tekstas: " << text << endl;
    cout << "Uzsifruotas tekstas: " << encrypted << endl;
    cout << "Desifruotas tekstas: " << decrypted << endl;
    return 0;
}

int findIndex(char c) {
    for (int i = 0; i < 26; i++) {
        if (abc[i] == c) return i;
    }
    return -1;
}

string Encrypt(string text, string key, bool useASCII = false) {
    if (useASCII) {
        stringstream ss;
        for (char c : text) {
            ss << int(c) << " ";
        }
        return ss.str();
    }
    else {
        string encrypted = "";
        for (int i = 0, j = 0; i < text.length(); i++) {
            char mi = text[i];
            char ki = key[j % key.length()];

            int miIndex = findIndex(mi);
            int kiIndex = findIndex(ki);

            if (miIndex == -1 || kiIndex == -1) continue;
            encrypted += abc[(miIndex + kiIndex) % 26];

            j++;
        }
        return encrypted;
    }
}

string Decrypt(string encrypted, string key, bool useASCII = false) {
    if (useASCII) {
        stringstream ss(encrypted);
        string decrypted;
        int num;
        while (ss >> num) {
            decrypted += char(num);
        }
        return decrypted;
    }
    else {
        string decrypted = "";
        for (int i = 0, j = 0; i < encrypted.length(); i++) {
            char ci = encrypted[i];
            char ki = key[j % key.length()];

            int ciIndex = findIndex(ci);
            int kiIndex = findIndex(ki);

            if (ciIndex == -1 || kiIndex == -1) continue;
            decrypted += abc[(ciIndex - kiIndex + 26) % 26];

            j++;
        }
        return decrypted;
    }
}
