#include "settingsgraph.h"
#include "ui_settingsgraph.h"

settingsGraph::settingsGraph(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::settingsGraph)
{
    ui->setupUi(this);
    connect(ui->startButton, &QPushButton::clicked, this, &settingsGraph::compile_graph);
    connect(ui->defaultButton,SIGNAL(clicked()),this,SLOT(default_graph()));
    connect(ui->clearButton,SIGNAL(clicked()),this,SLOT(clear_graph()));
}

settingsGraph::~settingsGraph()
{
    delete ui;
}

void settingsGraph::clear_graph() {
    ui->x_show->setText("");
    ui->y_show->setText("");
    ui->minus_x_show->setText("");
    ui->minus_y_show->setText("");
    ui->steps_show->setText("");
}

void settingsGraph::default_graph() {

    double x;
    double minus_x;
    double y;
    double minus_y;
    double steps;

    x = 5;
    minus_x = -5;
    y = 5;
    minus_y = -5;

    steps = 0.5;

    QString x_str = QString::number(x);
    ui->x_show->setText(x_str);
    QString y_str = QString::number(y);
    ui->y_show->setText(y_str);
    QString minus_x_str = QString::number(minus_x);
    ui->minus_x_show->setText(minus_x_str);
    QString minus_y_str = QString::number(minus_y);
    ui->minus_y_show->setText(minus_y_str);
    QString steps_str = QString::number(steps);
    ui->steps_show->setText(steps_str);
}

void settingsGraph::compile_graph() {
    double x =  ui->x_show->text().toDouble();
    double minus_x =  ui->minus_x_show->text().toDouble();
    double y =  ui->y_show->text().toDouble();
    double minus_y =  ui->minus_y_show->text().toDouble();
    double steps = ui->steps_show->text().toDouble();
    if (!x || !minus_x || !y || !minus_y || x == minus_x || y == minus_y)
    {
        x = 5;
        minus_x = -5;
        y = 5;
        minus_y = -5;
    }
    if (!steps) {
        steps = 0.5;
    }
    if (steps < 0)
    {
        steps *= -1;
    }
    QString x_str = QString::number(x);
    ui->x_show->setText(x_str);
    QString y_str = QString::number(y);
    ui->y_show->setText(y_str);
    QString minus_x_str = QString::number(minus_x);
    ui->minus_x_show->setText(minus_x_str);
    QString minus_y_str = QString::number(minus_y);
    ui->minus_y_show->setText(minus_y_str);
    QString steps_str = QString::number(steps);
    ui->steps_show->setText(steps_str);
    QString empty = "";
    QString *all[6];
    all[0] = &x_str;
    all[1] = &y_str;
    all[2] = &minus_x_str;
    all[3] = &minus_y_str;
    all[4] = &steps_str;
    all[5] = &empty;
    emit sendData(all);
}


