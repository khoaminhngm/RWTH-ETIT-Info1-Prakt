/**
 * @class addcity
 * @brief Dialogfenster zum Erstellen und Hinzufügen einer neuen Stadt zur Karte.
 *
 * Diese Klasse bietet eine einfache Eingabemaske zur Erfassung des Stadtnamens sowie
 * der X- und Y-Koordinaten. Nach Bestätigung wird ein neues City-Objekt erstellt.
 */

#include "addcity.h"
#include "ui_addcity.h"

/**
 * @brief Konstruktor für das Dialogfenster zum Hinzufügen einer Stadt.
 * @param parent Zeiger auf das übergeordnete Widget
 */
addcity::addcity(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::addcity)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor. Gibt das UI-Objekt frei.
 */
addcity::~addcity()
{
    delete ui;
}

/**
 * @brief Erstellt ein neues City-Objekt basierend auf den Benutzereingaben im Dialog.
 * @return Pointer auf das neu erstellte City-Objekt
 */
City* addcity::createCity() {
    QString name = ui->lineEdit_name->text();
    int x = ui->lineEdit_x->text().toInt();
    int y = ui->lineEdit_y->text().toInt();

    return new City(name, x, y);
}

/**
 * @brief Slot-Funktion, die bei Akzeptieren des Dialogs ausgelöst wird.
 * Schließt den Dialog mit akzeptiertem Status.
 */
void addcity::on_buttonBox_accepted()
{
    accept();
}
