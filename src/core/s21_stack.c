#include "s21_stack.h"

#include "s21_backend.h"
// стэк для токенов

s21_stack_t* s21_initialise_str_stack(s21_stack_t* top) {
  top = malloc(sizeof(s21_stack_t));
  if (top == NULL) {
    return NULL;
  }
  // strcat(top->tokens, "");
  top->link = NULL;
  return top;
}

s21_stack_t* s21_push_tok(char* x, s21_stack_t* top) {
  s21_stack_t* new_pos = malloc(sizeof(s21_stack_t));
  strcpy(new_pos->tokens, x);
  new_pos->link = top;
  return new_pos;
}

s21_stack_t* s21_pop_tok(s21_stack_t* top) {
  if (top == NULL) {
    return NULL;
  } else {
    s21_stack_t* temp;
    temp = top;
    // free(top -> tokens);
    // top -> tokens = NULL;

    if (top->link == NULL) {
      free(top);
      top = NULL;
    } else {
      temp = top->link;
      free(top);
      top = temp;
    }
    return top;
  }
}

char* s21_peek_tok(s21_stack_t* top, char* result) {
  if (top->link != NULL) {
    strcpy(result, top->tokens);
  } else {
    result = NULL;
  }
  return result;
}

// стэк для чисел
s21_num_stack_t* s21_initialise_num_stack(s21_num_stack_t* top) {
  top = (s21_num_stack_t*)malloc(sizeof(s21_num_stack_t));
  if (top == NULL) {
    return NULL;
  }
  top->link = NULL;
  top->value = 0;
  return top;
}

s21_num_stack_t* s21_push_num(double* x, s21_num_stack_t* top) {
  s21_num_stack_t* new_pos = malloc(sizeof(s21_num_stack_t));
  new_pos->link = top;
  new_pos->value = *x;
  return new_pos;
}

s21_num_stack_t* s21_pop_num(s21_num_stack_t* top) {
  if (top == NULL) {
    return NULL;
  } else {
    s21_num_stack_t* temp;
    temp = top;
    if (top->link == NULL) {
      free(top);
      top = NULL;
    } else {
      temp = top->link;
      free(top);
      top = NULL;
      top = temp;
    }
    return top;
  }
}

double s21_peek_num(s21_num_stack_t* top) {
  double res = top->value;
  return res;
}