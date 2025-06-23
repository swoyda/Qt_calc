#include <math.h>

#include "../s21_main.h"
#include "s21_stack.h"

char *s21_calculate(char *str, double *x) {
  double copy_x = *x;

  int error = 0;
  s21_num_stack_t *num_steck = NULL;
  num_steck = s21_initialise_num_stack(num_steck);
  s21_stack_t *str_stack = NULL;
  str_stack = s21_initialise_str_stack(str_stack);
  for (char *ptr = str; *ptr != '\0' && *ptr != '\n' && !error; ptr++) {
    int shift = 0;
    if (strchr(" ", *ptr)) continue;
    if (strchr(ALL_NUMBERS, *ptr) || strchr("x", *ptr)) {
      num_steck = str_to_num_stack(ptr, num_steck, &shift, &copy_x);
    } else if (strchr(ALL_SIGNS, *ptr)) {
      str_stack = sign_to_str_stack(ptr, str_stack, &shift);
    } else if (strchr(ALL_FUNCTIONS, *ptr)) {
      str_stack = func_to_str_stack(ptr, str_stack, &shift);
    } else if (strchr(ALL_SIMBOLS, *ptr) == NULL)
      error = 1;
    ptr += (shift - 1);
  }

  s21_stack_t *reverse_tokens = NULL;
  reverse_tokens = s21_initialise_str_stack(reverse_tokens);
  while (str_stack->link != NULL) {
    char res[MAX_LEN] = {'\0'};
    s21_peek_tok(str_stack, res);
    str_stack = s21_pop_tok(str_stack);
    reverse_tokens = s21_push_tok(res, reverse_tokens);
  }
  str_stack = s21_pop_tok(str_stack);
  s21_num_stack_t *reverse_numbers = NULL;
  reverse_numbers = s21_initialise_num_stack(reverse_numbers);
  while (num_steck->link != NULL) {
    double res;
    res = s21_peek_num(num_steck);
    num_steck = s21_pop_num(num_steck);
    reverse_numbers = s21_push_num(&res, reverse_numbers);
  }
  num_steck = s21_pop_num(num_steck);
  //  1 - cos
  //  2 - ^
  //  3 - * mod
  //  4 - + -
  //  spec - () sin
  s21_num_stack_t *res_steck = NULL;
  res_steck = s21_initialise_num_stack(res_steck);
  s21_stack_t *res_tokens = NULL;
  res_tokens = s21_initialise_str_stack(res_tokens);
  int prev_was_num = 0;
  for (char *ptr = str; *ptr != '\0' && *ptr != '\n' && !error; ptr++) {
    int shift = 0, stop = 0;
    if (strchr(" ", *ptr)) continue;
    if (strchr("x", *ptr)) {
      prev_was_num = 1;
      double new_res;
      new_res = s21_peek_num(reverse_numbers);
      reverse_numbers = s21_pop_num(reverse_numbers);
      res_steck = s21_push_num(&new_res, res_steck);
    } else if (strchr(ALL_NUMBERS, *ptr)) {
      prev_was_num = 1;
      double new_res;
      new_res = s21_peek_num(reverse_numbers);
      reverse_numbers = s21_pop_num(reverse_numbers);
      res_steck = s21_push_num(&new_res, res_steck);
      for (char *ptr_dop = ptr; *ptr_dop != '\0' && *ptr_dop != '\n' && !stop;
           ptr_dop++) {
        if (strchr(ALL_NUMBERS, *ptr_dop)) {
          shift++;
        } else
          stop = 1;
      }
      shift--;
    } else if (strchr(ALL_SIGNS, *ptr) || strchr("m", *ptr)) {
      if (strchr("m", *ptr)) shift = 2;
      char new_res[5] = {'\0'};
      s21_peek_tok(reverse_tokens, new_res);
      if (!prev_was_num && strchr("-", *ptr)) {
        reverse_numbers->value *= -1;
        reverse_tokens = s21_pop_tok(reverse_tokens);
        continue;
      } else if (!prev_was_num && strchr("+", *ptr)) {
        reverse_tokens = s21_pop_tok(reverse_tokens);
        continue;
      }
      if (res_tokens->link == NULL || strstr(new_res, "(")) {
        res_tokens = s21_push_tok(new_res, res_tokens);
        reverse_tokens = s21_pop_tok(reverse_tokens);
      } else if (strstr(new_res, ")")) {
        shift++;
        char res_top[MAX_LEN] = {'\0'};
        s21_peek_tok(res_tokens, res_top);
        // выпихиваем все до (, чекаем что после не функция
        while (strstr("(", res_top) == NULL) {
          res_steck = from_stack_to_output(res_tokens, res_steck, new_res);
          res_tokens = s21_pop_tok(res_tokens);
          s21_peek_tok(reverse_tokens, new_res);
          s21_peek_tok(res_tokens, res_top);
        }
        res_tokens = s21_pop_tok(res_tokens);  // выпихиваем (

        reverse_tokens = s21_pop_tok(reverse_tokens);  // выпихиваем )

        if (s21_peek_tok(res_tokens, res_top)) {  // смотрим next не NULL
          if (s21_find_func(res_top) != -1) {  // если там функция
            res_steck = func_mini_calc(res_steck, res_top);
            for (char *ptr_dop = ptr;
                 *ptr_dop != '\0' && *ptr_dop != '\n' && !stop; ptr_dop++) {
              if (strchr("(", *ptr_dop)) {
                shift++;
              } else
                stop = 1;
            }
            res_tokens = s21_pop_tok(res_tokens);
          }
        }
        shift--;

      } else {
        char res_top[MAX_LEN] = {'\0'};
        s21_peek_tok(res_tokens, res_top);
        if ((s21_find_sign(res_top) <= s21_find_sign(new_res)) &&
            (strstr("(", res_top) == NULL)) {
          // выпихиваем до new_res пока не станет new_res <= res_top или не (
          while (s21_find_sign(res_top) <= s21_find_sign(new_res) &&
                 (strstr("(", res_top) == NULL) && res_tokens->link != NULL) {
            res_steck = from_stack_to_output(res_tokens, res_steck, new_res);
            res_tokens = s21_pop_tok(res_tokens);
            s21_peek_tok(res_tokens, res_top);
          }

          res_tokens = s21_push_tok(new_res, res_tokens);
          reverse_tokens = s21_pop_tok(reverse_tokens);

        } else {
          res_tokens = s21_push_tok(new_res, res_tokens);
          reverse_tokens = s21_pop_tok(reverse_tokens);
        }
      }
      prev_was_num = 0;
    } else if (strchr(ALL_FUNCTIONS, *ptr)) {
      char new_func[5] = {'\0'};
      s21_peek_tok(reverse_tokens, new_func);
      shift = strlen(new_func) - 1;
      res_tokens = s21_push_tok(new_func, res_tokens);
      reverse_tokens = s21_pop_tok(reverse_tokens);
    } else if (strchr(ALL_SIMBOLS, *ptr) == NULL)
      error = 1;
    ptr += shift;
  }
  while (res_tokens->link != NULL && res_tokens != NULL) {
    res_steck = from_stack_to_output(res_tokens, res_steck, "to_fin");
    res_tokens = s21_pop_tok(res_tokens);
  }

  char *fin_res = (char *)malloc(MAX_LEN * sizeof(char));
  sprintf(fin_res, "%10.8g", res_steck->value);
  // выпихнуть все и 0
  while (num_steck != NULL) {
    num_steck = s21_pop_num(num_steck);
  }
  while (str_stack != NULL) {
    str_stack = s21_pop_tok(str_stack);
  }
  while (res_steck != NULL) {
    res_steck = s21_pop_num(res_steck);
  }
  while (res_tokens != NULL) {
    res_tokens = s21_pop_tok(res_tokens);
  }
  while (reverse_numbers != NULL) {
    reverse_numbers = s21_pop_num(reverse_numbers);
  }
  while (reverse_tokens != NULL) {
    reverse_tokens = s21_pop_tok(reverse_tokens);
  }
  return fin_res;
}

