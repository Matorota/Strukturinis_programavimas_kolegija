/*
Likusios Uzd
1.Prid�ti pasirinkim�, kurio metu vartotojas �ifravimui naudos tik ASCII koduot� vietoj masyve saugom� element�.
Tam bus reikalinga patobulintas �ifravimo/de�ifravimo metodas.
2. Localizacija sutvarkyti
*/
#include <iostream>
#include <string>
//#include <fcntl.h>
//#include <io.h>

char abc[32] = { 'A','�','B','C','�','D','E','�','�','F','G','H', 'I','�','Y','J','K','L','M','N','O','P','R','S','�','T','U','�','�','V','Z','�' };

using namespace std;


int findIndex(char c, bool useASCII);
string Encrypt(string text, string key, bool useASCII);
string Decrypt(string text, string key, bool useASCII);


int main() {

    setlocale(LC_ALL, "Lithuanian"); // neveikia
    bool useASCII;
    string text;
    cout << "Norite naudoti ASCII koduot�? (1 - taip, 0 - ne): \n";
    cin >> useASCII;
    cout << "Parasykit zody: \n";
    cin >> text;
    string key = "KEY";
    
    string encrypted = Encrypt(text, key, useASCII);
    string decrypted = Decrypt(encrypted, key, useASCII);

    cout << "Pradinis tekstas: " << text << endl;
    cout << "U��ifruotas tekstas: " << encrypted << endl;
    cout << "De�ifruotas tekstas: " << decrypted << endl;

    return 0;
}

int findIndex(char c, bool useASCII) {
    //cout << useASCII;
    if (useASCII) return(int)c;
    for (int i = 0; i < 32; i++) {
        if (abc[i] == c) return i;

    }
    return -1;
}

string Encrypt(string text, string key, bool useASCII = false) {
    int n = 32;
    string encrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        int miIndex = findIndex(text[i], useASCII);
        int kiIndex = findIndex(key[j % key.length()], useASCII);

        if (miIndex == -1 || kiIndex == -1) continue;

        encrypted += abc[(miIndex + kiIndex) % n];
        j++;
    }
    return encrypted;
}

string Decrypt(string text, string key, bool useASCII) {
    int n = 32;
    string decrypted = "";
    for (int i = 0, j = 0; i < text.length(); i++) {
        int ciIndex = findIndex(text[i], useASCII);
        int kiIndex = findIndex(key[j % key.length()], useASCII);

        if (ciIndex == -1 || kiIndex == -1) continue;

        decrypted += abc[(ciIndex - kiIndex + n) % n];
        j++;
    }
    return decrypted;
}