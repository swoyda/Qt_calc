#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>

#include <QString>
#include <settingsgraph.h>
#include "qcustomplot.h"
#include "creditcalc.h"
#include "depositcalc.h"

extern "C" {
    #include "../../s21_main.h"
}
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(QString *data[6]);
    // void sendString(const char &str);
public:
    MainWindow(settingsGraph *settingsGraph, QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void receiveData(QString *data[6]);
private:
    settingsGraph *settingsgraph;
    creditcalc *CreditCalc;
    depositcalc *DepositCalc;
    Ui::MainWindow *ui;
private slots:
    // void graphs(double x, double minus_x, double y, double minus_y, double steps);
    void digits_numbers();
    void on_GSettingsButton_clicked();
    void open_credit_calc();
    void open_deposit_calc();
};
#endif // MAINWINDOW_H
