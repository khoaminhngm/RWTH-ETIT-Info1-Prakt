#ifndef STREET_H
#define STREET_H

#include "city.h"

class Street
{
private:
    City* c1;
    City* c2;
public:
    Street(City* c1, City* c2);
    void draw(QGraphicsScene& scene);
    City* getCity1() const;
    City* getCity2() const;
    void drawRed(QGraphicsScene& scene);
};

#endif // STREET_H
