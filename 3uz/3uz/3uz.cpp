#include <iostream>
#include <cctype> // C bibliotekos char 
#include <array>

using namespace std;

bool palindrome(int number);
bool arLietuviskaBalse(char raide);
int DBD(int skaicius1, int skaicius2);

int main()
{
	while (true)
	{
		int uzd0, uzd, number;
		char raide;
		int skaicius1, skaicius2;
		cout << "Pradeti (1) baigti (2) ? " << endl;
		cin >> uzd0;

		int dbd;

		if (uzd0 == 1) {

			cout << "Pasirinkite uzduoty 1-3:" << endl;
			cin >> uzd;
			switch (uzd)
			{
			case 1:
				cout << "Irasykite numeri: ";
				cin >> number;

				if (palindrome(number)) {
					cout << "Numeris yra a palindrome." << endl;
				}
				else {
					cout << "Numeris nera palindrome." << endl;
				}
				break;
			case 2:
				cout << "Irasykite raide: ";
				cin >> raide;
				if (arLietuviskaBalse(raide))
				{
					cout << "Ivesta raide yra balse." << endl;
				}
				else
				{
					cout << "Ivesta raide nera balse." << endl;
				}
				break;
			case 3:
				cout << "Įveskite pirmąjį skaičių: ";
				cin >> skaicius1;
				cout << "Įveskite antrąjį skaičių: ";
				cin >> skaicius2;
				dbd = DBD(skaicius1, skaicius2);
				cout << "Didžiausias bendras daliklis: " << dbd << endl;
				break;
			default:
				cout << "Netinkamas pasirinkimas bandyk dar karta" << endl;
			}
		}
		else if (uzd == 2)
		{
			cout << "Ate " << endl;
			break;
		}
		else
		{
			cout << "Nera tokio pasirinkimo " << endl;
			break;
		}
	}

	return 0;
}
bool palindrome(int number) {
	int originalNumber = number;
	int reverseNumber = 0;

	while (number > 0) {
		reverseNumber = reverseNumber * 10 + number % 10;
		number /= 10;
	}

	return originalNumber == reverseNumber;
}
bool arLietuviskaBalse(char raide) {
	const char lietuviskosBalses[] = "AĄEĘĖIĮYOUŲŪ";


	raide = tolower(raide);

	for (char balse : lietuviskosBalses) {
		if (raide == balse) {
			return true;
		}
	}

	return false;
}
int DBD(int skaicius1, int skaicius2) {
	int sum = 0;
	for (int i = 1; i <= skaicius1 && i <= skaicius2; i++) {
		if (skaicius1 % i == 0 && skaicius2 % i == 0) {
			sum = i;
		}
	}
	return sum;
}