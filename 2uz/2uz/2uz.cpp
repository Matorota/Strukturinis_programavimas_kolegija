/*
Likusios Uzd
1.Pridëti pasirinkimà, kurio metu vartotojas ðifravimui naudos tik ASCII koduotæ vietoj masyve saugomø elementø.
Tam bus reikalinga patobulintas ðifravimo/deðifravimo metodas.
2. Localizacija sutvarkyti
*/
#include <iostream>
#include <string>
//#include <fcntl.h>
//#include <io.h>

char abc[32] = { 'A','À','B','C','È','D','E','Æ','Ë','F','G','H', 'I','Á','Y','J','K','L','M','N','O','P','R','S','Ð','T','U','Ø','Û','V','Z','Þ' };

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
    string key = "KEY";
    
    string encrypted = Encrypt(text, key, useASCII);
    string decrypted = Decrypt(encrypted, key, useASCII);

    cout << "Pradinis tekstas: " << text << endl;
    cout << "Uþðifruotas tekstas: " << encrypted << endl;
    cout << "Deðifruotas tekstas: " << decrypted << endl;

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