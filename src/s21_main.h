#ifndef UNSMART_CALC
#define UNSMART_CALC

#include <iso646.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "core/s21_backend.h"

#define MAX_LEN 255
#define INPUT_ERROR 1

char* s21_str_calc(const char* str, double* res);

// long double* s21_graph_calc(const char* str, long double* res);

// double calculate_annuity(double principal, double term, double
// interest_rate); void calculate_differentiated(double principal, int term,
// double interest_rate);
#endif  // UNSMART_CALC
