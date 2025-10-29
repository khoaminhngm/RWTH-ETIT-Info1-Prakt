#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QGraphicsScene>

class City
{
private:
    QString name;
    int x;
    int y;

public:
    City(QString name, int x, int y);
    void draw(QGraphicsScene& scene);
    QString getName() const;
    int getX() const;
    int getY() const;
    bool operator==(const City& other) const;
};

#endif // CITY_H
