// #include <stdio.h>
// #include <stdlib.h>

// double calculate_interest(double amount, double rate, int term, int
// capitalization) {
//     double interest = 0;
//     for (int i = 0; i < term; i++) {
//         if (capitalization) {
//             // Капитализация процентов
//             interest += amount * rate / 12 / 100;
//             amount += interest;
//         } else {
//             // Простые проценты
//             interest += amount * rate / 12 / 100;
//         }
//     }
//     return interest;
// }

// double calculate_tax(double interest, double tax_rate) {
//     return interest * tax_rate / 100;
// }

// int main() {
//     double deposit, rate, tax_rate;
//     int term, capitalization;
//     // Ввод основных параметров
//     printf("Enter deposit amount: ");
//     scanf("%lf", &deposit);
//     printf("Enter term in months: ");
//     scanf("%d", &term);
//     printf("Enter annual interest rate (percentage): ");
//     scanf("%lf", &rate);
//     printf("Enter tax rate (percentage): ");
//     scanf("%lf", &tax_rate);
//     printf("Enter capitalization (1 for yes, 0 for no): ");
//     scanf("%d", &capitalization);

//     // Расчёт процентов и налога
//     double interest = calculate_interest(deposit, rate, term,
//     capitalization); double tax = calculate_tax(interest, tax_rate); double
//     final_amount = deposit + interest - tax;

//     printf("Accrued Interest: %.2f\n", interest);
//     printf("Tax Amount: %.2f\n", tax);
//     printf("Final Amount: %.2f\n", final_amount);

//     return 0;
// }
