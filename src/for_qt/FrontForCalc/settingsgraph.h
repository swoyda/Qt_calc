#ifndef SETTINGSGRAPH_H
#define SETTINGSGRAPH_H

#include <QMainWindow>

#include <QString>
namespace Ui {
class settingsGraph;
}

class settingsGraph : public QMainWindow
{
    Q_OBJECT
signals:
    void sendData(QString *data[6]);

public:
    explicit settingsGraph(QWidget *parent = nullptr);
    ~settingsGraph();
public slots:
private:
    Ui::settingsGraph *ui;

private slots:
    void compile_graph();
    void default_graph();
    void clear_graph();
};

#endif // SETTINGSGRAPH_H
