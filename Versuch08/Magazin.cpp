/**
 * @file Magazin.cpp
 * @brief Implementierung der Klasse Magazin (erbt von Medium).
 */

#include "Medium.h"
#include "Magazin.h"

/**
 * @brief Konstruktor mit Titel, Ausgabedatum und Sparte.
 * @param initTitel Titel des Magazins
 * @param initDatumAusgabe Erscheinungsdatum
 * @param initSparte Themenbereich
 */
Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte) {}

/**
 * @brief Gibt Titel, Erscheinungsdatum und Sparte aus.
 */
void Magazin::ausgabe() const {
    Medium::ausgabe();
    std::cout << "Erscheinungsdatum: " << datumAusgabe << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}

/**
 * @brief Verweigert Ausleihe, wenn Magazin zu aktuell ist.
 * @param person Die ausleihende Person
 * @param ausleihedatum Datum der Ausleihe
 * @return true, wenn ausleihbar; false, wenn zu aktuell
 */
bool Magazin::ausleihen(Person person, Datum ausleihedatum) {
    if ((ausleihedatum - datumAusgabe) <= 1) {
        std::cout << "Es handelt sich um die neueste Ausgabe des Magazins, die nicht ausleihbar ist." << std::endl;
        return false;
    }

    return Medium::ausleihen(person, ausleihedatum);
}
