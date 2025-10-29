#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QComboBox>
#include "map.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, MapIoNrw* mapio = nullptr);
    ~MainWindow();
    QGraphicsScene scene;
    void populateComboBoxes();

private slots:
    void on_pushButton_clicked();

    void on_actionExit_3_triggered();

    void on_actionClear_Scene_triggered();

    void on_actionAbout_triggered();

    void on_pushbutton_drawcity_clicked();

    void on_checkbox_showhide_test_clicked();

    void on_add_city_clicked();

    void on_pushButton_fillmap_clicked();

    void on_pushButton_testabstractmap_clicked();

    void on_pushButton_2_clicked();

    void on_pushbutton_addstreet_clicked();

private:
    Ui::MainWindow *ui;

    Map map;
    MapIo* mapio;

    // === Testmethoden ===
    void testSimpleUi();
    void testSimpleDrawing();
    void testDrawCities();
    void testDrawMapWithCities();
    void testDrawStreets();
    void testDrawMapWithStreets();
    void testRejectStreet();
    void testShowDialog();
    void testAbstractMap();
};
#endif // MAINWINDOW_H
