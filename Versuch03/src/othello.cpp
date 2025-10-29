/**
 * Praktikum Informatik 1 
 * 
 *
 * @file main.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	if (0 <= posX && posX < GROESSE_X && 0 <= posY && posY < GROESSE_Y) {
		return true;
	}
    return false;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
        	if (i == 0 && j == 0) {
        		continue; // das zu betrachtene Feld überspringen
        	}

        	int x = posX + i;
        	int y = posY + j;


        	if (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) {
				/**
				 * Wenn in der Richtung ein Gegner ist,
				 * weiter in dieser Richtung laufen & scannen
				 */

        		while(aufSpielfeld(x,y) && spielfeld[y][x] == gegner) {
        			x += i;
        			y += j;
        		}

        		/**
        		 * Wenn da ein eigenes Stück ist --> eingeklammert --> gültig
        		 */

        		if (aufSpielfeld(x,y) && spielfeld[y][x] == aktuellerSpieler) {
        			return true;
        		}
        	}
        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    // Implementierung vor dem Loop - Check nach Gültigkeit
    if (!zugGueltig(spielfeld, aktuellerSpieler, posX, posY)) {
    	return;
    }

    // Zug
    spielfeld[posY][posX] = aktuellerSpieler;

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...

        	if (i == 0 && j == 0) {
				continue; // das zu betrachtene Feld überspringen
			}

			int x = posX + i;
			int y = posY + j;


			if (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) {
				/**
				 * Wenn in der Richtung ein Gegner ist,
				 * weiter in dieser Richtung laufen & scannen
				 */
				int tmpX = x + i; // tmpX läuft vorraus und checkt, während x dessen position behält
				int tmpY = y + j; // analog für tmpY

				while(aufSpielfeld(tmpX, tmpY) && spielfeld[tmpY][tmpX] == gegner) {
					tmpX += i;
					tmpY += j;
				}


				if (aufSpielfeld(tmpX, tmpY) && spielfeld[tmpY][tmpX] == aktuellerSpieler) {

					while (tmpX != posX || tmpY != posY) {
						tmpX -= i;
						tmpY -= j;
						spielfeld[tmpY][tmpX] = aktuellerSpieler;
					}
				}
			}
        }
    }

}


/**
 * @brief Funktion, die mögliche Züge pro Spieler zählt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return Anzahl möglicher Züge
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
	int moeglicheZuege = 0;

	for (int y = 0; y < GROESSE_Y; y++) {
		for (int x = 0; x < GROESSE_X; x++) {
			if (zugGueltig(spielfeld, aktuellerSpieler, y, x)) {
				moeglicheZuege ++;
			}
		}
	}

    return moeglicheZuege;
}


/**
 * @brief Führt einen menschlichen Zug aus
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return Anzahl möglicher Züge
 */
bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    int posX;
    int posY;
    std::string symbolSpieler;
    if (aktuellerSpieler == 1)
    {
        symbolSpieler = "X";
    }
    else
    {
        symbolSpieler = "O";
    }

    while (true)
    {
        std::string eingabe;
        std::cout << std::endl << "Du bist " << symbolSpieler << ". Dein Zug (z.B. A1, a1): " ;
        std::cin >> eingabe;
        posX = (int) eingabe[0] % 32 -1;
        posY = (int) eingabe[1] - 49;

        if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY))
        {
            //accept turn;
            break;
        }
        else
        {
            std::cout << std::endl << "Ungueltige Eingabe !" << std::endl;
        }
    }

    zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
    std::cout << std::endl << "Spieler " << aktuellerSpieler << " setzt auf " << (char) (posX + 65) << (posY + 1) << std::endl << std::endl;

    return true;
}

/**
 * @brief Spielfunktion für Modus Mensch vs Mensch
 *
 * @param spielerTyp
 */
void spielenMensch(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while(moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, 3-aktuellerSpieler) != 0) {
    	menschlicherZug(spielfeld, aktuellerSpieler);
    	zeigeSpielfeld(spielfeld);
		aktuellerSpieler = 3 - aktuellerSpieler;
    }
    
    // Gewinner bekanntgeben
    int winner = gewinner(spielfeld);

    switch (winner)
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
    	case 0:
    		std::cout << "Das Spiel geht unentschieden aus!" << std::endl << std::endl;
    		break;
    	case 1:
		case 2:
			std::cout << "Der Gewinner ist: " << winner << "! Glückwunsch :))" << std::endl << std::endl;
			break;
		default:
			std::cout << "Unerwartetes Ergebnis: " << std::endl;
			break;
    }
}


/**
 * @brief Spielfunktion für Modus Mensch vs KI
 *
 * @param spielerTyp
 */
