#ifndef CREDITCALC_H
#define CREDITCALC_H
#include <QFontComboBox>

#include <QWidget>

extern "C" {
#include "../../core/s21_cred_calc.h"
}
namespace Ui {
class creditcalc;
}

class creditcalc : public QWidget
{
    Q_OBJECT

public:
    explicit creditcalc(QWidget *parent = nullptr);
    ~creditcalc();

private:
    Ui::creditcalc *ui;
private slots:
    void calc_numbers();
};

#endif // CREDITCALC_H
