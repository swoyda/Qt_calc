#ifndef GRAPH_H
#define GRAPH_H

#include <QWidget>
#include "mainwindow.h"
extern "C" {
#include "../../s21_main.h"
}
namespace Ui {
class Graph;
}

class Graph : public QWidget
{
    Q_OBJECT

public:
    explicit Graph(MainWindow *mainwindow, QWidget *parent = nullptr);
    ~Graph();

private:
    MainWindow *settingsgraph;
    Ui::Graph *ui;
private slots:
    void build(QString *data[6]);
};

#endif // GRAPH_H
