/**
 * @class Map
 * @brief Repräsentiert eine Karte, bestehend aus Städten und Straßen.
 *
 * Die Klasse verwaltet eine Liste von City-Objekten und Street-Objekten, stellt
 * Methoden zur Visualisierung auf einer Szene bereit und unterstützt Pfadsuche,
 * Verbindungsmanagement und Distanzberechnungen.
 */

#include "map.h"
#include <QDebug>
#include <cmath>
#include <iostream>

/**
 * @brief Standardkonstruktor der Map-Klasse.
 */
Map::Map() {}

/**
 * @brief Fügt eine Stadt zur Karte hinzu.
 * @param city Zeiger auf das hinzuzufügende City-Objekt
 */
void Map::addCity(City* city) {
    cities.append(city);
    qDebug() << "Stadt hinzugefügt:" << city->getName();
}

/**
 * @brief Gibt eine Liste aller Städte in der Karte zurück.
 * @return QList mit City-Pointern
 */
QList<City*> Map::getCityList() {
    return cities;
}

/**
 * @brief Zeichnet alle Städte und Straßen in der gegebenen Szene.
 * @param scene QGraphicsScene zur Darstellung
 */
void Map::draw(QGraphicsScene &scene) {
    for (QList<City*>::iterator it = cities.begin(); it != cities.end(); ++it) {
        (*it)->draw(scene);
    }

    for (QList<Street*>::iterator it = streets.begin(); it != streets.end(); ++it) {
        (*it)->draw(scene);
    }
}

/**
 * @brief Fügt eine Straße zur Karte hinzu, wenn beide Städte bereits enthalten sind.
 * @param street Zeiger auf Street-Objekt
 * @return true bei Erfolg, false wenn eine der Städte nicht vorhanden ist
 */
bool Map::addStreet(Street* street) {
    if (cities.contains(street->getCity1()) && cities.contains(street->getCity2())) {
        streets.append(street);
        qDebug() << "Straße hinzugefügt zwischen:"
                 << street->getCity1()->getName()
                 << "und"
                 << street->getCity2()->getName();
        return true;
    } else {
        qDebug() << "Fehler: Eine oder beide Städte sind nicht in der Karte!";
        return false;
    }
}

/**
 * @brief Sucht eine Stadt anhand ihres Namens.
 * @param cityName Name der Stadt (case-insensitive)
 * @return Zeiger auf City oder nullptr, falls nicht gefunden
 */
City* Map::findCity(const QString cityName) const {
    for (City* city : cities) {
        if (QString::compare(cityName, city->getName(), Qt::CaseInsensitive) == 0) {
            qDebug() << "Gefundene Stadt: " << city->getName();
            return city;
        }
    }
    qDebug() << "Stadtname nicht gefunden :<";
    return nullptr;
}

/**
 * @brief Gibt alle Straßen zurück, die mit einer bestimmten Stadt verbunden sind.
 * @param city Zeiger auf die Zielstadt
 * @return QVector mit allen verbundenen Street-Pointern
 */
QVector<Street*> Map::getStreetList(const City* city) const {
    QString cityName = city->getName();
    QVector<Street*> streetList;

    for (Street* street : streets) {
        if (
            QString::compare(cityName, street->getCity1()->getName(), Qt::CaseInsensitive) == 0 ||
            QString::compare(cityName, street->getCity2()->getName(), Qt::CaseInsensitive) == 0
            ) {
            streetList.append(street);
        }
    }

    if (streetList.isEmpty()) {
        qDebug() << "Keine Straßen gefunden für diese Stadt.";
    }

    return streetList;
}

/**
 * @brief Gibt die andere Stadt zurück, die über eine Straße mit der gegebenen Stadt verbunden ist.
 * @param street Zeiger auf eine Straße
 * @param city Zeiger auf eine der beiden Städte
 * @return Die jeweils andere Stadt oder nullptr, wenn keine Verbindung existiert
 */
City* Map::getOppositeCity(const Street* street, const City* city) const {
    if (*street->getCity1() == *city) {
        return street->getCity2();
    }
    if (*street->getCity2() == *city) {
        return street->getCity1();
    }
    return nullptr;
}

/**
 * @brief Berechnet die Länge einer Straße anhand der Koordinaten ihrer Endpunkte.
 * @param street Zeiger auf die Straße
 * @return Länge als double
 */
double Map::getLength(const Street* street) const {
    int x1 = street->getCity1()->getX();
    int x2 = street->getCity2()->getX();

    int y1 = street->getCity1()->getY();
    int y2 = street->getCity2()->getY();

    double deltaX = static_cast<double>(x1 - x2);
    double deltaY = static_cast<double>(y1 - y2);

    double length = std::sqrt(std::pow(deltaX, 2) + std::pow(deltaY, 2));

    return length;
}
