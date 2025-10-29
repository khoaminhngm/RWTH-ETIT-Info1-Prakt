/** @mainpage
 *
 * Praktikum Informatik 1 MMXXV <BR>
 * Versuch 5: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <limits>

#include "Student.h"

/**
 * @brief Hauptfunktion zum Verwalten einer Studentenliste.
 *
 * Das Programm bietet ein Menüsystem zur Interaktion mit einer doppelt verketteten Liste, in der
 * Studentendaten gespeichert werden. Es unterstützt folgende Operationen:
 * - Manuelles oder automatisches Befüllen der Liste
 * - Hinzufügen von Studenten am Anfang oder Ende
 * - Entfernen von Studenten vom Anfang
 * - Löschen eines Studenten anhand der Matrikelnummer
 * - Ausgabe der Liste vorwärts oder rückwärts
 *
 * @return int Rückgabewert 0 signalisiert erfolgreichen Programmabschluss.
 */

int main()
{
    std::vector<Student> studentenListe;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    // Füllen der Liste
    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenListe.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenListe.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenListe.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenListe.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "W�llnerstr.9");
        studentenListe.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement hinten entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
				  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
				  << "(5): Datenelement löschen" << std::endl
				  << "(6): Datenelement vorne löschen" << std::endl
				  << "(7): Datenelement an beliebiger Stelle hinzufügen" << std::endl
				  << "(8): Daten aus einer Datei einlesen" << std::endl
				  << "(9): Daten in eine Datei sichern" << std::endl
				  << "(s): Studenten nach Matrikelnummer sortieren" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen
            case '1':
            	{
					unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";

					std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					studentenListe.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenListe.empty())
                    {
                        student = studentenListe.back();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        student.ausgabe(std::cout);
                        studentenListe.pop_back();
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenListe.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (auto it = studentenListe.begin(); it != studentenListe.end(); ++it) {
                    	it -> ausgabe(std::cout);
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            case '4':
				{
					if (!studentenListe.empty()) {
						std::cout << "Inhalt der Liste in ruecklaufender Reihenfolge:" << std::endl;
						for (auto it = studentenListe.rbegin(); it != studentenListe.rend(); ++it) {
							it -> ausgabe(std::cout);
						}
					}
					else {
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
            	break;

            case '5':
				{
					if (!studentenListe.empty()) {
						unsigned int matNrInput;

						std::cout << "Geben Sie die zu löschende Matrikelnummer ein: ";
						std::cin >> matNrInput;

						Student studentGesucht(matNrInput, " ", " ", " ");

						auto it = std::find(studentenListe.begin(), studentenListe.end(), studentGesucht); // find() returns iterator (pointer)

						if (it != studentenListe.end()) {
							std::cout << "Der folgende Student ist gelöscht worden:\n";
							it -> ausgabe(std::cout);
							studentenListe.erase(it);
						}
						else {
							std::cout << "Kein Student mit dieser Matrikelnummer gefunden.\n";
						}
					}
					else {
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
				break;

            case '6':
				{
				    if (!studentenListe.empty()) {
				        student = studentenListe.front();
				        auto it = studentenListe.begin();
				        studentenListe.erase(it);
				        std::cout << "Student gelöscht:\n" << student << std::endl;
				    } else {
				        std::cout << "Liste ist leer, nichts zu löschen.\n";
				    }
				}
				break;

            case '7':
            	{
            		unsigned int matNr = 0;
					std::string name = "";
					std::string geburtstag = "";
					std::string adresse = "";
					int position;

					std::cout << "Bitte geben sie die Daten fuer den Studenten ein.\nName: ";
					getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

					std::cout << "Geburtsdatum: ";
					getline(std::cin, geburtstag);

					std::cout << "Adresse: ";
					getline(std::cin, adresse);

					std::cout << "Matrikelnummer: ";
					std::cin >> matNr;
					std::cin.ignore(10, '\n');

					student = Student(matNr, name, geburtstag, adresse);

					std::cout << "Gewünschte Input Position von 0 bis " << studentenListe.size() << ": ";
					std::cin >> position;
					std::cin.ignore(10, '\n');

					if (position < 0 || position > studentenListe.size()) {
					    std::cout << "Ungültige Position!\n";
					    break;
					}


					studentenListe.insert(studentenListe.begin() + position, student);
            	}
            	break;

            case '8':
				{
					studentenListe.clear();

					unsigned int matNr = 0;
					std::string name;
					std::string geburtsdatum;
					std::string adresse;

					std::string datei;

					std::cout << "Aus welcher Datei soll gelesen werden? Dateiname: " << std::endl;
					getline(std::cin, datei);

					std::ifstream eingabe(datei);

					if (!eingabe.is_open()) {
					    std::cout << "Datei konnte nicht geöffnet werden.\n";
					    return 1;
					}

					// Lesen
					while(eingabe >> matNr) {
						eingabe.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
						std::getline(eingabe, name);
						if (!name.empty() && name.back() == '\r') name.pop_back();

						std::getline(eingabe, geburtsdatum);
						if (!geburtsdatum.empty() && geburtsdatum.back() == '\r') geburtsdatum.pop_back();

						std::getline(eingabe, adresse);
						if (!adresse.empty() && adresse.back() == '\r') adresse.pop_back();


						student= Student(matNr,  name, geburtsdatum, adresse);
						studentenListe.push_back(student);
					}

				}
				break;

            case '9':
				{
					if (!studentenListe.empty()) {
						std::ofstream sichern;
						sichern.open("safe.txt");

						// schreiben
						for (auto it = studentenListe.begin(); it != studentenListe.end(); ++it) {
							sichern << it->getMatNr() << std::endl;
							sichern << it->getName() << std::endl;
							sichern << it->getGeburtstag() << std::endl;
							sichern << it->getAdresse() << std::endl;
						}
						std::cout << "Daten wurden erfolgreich in 'safe.txt' gespeichert.\n";
					}
					else {
						std::cout << "Die Liste ist leer!\n\n";
					}
				}
				break;
            case 's':
				{
					if(!studentenListe.empty()){
						std::sort(studentenListe.begin(), studentenListe.end());
					}
					else {
						std::cout << "Liste ist leer :<" << std::endl;
					}
				}
				break;

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
