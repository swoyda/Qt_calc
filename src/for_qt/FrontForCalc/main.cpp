#include "graph.h"
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    settingsGraph *settingsGraphInstance = new settingsGraph();
    MainWindow *w = new MainWindow(settingsGraphInstance);
    Graph *graph = new Graph(w);
    graph->show();
    w->show();
    return a.exec();
}
