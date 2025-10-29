/**
 * @file DVD.cpp
 * @brief Implementierung der Klasse DVD (erbt von Medium).
 */

#include "DVD.h"
#include "Medium.h"
#include "Person.h"

/**
 * @brief Konstruktor mit Titel, Altersfreigabe und Genre.
 * @param initTitel Titel der DVD
 * @param initAltersfreigabe Mindestalter in Jahren
 * @param initGenre Genre der DVD
 */
DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersFreigabe(initAltersfreigabe), genre(initGenre) {}

/**
 * @brief Gibt Titel, Altersfreigabe und Genre auf der Konsole aus.
 */
void DVD::ausgabe() const {
    Medium::ausgabe();
    std::cout << "Altersfreigabe: " << altersFreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

/**
 * @brief Versucht, die DVD an eine Person auszuleihen.
 * @param person Die ausleihende Person
 * @param ausleihedatum Datum der Ausleihe
 * @return true, wenn die Altersfreigabe erfüllt ist; sonst false
 */
bool DVD::ausleihen(Person person, Datum ausleihedatum) {
    int alter = (ausleihedatum - person.getGeburtsdatum()) / 12;

    if (alter < altersFreigabe) {
        std::cout << "Du bist leider zu jung um das auszuleihen, die Altersfreigabe liegt bei " << altersFreigabe << "." << std::endl;
        return false;
    }

    return Medium::ausleihen(person, ausleihedatum);
}
