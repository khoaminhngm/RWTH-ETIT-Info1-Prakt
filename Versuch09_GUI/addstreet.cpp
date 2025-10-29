/**
 * @class addstreet
 * @brief Dialogfenster zum Erstellen und Hinzufügen einer Straße zwischen zwei Städten.
 *
 * Diese Klasse bietet eine Benutzeroberfläche zur Eingabe von Start- und Zielstadt.
 * Nach Bestätigung wird eine Street zwischen den angegebenen Städten erstellt,
 * sofern beide in der Map vorhanden sind.
 */

#include "addstreet.h"
#include "ui_addstreet.h"

/**
 * @brief Konstruktor des Dialogs zum Hinzufügen einer Straße.
 * @param parent Zeiger auf das übergeordnete Widget
 */
addstreet::addstreet(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addstreet)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor. Gibt das UI-Objekt frei.
 */
addstreet::~addstreet()
{
    delete ui;
}

/**
 * @brief Erstellt eine neue Street zwischen zwei Städten, sofern beide in der Map existieren.
 * @param map Referenz auf die aktuelle Map zur Stadtsuche
 * @return Zeiger auf das neue Street-Objekt oder nullptr, wenn Eingabe ungültig ist
 */
Street* addstreet::createStreet(Map& map) {
    City* c1 = map.findCity(ui->lineEdit_addstreet_start->text());
    City* c2 = map.findCity(ui->lineEdit_addstreet_end->text());

    if (c1 == nullptr || c2 == nullptr) {
        return nullptr;
    }

    return new Street(c1, c2);
}

/**
 * @brief Slot-Funktion, die beim Bestätigen des Dialogs ausgelöst wird.
 * Schließt den Dialog mit akzeptiertem Status.
 */
void addstreet::on_buttonBox_accepted()
{
    accept();
}
