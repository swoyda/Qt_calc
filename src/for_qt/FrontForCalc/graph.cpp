#include "graph.h"
#include "ui_graph.h"
#include "mainwindow.h"

Graph::Graph(MainWindow *mainwindow, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Graph)
{

    ui->setupUi(this);
    // Graph *graph = new Graph(mainwindow);
    // QTextStream(stdout) << "pre 2\n";
    connect(mainwindow , &MainWindow::sendData, this, &Graph::build);

    // graph->show();
}

void Graph::build(QString *data[6]) {
    ui->graph->clearGraphs();
    // double x = data[0]->toDouble();
    // double minus_x = data[1]->toDouble();
    // double y = data[2]->toDouble();
    // double minus_y = data[3]->toDouble();
    // double steps = data[4]->toDouble();
    // all[0] = &x_str;
    // all[1] = &y_str;
    // all[2] = &minus_x_str;
    // all[3] = &minus_y_str;
    // all[4] = &steps_str;
    // all[5] = &empty;
    double a = data[2]->toDouble(); //Начало интервала, где рисуем график по оси Ox
    double b = data[0]->toDouble();//Конец интервала, где рисуем график по оси Ox
    double h = data[4]->toDouble();//Шаг, с которым будем пробегать по оси Ox
    int N = (b - a) / h + 2; //Вычисляем количество точек, которые будем отрисовывать
    QVector<double> x(N), y(N); //Массивы координат точек

    int i=0;
    QString *input_str = data[5];
    std::string std_input_str = input_str->toStdString();
    const char* char_input_str = std_input_str.c_str();

    // QTextStream(stdout) << *input_str;
    //Пробегаем по всем точкам
    for (double X = a; X <= b; X += h) {
        x[i] = X;
        // char *input_in_y = s21_str_calc(char_input_str, &X);
        std::string error = ("ERROR");
        QString qString = QString::fromUtf8(s21_str_calc(char_input_str, &X));
        if (qString.toStdString().find(error) != std::string::npos) {
            QTextStream(stdout) << qString;
            qWarning() << "SAD";
            return;
        }
        y[i] = qString.toDouble(); //Формула нашей функции
        // QTextStream(stdout) << QString::number(y[0]) << "\n";
        i++;
    }
    // QTextStream(stdout) << s21_str_calc(char_input_str, 0) << "\n";
    ui->graph->clearGraphs();//Если нужно, но очищаем все графики

    //Добавляем один график в widget
    ui->graph->addGraph();

    //Говорим, что отрисовать нужно график по нашим двум массивам x и y
    ui->graph->graph(0)->setData(x, y);
    ui->graph->graph(0)->setPen(QColor(50, 50, 50, 255));//задаем цвет точки
    ui->graph->graph(0)->setLineStyle(QCPGraph::lsNone);//убираем линии

    // QTextStream(stdout) << "3\n";
    //формируем вид точек
    ui->graph->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle, 4));

    //Подписываем оси Ox и Oy
    ui->graph->xAxis->setLabel("x");
    ui->graph->yAxis->setLabel("y");

    //Установим область, которая будет показываться на графике
    ui->graph->xAxis->setRange(a, b);//Для оси Ox

    // QTextStream(stdout) << QString::number(y[0]) << "\n";
    //Для показа границ по оси Oy сложнее, так как надо по правильному
    //вычислить минимальное и максимальное значение в векторах
    double minY = data[3]->toDouble(), maxY = data[1]->toDouble();

    ui->graph->yAxis->setRange(minY, maxY);//Для оси Oy

    // QTextStream(stdout) << "5\n";
    //И перерисуем график на нашем widget
    ui->graph->replot();
    ui->graph->show();
}

Graph::~Graph()
{
    delete ui;
}