void spielenKI(const int spielerTyp[2]) {

    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while(moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, 3-aktuellerSpieler) != 0) {
    	if (aktuellerSpieler == 1) {
    		menschlicherZug(spielfeld, aktuellerSpieler);
    		zeigeSpielfeld(spielfeld);
    		aktuellerSpieler = 3 - aktuellerSpieler;
    	}
    	else if (aktuellerSpieler == 2) {
    		computerZug(spielfeld, aktuellerSpieler);
    		zeigeSpielfeld(spielfeld);
    		aktuellerSpieler = 3 - aktuellerSpieler;
    	}
    }

    // Gewinner bekanntgeben
	int winner = gewinner(spielfeld);

	switch (winner)
	{
		// Hier erfolgt jetzt Ihre Implementierung ...
		case 0:
			std::cout << "Das Spiel geht unentschieden aus!" << std::endl << std::endl;
			break;
		case 1:
			std::cout << "Der Gewinner bist du! Glückwunsch :)" << std::endl << std::endl;
			break;
		case 2:
			std::cout << "Der Gewinner ist das fancy KI.. schade :(" << std::endl << std::endl;
			break;
		default:
			std::cout << "Unerwartetes Ergebnis: " << std::endl << std::endl;
			break;
	}
}

void spielenKIKI(const int spielerTyp[2]) {
	int spielfeld[GROESSE_Y][GROESSE_X];

	//Erzeuge Startaufstellung
	initialisiereSpielfeld(spielfeld);

	int aktuellerSpieler = 1;
	zeigeSpielfeld(spielfeld);

	// solange noch Zuege bei einem der beiden Spieler moeglich sind
	//
	// Hier erfolgt jetzt Ihre Implementierung ...
	while(moeglicheZuege(spielfeld, aktuellerSpieler) != 0 || moeglicheZuege(spielfeld, 3-aktuellerSpieler) != 0) {
		computerZug(spielfeld, aktuellerSpieler);
		zeigeSpielfeld(spielfeld);
		aktuellerSpieler = 3 - aktuellerSpieler;
	}

	// Gewinner bekanntgeben
	int winner = gewinner(spielfeld);

	switch (winner)
	{
		// Hier erfolgt jetzt Ihre Implementierung ...
		case 0:
			std::cout << "Das Spiel geht unentschieden aus!" << std::endl << std::endl;
			break;
		case 1:
		case 2:
			std::cout << "Der Gewinner ist das KI Nummer: " << winner << "! Glückwunsch :))" << std::endl << std::endl;
			break;
		default:
			std::cout << "Unerwartetes Ergebnis: " << std::endl;
			break;
	}
}


//int main()
//{
//    if (TEST == 1)
//    {
//        bool gesamtErgebnis = ganzenTestAusfuehren();
//        if (gesamtErgebnis == true)
//        {
//            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
//        }
//        else
//        {
//            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
//            exit(1);
//        }
//        std::cout << std::endl << std::endl;
//    }
//
//    return 0;
//};


int main () {
	int auswahlGegner;
	char nochmal;

	do {
		while(1) {
			std::cout << "Wollen Sie 'Mensch vs Mensch' oder 'Mensch vs KI' spielen?" << std::endl << std::endl
						<< "Geben Sie 1 ein für 'Mensch vs Mensch Modus' und 2 für 'Mensch vs KI Modus' und 3 für 'KI vs KI Modus': ";
			std::cin >> auswahlGegner;
			if (auswahlGegner != 1 && auswahlGegner != 2 && auswahlGegner != 3) {
				std::cout << "Eingabe ungültig, bitte lesen lernen." << std::endl << std::endl;
			}
			else {
				break;
			}
		}

		if (auswahlGegner == 1) {
			int spielerTyp[2] = {MENSCH ,MENSCH};
			spielenMensch(spielerTyp);
			return 0;
		}
		else if (auswahlGegner == 2) {
			int spielerTyp[2] = {MENSCH, COMPUTER};
			spielenKI(spielerTyp);
			return 0;
		}
		else if (auswahlGegner == 3) {
			int spielerTyp[2] = {COMPUTER, COMPUTER};
			spielenKIKI(spielerTyp);
			return 0;
		}
		else {
			std::cout << "Es gab einen Fehler." << std::endl;
			return 1;
		}

		std::cout << "Möchten Sie noch eine Partie spielen? (j/n): ";
		std::cin >> nochmal;
	} while (nochmal == 'j' || nochmal == 'J');
};


//     Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
//     implementiert haben (waeren sonst doppelt)
//    int spielfeld[GROESSE_Y][GROESSE_X];
//
//    initialisiereSpielfeld(spielfeld);
//
//    zeigeSpielfeld(spielfeld);
//
//     int spielerTyp[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
//     spielen(spielerTyp);
//
//     Hier erfolgt jetzt Ihre Implementierung ...

//    return 0;
// };
