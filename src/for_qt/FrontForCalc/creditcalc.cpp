#include "creditcalc.h"
#include "ui_creditcalc.h"

#include <QFontComboBox>
#include <QVBoxLayout>
creditcalc::creditcalc(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::creditcalc)
{
    ui->setupUi(this);
    connect(ui->startButton,SIGNAL(clicked()),this,SLOT(calc_numbers()));
}

creditcalc::~creditcalc()
{
    delete ui;
}

void creditcalc::calc_numbers() {
    QString type = ui->type_comboBox->currentText();
    QString data = ui->convert_to_comboBox->currentText();

    QString input_str = ui->input_show->text();
    QString data_input_str = ui->data_show->text();
    QString percent_input_str = ui->percent_show->text();

    double principal = input_str.toDouble();
    double term = data_input_str.toDouble();
    double interest_rate = percent_input_str.toDouble();

    std::string std_input_str = type.toStdString();
    std::string std_data_input_str = data.toStdString();
    if (std_data_input_str.find("г") != std::string::npos) {
        term *= 12;
    }
    else if(std_data_input_str.find("д") != std::string::npos)
    {
        term /= 30;
    }
    if (std_input_str.find("анну") != std::string::npos) {

        double double_output = 0, double_output_2 = 0, double_output_3 = 0;
        double_output = monthly_payment(principal, term, interest_rate);
        double_output_2 = total_interest(double_output, term);
        double_output_3 = total_payment(double_output_2, principal);
        ui->res_monthly_show->setText(QString::number(double_output));
        ui->overpayment_show->setText(QString::number(double_output_2));
        ui->total_payout_show->setText(QString::number(double_output_3));
    } else {
        ui->graph->clearGraphs();
        int month = 1;
        QVector<double> x((int)term), y((int)term);
        // QTextStream(stdout) << QString::number((int)term);
        double total_interest = 0 ;
        // y[0] = 0;
        for(; month <= (int)term; month++)
        {
            x[month - 1] = month;
            y[month - 1] = diff_monthly_payment(principal, term, interest_rate, month);
            // QTextStream(stdout) << QString::number(y[month - 1]) << "\n";
            total_interest = diff_total_interest(total_interest, y[month - 1]); // arr[month]
        }
        double total_payment = total_interest;
        total_interest -= principal;
        ui->res_monthly_show->setText("Check graph");
        ui->overpayment_show->setText(QString::number(total_payment));
        ui->total_payout_show->setText(QString::number(total_interest));

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
        ui->graph->xAxis->setLabel("Months");
        ui->graph->yAxis->setLabel("Total payment");
        //Установим область, которая будет показываться на графике
        ui->graph->xAxis->setRange(0, month);//Для оси Ox

        //Для показа границ по оси Oy сложнее, так как надо по правильному
        //вычислить минимальное и максимальное значение в векторах
        double minY = 0, maxY = y[0] + total_interest;

        ui->graph->yAxis->setRange(minY, maxY);//Для оси Oy

        // QTextStream(stdout) << "5\n";
        //И перерисуем график на нашем widget
        ui->graph->replot();
        ui->graph->show();
    }
}

// void MainWindow::updateFont()
// {
//     QFont currentFont = ui->textEdit->currentFont();

//     currentFont->setFamily(ui->fontComboBox->currentText());
//     currentFont->setItalic(ui->italicCheckBox->isChecked());
//     currentFont->setPointSize(ui->sizeSpinBox->value());

//     // устанавливаем остальные свойства

//     textEdit->setCurrentFont(currentFont);
// }
