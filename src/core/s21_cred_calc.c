#include <math.h>
#include <stdio.h>

#include "../s21_main.h"
// ann. calc

double monthly_payment(double principal, double term, double interest_rate) {
  double monthly_interest_rate = interest_rate / 12 / 100;
  return principal *
         (monthly_interest_rate * pow(1 + monthly_interest_rate, term)) /
         (pow(1 + monthly_interest_rate, term) - 1);
}

double total_interest(double monthly_payment, double term) {
  return monthly_payment * term;
}
double total_payment(double total_interest, double principal) {
  return total_interest - principal;
}
// diff. calc

double diff_monthly_payment(double principal, double term, double interest_rate,
                            int month) {
  double monthly_interest_rate = interest_rate / 12 / 100;
  double total_interest = 0;
  double principal_payment = principal / term;
  double monthly_payment = 0;
  monthly_payment =
      principal_payment +
      (principal - principal_payment * (month - 1)) * monthly_interest_rate;
  total_interest += monthly_payment;
  return monthly_payment;
}

double diff_total_interest(double total_interest, double monthly_payment) {
  return total_interest + monthly_payment;
}
