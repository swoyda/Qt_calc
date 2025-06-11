#ifndef CRED_CALC
#define CRED_CALC

#include <math.h>
#include <stdio.h>

#include "../s21_main.h"

// #define ALL_WRONG_1_POS ".*/^)"
// #define ALL_SIMBOLS " 1234567890.sincotamdlgx()-+*/^"
// #define ALL_SIGNS "()-+*/^"
// #define ALL_FUNCTIONS "sincotalgm"
// #define ALL_NUMBERS "1234567890."
// #define NUMBERS_IN "1234567890.x"

double monthly_payment(double principal, double term, double interest_rate);
double total_interest(double monthly_payment, double term);
double total_payment(double total_interest, double principal);

double diff_monthly_payment(double principal, double term, double interest_rate,
                            int month);
double diff_total_interest(double total_interest, double monthly_payment);

#endif  // CRED_CALC
