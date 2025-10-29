//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

/**
 * @brief Konstruktor der Klasse Vektor.
 *
 * Initialisiert einen Vektor mit den gegebenen x-, y- und z-Komponenten.
 *
 * @param inX X-Komponente des Vektors
 * @param inY Y-Komponente des Vektors
 * @param inZ Z-Komponente des Vektors
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{

}

/**
 * @brief Destruktor der Klasse Vektor.
 *
 * Wird beim Löschen eines Vektor-Objekts aufgerufen.
 */
Vektor::~Vektor()
{

}

/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}


/**
 * @brief Berechnet die euklidische Länge (Betrag) des Vektors.
 *
 * @return Die Länge des Vektors als double.
 */
double Vektor::laenge() const {
	return sqrt(x*x + y*y + z*z);
}

/**
 * @brief Subtrahiert einen übergebenen Vektor vom aktuellen Vektor.
 *
 * @param input Der zu subtrahierende Vektor.
 * @return Neuer Vektor als Ergebnis der Subtraktion.
 */
Vektor Vektor::sub(const Vektor& input) const {
	return Vektor(this->x - input.x, this->y - input.y, this->z - input.z);
}


/**
 * @brief Berechnet das Skalarprodukt mit einem anderen Vektor.
 *
 * @param input Der andere Vektor.
 * @return Das Skalarprodukt als double.
 */
double Vektor::skalarProd(const Vektor& input) const {
	return (this->x * input.x + this->y * input.y + this->z * input.z);
}


/**
 * @brief Berechnet den Winkel zwischen dem aktuellen Vektor und einem anderen Vektor.
 *
 * @param input Der andere Vektor.
 * @return Der Winkel in Radiant als double.
 */
double Vektor::winkel(const Vektor& input) const {
	double skalar;
	double laenge1;
	double laenge2;

	skalar = this->skalarProd(input);
	laenge1 = this->laenge();
	laenge2 = input.laenge();

	if (laenge1 == 0 || laenge2 == 0) {
		return 0;
	}

	double cosTheta = skalar/(laenge1*laenge2);
	return acos(cosTheta);
}


/**
 * @brief Rotiert den Vektor um die Z-Achse.
 *
 * Die Rotation erfolgt gegen den Uhrzeigersinn im XY-Ebene um den übergebenen Winkel in Radiant.
 *
 * @param rad Der Rotationswinkel in Radiant.
 */
void Vektor::rotiereUmZ(const double rad) {
	double tmp_x;
	double tmp_y;
	tmp_x = (this->x * cos(rad) - this->y * sin(rad));
	tmp_y = (this->x * sin(rad) + this->y * cos(rad));
	this->x = tmp_x;
	this->y = tmp_y;
}
