#ifndef UNSMART_CALC_BACK
#define UNSMART_CALC_BACK

// #include <iso646.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include <regex.h>

#include "s21_stack.h"

#define ALL_WRONG_1_POS ".*/^)"
#define ALL_SIMBOLS " 1234567890.sincotamdlgxqr()-+*/^"
#define ALL_SIGNS "()-+*/^"
#define ALL_FUNCTIONS "sincotalgmdqr"
#define ALL_NUMBERS "1234567890."
#define NUMBERS_IN "1234567890.x"

void all_out(s21_num_stack_t* top_1, s21_stack_t* top_2);

char* s21_calculate(char* str, double* x);

char* s21_is_valid(char* str);
int s21_is_valid_dots(char* str);
int s21_find_func(char* str);
int s21_is_valid_func(char* str);
int s21_is_valid_parenthesis(char* str);
int s21_is_valid_num_sequence(char* str);

int s21_find_sign(char* str);
s21_num_stack_t* from_stack_to_output(s21_stack_t* str_top,
                                      s21_num_stack_t* num_top, char* what_new);
s21_num_stack_t* mini_calc(s21_num_stack_t* num_top, char* sign);
s21_num_stack_t* func_mini_calc(s21_num_stack_t* num_top, char* func);

s21_num_stack_t* str_to_num_stack(char* str, s21_num_stack_t* top, int* shift,
                                  double* change);
s21_stack_t* func_to_str_stack(char* str, s21_stack_t* top, int* shift);
s21_stack_t* sign_to_str_stack(char* str, s21_stack_t* top, int* shift);
#endif  // UNSMART_CALC_BACK
