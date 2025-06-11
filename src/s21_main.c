#include "s21_main.h"

char* s21_str_calc(const char* str, double* res) {
  char* error = "0";
  // printf("ayaya\n");
  if (!str || res == NULL) return "INPUT_ERROR";
  char str_new[MAX_LEN + 2] = {'\0'};
  strcpy(str_new, str);

  // printf("%s   %lf\n", str, *res);
  // *res = 0;
  char input[MAX_LEN + 1] = {'\0'};
  strncpy(input, str_new, MAX_LEN);
  // input[strlen(str) + 1] = '\0';
  error = s21_is_valid(input);
  if (strstr(error, "0")) {
    error = s21_calculate(input, res);
  }
  // printf("%s\n", error);
  return error;
}

// double* s21_graph_calc(const char* str, double* res) {

//     if (!str || res != NULL) return 0;

//     char* error = "0";
//     double* fin = 0;
//     char str_new[MAX_LEN+2] = {'\0'};
//     strcpy(str_new, str);
//     char input[MAX_LEN + 1] = {'\0'};
//     strncpy(input, str_new, MAX_LEN);
//     error = s21_is_valid(input);
//     double *dop_res = res;
//     if (strstr(error, "0")) {
//         sprintf(fin, "%30Lf", s21_calculate(input, dop_res));
//         // *fin = strtod(s21_calculate(input, dop_res), NULL);
//     }
//     return fin;
// }