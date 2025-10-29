#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QDebug>
#include <iostream>
#include <QMessageBox>
#include <QRandomGenerator>
#include "city.h"
#include "addcity.h"
#include "addstreet.h"
#include "dijkstra.h"

/**
 * @brief Konstruktor der MainWindow-Klasse.
 * @param parent Eltern-Widget
 * @param mapio Pointer auf MapIoNrw für Map-Befüllung
 */
MainWindow::MainWindow(QWidget *parent, MapIoNrw* mapio)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , mapio(mapio)
{
    ui->setupUi(this);
}

/**
 * @brief Destruktor der MainWindow-Klasse.
 */
MainWindow::~MainWindow()
{
    delete ui;
}

// ================================
// =      Action Funktionen       =
// ================================

/**
 * @brief Handler für Klick auf den ersten Push-Button.
 * Führt einfache Verarbeitung von Text- oder Zahleneingabe aus
 * und zeigt Rechteck zufällig in der Szene.
 */
void MainWindow::on_pushButton_clicked()
{
    bool zahl;

    QString input = ui->lineEdit_teste_was->text();
    int number = input.toInt(&zahl);

    if (!zahl) {
        QString text = "Text input von Line Edit: %1";
        text = text.arg(input);
        qDebug() << text;
        QMessageBox::information(this, "Eingabe", text);
    } else {
        int result = number + 4;
        qDebug() << result;
        QMessageBox::information(this, "Ergebnis", "Zahl + 4 = " + QString::number(result));
    }

    int x = QRandomGenerator::global()->bounded(1000);
    int y = QRandomGenerator::global()->bounded(1000);

    scene.addRect(x, y, 100, 100);
    ui->graphicsView->setScene(&scene);
}

/**
 * @brief Beendet das Programm bei Auswahl von "Exit" im Menü.
 */
void MainWindow::on_actionExit_3_triggered()
{
    close();
}


/**
 * @brief Löscht alle Objekte aus der Zeichenfläche (QGraphicsScene).
 */
void MainWindow::on_actionClear_Scene_triggered()
{
    scene.clear();
}


/**
 * @brief Zeigt ein Info-Fenster über das Programm ("About").
 */
void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "Über", "Dies ist eine Beispiel-GUI.");
}


/**
 * @brief Testet das Zeichnen von Städten und Straßen auf der Karte.
 */
void MainWindow::on_pushbutton_drawcity_clicked()
{
    testDrawStreets();
    testDrawMapWithStreets();
    testRejectStreet();
}

/**
 * @brief Zeigt oder versteckt bestimmte Buttons je nach Checkbox-Zustand.
 */
void MainWindow::on_checkbox_showhide_test_clicked()
{
    if (ui->checkbox_showhide_test->isChecked()) {
        ui->pushButton->show();
        ui->pushbutton_drawcity->show();
    }
    else {
        ui->pushButton->hide();
        ui->pushbutton_drawcity->hide();
    }
}

/**
 * @brief Öffnet Dialog zum Hinzufügen einer Stadt und fügt sie der Map hinzu.
 */
void MainWindow::on_add_city_clicked()
{
    addcity dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        City* newCity = dialog.createCity();
        map.addCity(newCity);
        map.draw(scene);
        ui->graphicsView->setScene(&scene);
        populateComboBoxes();
    }
}

/**
 * @brief Öffnet Dialog zum Hinzufügen einer Straße und fügt sie der Map hinzu, sofern gültig.
 */
void MainWindow::on_pushbutton_addstreet_clicked()
{
    addstreet dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        Street* newStreet = dialog.createStreet(map);
        if (newStreet && map.addStreet(newStreet)) {
            map.draw(scene);
            ui->graphicsView->setScene(&scene);
        } else {
            QMessageBox::warning(this, "Fehler", "Ungültige Straße oder Städte nicht in Map.");
        }
    }
}

/**
 * @brief Füllt die Map mit Daten durch MapIoNrw und zeichnet sie.
 */
void MainWindow::on_pushButton_fillmap_clicked()
{
    mapio->fillMap(map);
    map.draw(scene);
    populateComboBoxes();
    ui->graphicsView->setScene(&scene);
}

/**
 * @brief Führt Tests der abstrakten Map-Klasse durch (Validierung von Map-Logik).
 */
void MainWindow::on_pushButton_testabstractmap_clicked()
{
    testAbstractMap();
}

/**
 * @brief Aktualisiert die beiden ComboBoxen mit verfügbaren Städtenamen aus der Map.
 */
