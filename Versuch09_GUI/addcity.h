#ifndef ADDCITY_H
#define ADDCITY_H

#include <QDialog>
#include "city.h"

namespace Ui {
class addcity;
}

class addcity : public QDialog
{
    Q_OBJECT

public:
    explicit addcity(QWidget *parent = nullptr);
    ~addcity();

    City* createCity();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addcity *ui;
};

#endif // ADDCITY_H
