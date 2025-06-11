#include "depositcalc.h"
#include "ui_depositcalc.h"

depositcalc::depositcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::depositcalc)
{
    ui->setupUi(this);
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(calc_numbers()));
}

depositcalc::~depositcalc()
{
    delete ui;
}
void depositcalc::calc_numbers() {
    QString type = ui->type_comboBox_2->currentText();
    QString data = ui->convert_to_comboBox_2->currentText();

    QString input_str = ui->input_show->text();
    QString data_input_str = ui->data_show->text();
    QString percent_input_str = ui->percent_show->text();

//    double principal = input_str.toDouble();
    double term = data_input_str.toDouble();
//    double interest_rate = percent_input_str.toDouble();

    std::string std_input_str = type.toStdString();
    std::string std_data_input_str = data.toStdString();
    if (std_data_input_str.find("г") != std::string::npos) {
        term *= 12;
    }
    else if(std_data_input_str.find("д") != std::string::npos)
    {
        term /= 30;
    }

}