s21_num_stack_t *from_stack_to_output(s21_stack_t *str_top,
                                      s21_num_stack_t *num_top,
                                      char *what_new) {
  if (strstr(ALL_SIGNS, what_new) || strstr("mod", what_new)) {
    char check_top[5] = {'\0'};
    s21_peek_tok(str_top, check_top);
    num_top = mini_calc(num_top, check_top);

  } else if (strstr("to_fin", what_new)) {
    char check_top[5] = {'\0'};
    s21_peek_tok(str_top, check_top);
    num_top = mini_calc(num_top, check_top);
  }
  return num_top;
}

s21_num_stack_t *func_mini_calc(s21_num_stack_t *num_top, char *func) {
  double a, res = 0;

  char only_that_way[5] = {'\0'};
  strcat(only_that_way, func);

  a = s21_peek_num(num_top);
  num_top = s21_pop_num(num_top);

  if (strstr("sin", only_that_way)) {
    res = sinl(a);
  } else if (strstr("cos", only_that_way)) {
    res = cosl(a);
  } else if (strstr("tan", only_that_way)) {
    res = tanl(a);
  } else if (strstr("acos", only_that_way)) {
    res = acosl(a);
  } else if (strstr("asin", only_that_way)) {
    res = asinl(a);
  } else if (strstr("atan", only_that_way)) {
    res = atanl(a);
  } else if (strstr("sqrt", only_that_way)) {
    res = sqrtl(a);
  } else if (strstr("ln", only_that_way)) {
    res = logl(a);
  } else if (strstr("log", only_that_way)) {
    res = log10l(a);
  }
  num_top = s21_push_num(&res, num_top);
  return num_top;
}

