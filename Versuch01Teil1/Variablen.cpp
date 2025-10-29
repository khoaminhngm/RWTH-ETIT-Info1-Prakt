//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int iErste = 0;
    int iZweite = 0;
    
    // Hier folgt Ihr eigener Code
    
    // Variable Declaration
	int iSumme;
	int iQuotient;
	double dSumme;
	double dQuotient;
	double dErste;
	double dZweite;
	double dSummeCast;
	double dQuotientCast;

	// Input
	cout << "Geben Sie eine ganze Zahl ein: ";
	cin >> iErste;
	cout << "Geben Sie eine zweite ganze Zahl ein: ";
	cin >> iZweite;

	// Calculation (Integer output)
	iSumme = iErste + iZweite;
	iQuotient = iErste / iZweite;

	// Calculation (Double output)
	dSumme = iErste + iZweite;
	dQuotient = static_cast<double>(iErste) / iZweite;

	// Type Casting + Calculation
	dErste = static_cast<double>(iErste);
	dZweite = static_cast<double>(iZweite);
	dSummeCast = dErste + dZweite;
	dQuotientCast = dErste / dZweite;

	// Output
	cout << "Die Summe ist: " << iSumme << endl;
	cout << "Das Ergebnis der Division ist: " << iQuotient << endl;
	cout << "Nun als double:\n";
	cout << "Summe (double): " << dSumme << endl;
	cout << "Quotient (double): " << dQuotient << endl;
	cout << "Mit Typecasting:\n";
	cout << "Summe (cast): " << dSummeCast << endl;
	cout << "Quotient (cast): " << dQuotientCast << endl;
	cout << "Hinweis: Ohne Typecasting geht bei der Division als int der Nachkommateil verloren.\n";

	// Namen eingeben
	string sVorname, sNachname, sVornameName, sNameVorname;
	cout << "Geben Sie Ihren Vornamen ein: ";
	cin >> sVorname;
	cout << "Geben Sie Ihren Nachnamen ein: ";
	cin >> sNachname;

	sVornameName = sVorname + " " + sNachname;
	sNameVorname = sNachname + ", " + sVorname;

	cout << "Vorname Nachname: " << sVornameName << endl;
	cout << "Nachname, Vorname: " << sNameVorname << endl;


	// Note for myself: Block definiert lokale Variablen - ungültig außerhalb des Blocks

	// Block 1: Array iFeld
	{
		int iFeld[2] = {1, 2};
		cout << "iFeld[0]: " << iFeld[0] << ", iFeld[1]: " << iFeld[1] << endl;
	}

	// Block 2: 2x3 Array spielfeld
	{
		int spielfeld[2][3] = {{1,2,3},{4,5,6}};
		cout << "Spielfeld:\n";
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 3; ++j) {
				cout << spielfeld[i][j] << " ";
			}
			cout << endl;
		}
	}

	// Block 3
	{
	    const int iZweite = 1;
	    cout << "iZweite im Block: " << iZweite << endl;
	}
	cout << "iZweite außerhalb des Blocks: " << iZweite << endl;


	// ASCII-Umwandlung
	int iName1 = static_cast<int>(sVorname[0]);
	int iName2 = static_cast<int>(sVorname[1]);
	cout << "ASCII-Wert erster Buchstabe: " << iName1 << endl;
	cout << "ASCII-Wert zweiter Buchstabe: " << iName2 << endl;

	// Alphabet-Position berechnen (Groß-/Kleinschreibung ignorieren)
	int pos1 = (toupper(sVorname[0]) - 'A' + 1);
	int pos2 = (toupper(sVorname[1]) - 'A' + 1); // recheck

	cout << "Position von Buchstabe 1: " << pos1 << endl;
	cout << "Position von Buchstabe 2: " << pos2 << endl;


    return 0;
    
}
