/**
 * @file Buch.cpp
 * @brief Implementierung der Klasse Buch (erbt von Medium).
 */

#include "Medium.h"
#include "Buch.h"
#include <string>
#include <iostream>

/**
 * @brief Konstruktor mit Titel und Autor.
 * @param initTitel Buchtitel
 * @param initAutor Autorname
 */
Buch::Buch(std::string initTitel, std::string initAutor)
    : Medium(initTitel), autor(initAutor) {}

/**
 * @brief Gibt Titel und Autor auf der Konsole aus.
 */
void Buch::ausgabe() const {
    Medium::ausgabe();
    std::cout << "Autor: " << autor << std::endl;
}
