#include <math.h>
#include <stdio.h>

#include "../s21_main.h"
// ann. calc

double monthly_payment(double principal, double term, double interest_rate) {
  // double all[3] = {0};
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
  // double contain[2];
  double monthly_payment = 0;
  // printf("Differentiated Payment:\n");
  // for(int month = 1; month <= term; month++) {
  monthly_payment =
      principal_payment +
      (principal - principal_payment * (month - 1)) * monthly_interest_rate;
  total_interest += monthly_payment;
  // printf("Month %d: Payment: %.2f\n", month, monthly_payment);
  // }
  return monthly_payment;
  // total_interest -= principal;

  // printf("Total Interest: %.2f\n", total_interest);
  // printf("Total Payment: %.2f\n", total_paymen);
}

double diff_total_interest(double total_interest, double monthly_payment) {
  return total_interest + monthly_payment;
}
// int main() {
//     double principal;
//     int term;
//     double interest_rate;
//     int payment_type;

//     printf("Enter principal amount: ");
//     scanf("%lf", &principal);
//     printf("Enter loan term in months: ");
//     scanf("%d", &term);
//     printf("Enter annual interest rate (percentage): ");
//     scanf("%lf", &interest_rate);
//     printf("Enter payment type (1 for annuity, 2 for differentiated): ");
//     scanf("%d", &payment_type);

//     if(payment_type == 1) {
//         calculate_annuity(principal, term, interest_rate);
//     } else if(payment_type == 2) {
//         calculate_differentiated(principal, term, interest_rate);
//     } else {
//         printf("Invalid payment type.\n");
//     }

//     return 0;
// }
