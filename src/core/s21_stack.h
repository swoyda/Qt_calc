#ifndef S21_STACK
#define S21_STACK

#include <stdlib.h>
#include <string.h>
// добавить только те библиотеки которые нужны
#ifndef INPUT_ERROR
#define INPUT_ERROR 1
#define OK 0
#define MAX_LEN 255
#endif  // INPUT_ERROR
typedef struct s21_stack_tokens s21_stack_t;
typedef struct s21_stack_num s21_num_stack_t;
// typedef struct  {
//   s21_num_stack_t *num_part;
//   s21_stack_t *str_part;
// }stack_sruct;
struct s21_stack_num {
  double value;
  s21_num_stack_t* link;
};

struct s21_stack_tokens {
  char tokens[MAX_LEN];
  s21_stack_t* link;
};

s21_stack_t* s21_initialise_str_stack(s21_stack_t* top);
s21_stack_t* s21_push_tok(char* x, s21_stack_t* top);
s21_stack_t* s21_pop_tok(s21_stack_t* top);
char* s21_peek_tok(s21_stack_t* top, char* result);

s21_num_stack_t* s21_initialise_num_stack(s21_num_stack_t* top);
s21_num_stack_t* s21_push_num(double* x, s21_num_stack_t* top);
s21_num_stack_t* s21_pop_num(s21_num_stack_t* top);
double s21_peek_num(s21_num_stack_t* top);

#endif  // S21_STACK
