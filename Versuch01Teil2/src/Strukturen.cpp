/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
using namespace std;

int main()
{
	// Struktur deklarieren
	struct Person {
	    string sNachname;
	    string sVorname;
	    int iGeburtsjahr;
	    int iAlter;
	};

	Person nBenutzer;

	// Input
	cout << "Geben Sie Ihren Nachnamen ein: ";
	cin >> nBenutzer.sNachname;

	cout << "Geben Sie Ihren Vornamen ein: ";
	cin >> nBenutzer.sVorname;

	cout << "Geben Sie Ihr Geburtsjahr ein: ";
	cin >> nBenutzer.iGeburtsjahr;

	cout << "Geben Sie Ihr Alter ein: ";
	cin >> nBenutzer.iAlter;

	// Ausgabe der Struktur
	cout << "\n--- Benutzerdaten ---" << endl;
	cout << "Name: " << nBenutzer.sVorname << " " << nBenutzer.sNachname << endl;
	cout << "Geburtsjahr: " << nBenutzer.iGeburtsjahr << endl;
	cout << "Alter: " << nBenutzer.iAlter << endl;

	// Kopie 1: Jedes Element einzeln kopieren
	Person nKopieEinzeln;
	nKopieEinzeln.sNachname = nBenutzer.sNachname;
	nKopieEinzeln.sVorname = nBenutzer.sVorname;
	nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
	nKopieEinzeln.iAlter = nBenutzer.iAlter;


	// Kopie 2: Gesamte Struktur kopieren
	Person nKopieGesamt = nBenutzer;

	// Ausgabe der Kopien
	cout << "\n--- Kopie einzeln ---" << endl;
	cout << "Name: " << nKopieEinzeln.sVorname << " " << nKopieEinzeln.sNachname << endl;
	cout << "Geburtsjahr: " << nKopieEinzeln.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieEinzeln.iAlter << endl;

	cout << "\n--- Kopie gesamt ---" << endl;
	cout << "Name: " << nKopieGesamt.sVorname << " " << nKopieGesamt.sNachname << endl;
	cout << "Geburtsjahr: " << nKopieGesamt.iGeburtsjahr << endl;
	cout << "Alter: " << nKopieGesamt.iAlter << endl;

    return 0;
    
}
