/**
 * @class City
 * @brief Repräsentiert eine Stadt mit Namen und Koordinaten im 2D-Raum.
 *
 * Die Klasse stellt Methoden bereit zur Visualisierung auf einer QGraphicsScene
 * sowie Zugriff auf Positions- und Namensinformationen.
 */

#include "city.h"
#include <QBrush>
#include <QPen>
#include <QDebug>
#include <QGraphicsTextItem>

/**
 * @brief Konstruktor zur Initialisierung einer Stadt.
 * @param name Name der Stadt
 * @param x X-Koordinate auf der Zeichenfläche
 * @param y Y-Koordinate auf der Zeichenfläche
 */
City::City(QString name, int x, int y) : name(name), x(x), y(y) {}

/**
 * @brief Zeichnet die Stadt als Punkt und Text auf der gegebenen QGraphicsScene.
 * @param scene Die Szene, in der die Stadt dargestellt werden soll
 */
void City::draw(QGraphicsScene& scene) {
    qDebug() << "Zeichne Stadt: " << name << " bei (" << x << "," << y << ")";
    scene.addEllipse(x, y, 5, 5, QPen(Qt::NoPen), QBrush(Qt::red));
    scene.addText(name)->setPos(x + 6, y - 6);
}

/**
 * @brief Gibt den Namen der Stadt zurück.
 * @return QString mit dem Stadtnamen
 */
QString City::getName() const {
    return name;
}

/**
 * @brief Gibt die X-Koordinate der Stadt zurück.
 * @return X-Koordinate
 */
int City::getX() const {
    return x;
}

/**
 * @brief Gibt die Y-Koordinate der Stadt zurück.
 * @return Y-Koordinate
 */
int City::getY() const {
    return y;
}

/**
 * @brief Vergleicht zwei Städte auf Gleichheit (Name und Koordinaten).
 * @param other Die zu vergleichende Stadt
 * @return true, wenn Name und Koordinaten gleich sind, sonst false
 */
bool City::operator==(const City& other) const {
    return name == other.name && x == other.x && y == other.y;
}
