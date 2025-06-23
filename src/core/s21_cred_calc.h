#ifndef CRED_CALC
#define CRED_CALC

#include <math.h>
#include <stdio.h>

#include "../s21_main.h"

double monthly_payment(double principal, double term, double interest_rate);
double total_interest(double monthly_payment, double term);
double total_payment(double total_interest, double principal);

double diff_monthly_payment(double principal, double term, double interest_rate,
                            int month);
double diff_total_interest(double total_interest, double monthly_payment);

#endif  // CRED_CALC