void MainWindow::populateComboBoxes()
{
    ui->comboBox_suche_start->clear();
    ui->comboBox_suche_ziel->clear();

    for (City* city : map.getCityList()) {
        ui->comboBox_suche_start->addItem(city->getName());
        ui->comboBox_suche_ziel->addItem(city->getName());
    }
}

/**
 * @brief Führt Dijkstra-Pfadfindung zwischen ausgewählten Städten durch und zeichnet den Pfad.
 */
void MainWindow::on_pushButton_2_clicked()
{
    QString start = ui->comboBox_suche_start->currentText();
    QString ziel = ui->comboBox_suche_ziel->currentText();

    QVector<Street*> weg = Dijkstra::search(map, start, ziel);

    if (weg.isEmpty()) {
        qDebug() << "Kein Weg gefunden";
        QMessageBox::warning(this, "Pfad", "Kein Pfad gefunden.");
    } else {
        qDebug() << "Gefundener Pfad:";
        for (Street* s : weg) {
            qDebug() << s->getCity1()->getName() << " -> " << s->getCity2()->getName();
        }

        scene.clear();
        map.draw(scene);

        for (Street* s : weg) {
            s->drawRed(scene);
        }

        ui->graphicsView->setScene(&scene);
    }
}



// ================================
// =       Testfunktionen        =
// ================================

/**
 * @brief Gibt einfachen Text aus dem LineEdit in qDebug aus.
 */
void MainWindow::testSimpleUi() {
    QString pattern = "The user's input: %1";
    QString s = pattern.arg(ui->lineEdit_teste_was->text());
    qDebug() << s;
}

/**
 * @brief Zeichnet ein Test-Rechteck in der Szene.
 */
void MainWindow::testSimpleDrawing() {
    scene.addRect(50, 20, 50, 100);
    ui->graphicsView->setScene(&scene);
}

/**
 * @brief Erstellt eine einzelne Stadt und zeichnet sie in die Szene.
 */
void MainWindow::testDrawCities() {
    City c1("city c1", 20, 50);
    c1.draw(scene);
    ui->graphicsView->setScene(&scene);
}

/**
 * @brief Fügt Test-Städte zur Map hinzu (aber zeichnet sie noch nicht).
 */
void MainWindow::testDrawMapWithCities() {
    City* c1 = new City("Teststadt 1", 30, 30);
    City* c2 = new City("Teststadt 2", 100, 150);

    map.addCity(c1);
    map.addCity(c2);

    qDebug() << "Teststädte wurden hinzugefügt.";
}

/**
 * @brief Erstellt zwei Städte und eine Straße dazwischen und fügt sie zur Map hinzu.
 */
void MainWindow::testDrawStreets() {
    City* c1 = new City("Alpha", 20, 20);
    City* c2 = new City("Beta", 200, 100);

    map.addCity(c1);
    map.addCity(c2);

    Street* s1 = new Street(c1, c2);
    map.addStreet(s1);

    qDebug() << "Städte und Straße hinzugefügt.";
}

/**
 * @brief Zeichnet die aktuelle Map (mit Städten und Straßen) in der Szene.
 */
void MainWindow::testDrawMapWithStreets() {
    scene.clear();
    map.draw(scene);
    ui->graphicsView->setScene(&scene);
    qDebug() << "Karte mit Städten und Straßen gezeichnet.";
}

/**
 * @brief Öffnet Dialog zum Hinzufügen einer Stadt (testweise).
 */
void MainWindow::testShowDialog() {
    addcity dialog(this);
    int result = dialog.exec();
    qDebug() << QString("Dialog result: %1").arg(result);
}

/**
 * @brief Versucht eine ungültige Straße hinzuzufügen (Städte fehlen) und prüft Ablehnung.
 */
void MainWindow::testRejectStreet() {
    City* c3 = new City("Gamma", 50, 150);
    City* c4 = new City("Delta", 1000, 1000);

    // Städte werden **nicht** zur Map hinzugefügt

    Street* s2 = new Street(c3, c4);
    bool added = map.addStreet(s2);

    if (!added) {
        qDebug() << "Straße wurde wie erwartet abgelehnt, da Städte nicht in der Map sind.";
    } else {
        qDebug() << "Fehler: Straße wurde trotz fehlender Städte hinzugefügt.";
    }
}

/**
 * @brief Umfassender Test für die Map-Klasse:
 * Prüft Hinzufügen von Städten/Straßen, Suchen von Städten,
 * Opposite-City-Funktion, Straßenlänge und StreetList.
 */
void MainWindow::testAbstractMap()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}
