/**
 * @class Street
 * @brief Repräsentiert eine Verbindung (Straße) zwischen zwei Städten.
 *
 * Die Klasse verwaltet zwei Zeiger auf City-Objekte, zwischen denen sie eine Linie
 * in einer QGraphicsScene zeichnen kann. Optional kann die Straße auch in Rot hervorgehoben werden.
 */

#include "street.h"

/**
 * @brief Konstruktor. Initialisiert die Straße mit zwei verbundenen Städten.
 * @param c1 Zeiger auf die erste Stadt
 * @param c2 Zeiger auf die zweite Stadt
 */
Street::Street(City* c1, City* c2) : c1(c1), c2(c2) {}

/**
 * @brief Zeichnet die Straße (weiße Linie) zwischen den beiden Städten in der Szene.
 * @param scene Die QGraphicsScene, auf der gezeichnet wird
 */
void Street::draw(QGraphicsScene &scene) {
    int x1 = c1->getX();
    int y1 = c1->getY();
    int x2 = c2->getX();
    int y2 = c2->getY();

    scene.addLine(x1, y1, x2, y2, QPen(Qt::white));
}

/**
 * @brief Gibt die erste Stadt (c1) zurück.
 * @return Zeiger auf City
 */
City* Street::getCity1() const {
    return c1;
}

/**
 * @brief Gibt die zweite Stadt (c2) zurück.
 * @return Zeiger auf City
 */
City* Street::getCity2() const {
    return c2;
}

/**
 * @brief Zeichnet die Straße als rote Linie (z.B. zur Hervorhebung im Pfad).
 * @param scene Die QGraphicsScene, auf der gezeichnet wird
 */
void Street::drawRed(QGraphicsScene& scene) {
    int x1 = c1->getX();
    int y1 = c1->getY();
    int x2 = c2->getX();
    int y2 = c2->getY();

    QPen redPen(Qt::red);
    redPen.setWidth(4);

    scene.addLine(x1, y1, x2, y2, redPen);
}
