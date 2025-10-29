//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXV
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

/**
 * @brief Hauptfunktion zum Starten des Sichtweitenprogramms.
 *
 * Berechnet mithilfe von Vektoren die Sichtweite einer Person von einer Plattform
 * auf einem Kugelobjekt (z.B. Erde). Es wird ein iterativer Algorithmus verwendet,
 * um die Tangente am Erdradius zu finden (Sichtlinie ist orthogonal).
 *
 * @return Rückgabewert 0 bei erfolgreichem Programmende.
 */
int main()
{
    
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();

    std::cout << "----------------------- \n\n";

    // Variablen
    double radErde = 6371000;
    double hoeheMensch = 1.7;
    double hoehePlattform = 555.7;
    double increment = 1e-8;

    Vektor aussichtsPunkt(0, (radErde + hoehePlattform + hoeheMensch), 0);
    Vektor erdRadius(0, radErde, 0);
    Vektor sicht(0, 0, 0);

    double sichtWeite;
	double hoehe = hoehePlattform + hoeheMensch;
	double winkel_deg;
	int anzahlSchritte = 0;

//    while(1) {
//
//    	sicht = erdRadius.sub(aussichtsPunkt);
//    	erdRadius.rotiereUmZ(increment);
//    	anzahlSchritte++;
//
//    	std::cout << "SkalarProdukt " << anzahlSchritte << ": " << sicht.skalarProd(erdRadius) << std::endl << std::endl;
//
//    	if (sicht.skalarProd(erdRadius) > 0) {
//    		break;
//    	}
//
//    }
//
//    sichtWeite = sicht.laenge();
//    winkel_deg = erdRadius.winkel(aussichtsPunkt) * 180/M_PI;
//
//    // Print
//	std::cout << "Sie können " << sichtWeite * pow(10, (-3)) << " Km weit sehen." << std::endl;
//	std::cout << "Sie sind " << hoehe << " Meter hoch." << std::endl;
//	std::cout << "Der Winkel beträgt " << winkel_deg << " Grad." << std::endl;
//	std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;


	// Optionelle Aufgabe
	Vektor erdRadius_neu(0, radErde, 0);
	Vektor sicht_neu(0, 0, 0);
	double schrittweite = 1;
	double anzahlSchritte_neu = 0;
	double epsilon = 0.7579005;

	sicht_neu = erdRadius_neu.sub(aussichtsPunkt);

	while(1) {

		if (sicht_neu.skalarProd(erdRadius_neu) < 0) {

			if (schrittweite < 0) {
				schrittweite *= -0.1;
			}

		}

		else if (sicht_neu.skalarProd(erdRadius_neu) > 0) {
			if (schrittweite > 0) {
				schrittweite *= -0.1;
			}
		}

		erdRadius_neu.rotiereUmZ(schrittweite);
		sicht_neu = erdRadius_neu.sub(aussichtsPunkt);

		anzahlSchritte_neu++;


		std::cout << schrittweite << std::endl << std::endl;
		std::cout << sicht_neu.winkel(erdRadius) * 180/M_PI << std::endl << std::endl;


		if (abs((sicht_neu.winkel(erdRadius) * 180/M_PI) - 90) < epsilon) {
			break;
		}

		if (schrittweite == 0 || anzahlSchritte_neu == 1000) {
			break;
		}
	}

	sichtWeite = sicht_neu.laenge();
	winkel_deg = abs(erdRadius_neu.winkel(aussichtsPunkt)) * 180/M_PI;
	anzahlSchritte = anzahlSchritte_neu;

	std::cout << "Sie können " << sichtWeite * pow(10, (-3)) << " Km weit sehen." << std::endl;
	std::cout << "Sie sind " << hoehe << " Meter hoch." << std::endl;
	std::cout << "Der Winkel beträgt " << winkel_deg << " Grad." << std::endl;
	std::cout << "Anzahl Schritte: " << anzahlSchritte << std::endl;

    return 0;

}
