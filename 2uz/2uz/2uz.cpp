#include <iostream>
#include <string>

char abc[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

using namespace std;

int findIndex(char c, bool useASCII);
char findCharacter(int index, bool useASCII);
string Encrypt(string text, string key, bool useASCII);
string Decrypt(string text, string key, bool useASCII);

int main() {
    bool useASCII;
    string text;
    cout << "Norite naudoti ASCII? (1 - taip, 0 - ne): \n";
    cin >> useASCII;
    cout << "Parasykit zody: \n";
    cin >> text;
    string key;
    cout << "Parasykit rakta: \n";
    cin >> key;
    string encrypted = Encrypt(text, key, useASCII);
    string decrypted = Decrypt(encrypted, key, useASCII);
    cout << "Pradinis tekstas: " << text << endl;
    cout << "Uzsifruotas tekstas: " << encrypted << endl;
    cout << "Desifruotas tekstas: " << decrypted << endl;

    return 0;
}

int findIndex(char c, bool useASCII) {
    if (!useASCII) {
        for (int i = 0; i < 26; i++) {
            if (abc[i] == c) return i;
        }
        return -1;
    }
    else {
        return (c >= 'A' && c <= 'Z') ? c - 'A' : -1;
    }
}

char findCharacter(int index, bool useASCII) {
    if (!useASCII) {
        return (index >= 0 && index < 26) ? abc[index] : -1;
    }
    else {
        return (index >= 0 && index < 26) ? 'A' + index : -1;
    }
}

string Encrypt(string text, string key, bool useASCII = false) {
    int n = 26;  
    string encrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        char mi = text[i];
        char ki = key[j % key.length()];

        int miIndex = findIndex(mi, useASCII);
        int kiIndex = findIndex(ki, useASCII);

        if (miIndex == -1 || kiIndex == -1) continue;

        encrypted += findCharacter((miIndex + kiIndex) % n, useASCII);
        j++;
    }
    return encrypted;
}

string Decrypt(string text, string key, bool useASCII = false) {
    int n = 26;
    string decrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        char ci = text[i];
        char ki = key[j % key.length()];

        int ciIndex = findIndex(ci, useASCII);
        int kiIndex = findIndex(ki, useASCII);

        if (ciIndex == -1 || kiIndex == -1) continue;

        decrypted += findCharacter((ciIndex - kiIndex + n) % n, useASCII);
        j++;
    }
    return decrypted;
}