s21_num_stack_t *mini_calc(s21_num_stack_t *num_top, char *sign) {
  double a, b, res = 0;
  char only_that_way[5] = {'\0'};
  strcat(only_that_way, sign);

  b = s21_peek_num(num_top);
  num_top = s21_pop_num(num_top);

  a = s21_peek_num(num_top);
  num_top = s21_pop_num(num_top);

  if (*only_that_way == '-') {
    res = a - b;
  } else if (*only_that_way == '+') {
    res = a + b;
  } else if (*only_that_way == '/') {
    res = a / b;
  } else if (*only_that_way == '^') {
    res = powl(a, b);
  } else if (*only_that_way == '*') {
    res = a * b;
  } else if (strstr("mod", sign)) {
    res = fmodl(a, b);
  }

  num_top = s21_push_num(&res, num_top);
  return num_top;
}

s21_num_stack_t *str_to_num_stack(char *str, s21_num_stack_t *top, int *shift,
                                  double *change) {
  *shift = 0;
  double x = 0;
  if (strchr("x", *str)) {
    top = s21_push_num(change, top);
    (*shift)++;
  } else {
    int stop = 0;
    char new_steck[MAX_LEN] = {'\0'};
    for (char *ptr = str; *ptr != '\0' && *ptr != '\n' && !stop; ptr++) {
      if (strchr(ALL_NUMBERS, *ptr)) {
        (*shift)++;
      } else
        stop = 1;
    }
    strncat(new_steck, str, *shift);
    x = strtod(new_steck, NULL);
    top = s21_push_num(&x, top);
  }
  return top;
}

s21_stack_t *func_to_str_stack(char *str, s21_stack_t *top, int *shift) {
  *shift = 0;
  int stop = 0;
  char new_steck[5] = {'\0'};
  for (char *ptr = str; *ptr != '\0' && *ptr != '\n' && !stop; ptr++) {
    if (*ptr != '(' && !strchr(ALL_NUMBERS, *ptr)) {
      (*shift)++;
    } else
      stop = 1;
  }
  strncat(new_steck, str, *shift);
  top = s21_push_tok(new_steck, top);
  return top;
}

s21_stack_t *sign_to_str_stack(char *str, s21_stack_t *top, int *shift) {
  *shift = 1;
  char new_steck[6] = {'\0'};
  strncat(new_steck, str, *shift);
  top = s21_push_tok(new_steck, top);
  return top;
}

void all_out(s21_num_stack_t *top_1, s21_stack_t *top_2) {
  s21_num_stack_t *curr = top_1;
  while (curr != NULL) {
    printf("  %lf\n", curr->value);
    curr = curr->link;
  }
  s21_stack_t *curr_2 = top_2;
  while (curr_2 != NULL && curr_2 != NULL) {
    printf("   %s\n", curr_2->tokens);
    curr_2 = curr_2->link;
  }
  printf("End\n\n");
}
