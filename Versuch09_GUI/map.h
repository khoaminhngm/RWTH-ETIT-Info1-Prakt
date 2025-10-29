#ifndef MAP_H
#define MAP_H

#include <QList> // Template btw
#include "city.h"
#include "abstractmap.h"
#include "street.h"

class Map : public AbstractMap
{
private:
    QList<City*> cities;
    QList<Street*> streets;

public:
    Map();
    void addCity(City* city) override;
    bool addStreet(Street *) override;
    void draw(QGraphicsScene& scene);
    QList<City*> getCityList();

    City* findCity(const QString cityName) const override;
    QVector<Street*> getStreetList(const City* city) const override;
    City* getOppositeCity(const Street* street, const City* city) const override;
    double getLength(const Street* street) const override;

};

#endif // MAP_H
