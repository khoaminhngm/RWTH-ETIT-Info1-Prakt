#ifndef ADDSTREET_H
#define ADDSTREET_H

#include <QDialog>
#include "street.h"
#include "map.h"

namespace Ui {
class addstreet;
}

class addstreet : public QDialog
{
    Q_OBJECT

public:
    explicit addstreet(QWidget *parent = nullptr);
    ~addstreet();

    Street* createStreet(Map& map);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addstreet *ui;
};

#endif // ADDSTREET_H
