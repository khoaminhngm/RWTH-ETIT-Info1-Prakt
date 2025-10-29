///////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1
//
// Versuch 2.3: Felder
//
// Datei:  Verschuesselung.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

using namespace std;

#include <iostream>
#include <string>

string verschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int length = wort.length();
	int currentLetterPosition;
	int codedLetter;
	string codedWort;

	for (int i = 0; i < length; i++) {
		currentLetterPosition = wort[i] - 'A';
		codedLetter = schluessel[1][currentLetterPosition];
		wort[i] = codedLetter;
	}
	return wort;
}

string entschluesseln(char schluessel[2][26], string wort)
{
	// Hier folgt Ihr Code
	int length = wort.length();
	char currentLetter;
	char decodedLetter;
	string codedWort;

	for (int i = 0; i < length; i++) {
		currentLetter = wort[i];

		for (int j = 0; j < 26; j++) {
			if (currentLetter == schluessel[1][j]) {
				decodedLetter = schluessel[0][j];
			}
		}

		wort[i] = decodedLetter;
	}
	return wort;
}

int main()
{
	// Hier folgt Ihr Code

	// Variablen
	string input;
	string verschluesseltesWort;
	string entschluesseltesWort;

	// Lookup-Tabelle
	char tabelle[2][26] = {
	    { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' },
	    { 'Q', 'W', 'M', 'F', 'K', 'H', 'P', 'E', 'Z', 'B', 'C', 'T', 'V', 'I', 'R', 'J', 'S', 'O', 'X', 'Y', 'U', 'A', 'D', 'N', 'G', 'L' }
	};

	// Input
	cout << "Geben Sie das zu verschlüsselne Wort in Großbuchstaben ein: ";
	cin >> input;

	// Call Function verschluesseln
	verschluesseltesWort = verschluesseln(tabelle, input);
	entschluesseltesWort = entschluesseln(tabelle, verschluesseltesWort);


	cout << "Klartext: " << input << endl;
	cout << "Verschlüsselt: " << verschluesseltesWort << endl;
	cout << "Entschlüsselt: " << entschluesseltesWort << endl;

	return 0;
}
