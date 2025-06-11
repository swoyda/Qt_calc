#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "../../s21_main.h"
// #include "settingsgraph.h"
MainWindow::MainWindow(settingsGraph *settingsGraph, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // settingsGraph S_window = new settingsgraph;
    settingsgraph = settingsGraph;
    CreditCalc = new class creditcalc();
    DepositCalc = new class depositcalc();
    settingsgraph = new class settingsGraph();
    QVector<QPushButton*> allButtons;
    allButtons = { ui->pushButton_0, ui->pushButton_1,ui->pushButton_2,
                   ui->pushButton_3, ui->pushButton_4, ui->pushButton_5,
                   ui->pushButton_6, ui->pushButton_7, ui->pushButton_8,
                   ui->pushButton_9, ui->dottButton, ui->plusButton,
                   ui->minusButton, ui->divButton, ui->degreeButton,
                   ui->sinButton, ui->cosButton, ui->tanButton, ui->cotButton,
                   ui->atanButton, ui->asinButton, ui->acosButton, ui->sqrtButton,
                   ui->lnButton, ui->logButton, ui->modButton, ui->multButton,
                   ui->leftBButton, ui->rightBButton, ui->eqButton, ui->clearButton,
                   ui->deleatButton
    };
    for (auto dtb : allButtons) {
        connect(dtb,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    }
    connect(ui->creditButton,SIGNAL(clicked()),this,SLOT(open_credit_calc()));
    connect(ui->depositButton,SIGNAL(clicked()),this,SLOT(open_deposit_calc()));
    // connect(ui->eqButton, &settingsGraph::sendData, this, &MainWindow::receiveData);
    connect(settingsgraph , &settingsGraph::sendData, this, &MainWindow::receiveData);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::open_deposit_calc() {
    DepositCalc->show();
}
void MainWindow::open_credit_calc() {
    CreditCalc->show();
}

void MainWindow::digits_numbers()
{
    QPushButton *button = (QPushButton*)sender();

    QString new_label, input_str;
    new_label = button->text();
    if (new_label == "=") {
        input_str = ui->result_show->text();
        std::string std_input_str = input_str.toStdString();
        int len = input_str.size();
        if (len < 256) {

            const char* char_input_str = std_input_str.c_str();
            if (std_input_str.find("x") != std::string::npos) {
                connect(settingsgraph , &settingsGraph::sendData, this, &MainWindow::receiveData);

            } else {
                double a = 1;
                char* char_output_str = s21_str_calc(char_input_str, &a);
                ui->result_show->setText(char_output_str);
            }
        } else {
            ui->result_show->setText("TOO_LONG");
        }
    }
    else if (new_label == "c")
    {
        input_str = "";
        ui->result_show->setText(input_str);
    }
    else if (new_label == "<-")
    {
        input_str = ui->result_show->text();
        input_str.chop(1);
        ui->result_show->setText(input_str);
    }
    else {
        input_str = ui->result_show->text() + new_label;

        ui->result_show->setText(input_str);
    }

    // ui->result_show->
    // QTextStream(stdout) << input_str + "\n";
}

void MainWindow::receiveData(QString *data[6]) {

    QString input_str = ui->result_show->text();
    data[5] = &input_str;
    emit sendData(data);
}

void MainWindow::on_GSettingsButton_clicked()
{
    settingsgraph->show();
}

