#include <check.h>

#include "../s21_main.h"
double x = 1;
START_TEST(calc_test_plus) {
  // matrix_t matrix_group;
  const char *str = "1.25+3.45";
  char *expected = "       4.7";
  // s21_create_matrix(10, 15, &matrix_group);
  // filter_list_to_matrix(str, &matrix_group);
  char *buff = s21_str_calc(str, &x);
  ck_assert_pstr_eq(expected, buff);
  // s21_remove_matrix(&matrix_group);
  free(buff);
}
END_TEST

START_TEST(calc_test_minus) {
  // // matrix_t matrix_group;
  char *str = "100000*10000";
  char *expected = "     1e+09";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_mult) {
  // // matrix_t matrix_group;
  char *str = "0.25*5";
  char *expected = "      1.25";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_div) {
  // // matrix_t matrix_group;
  char *str = "0.2/5";
  char *expected = "      0.04";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_mod) {
  // // matrix_t matrix_group;
  char *str = "60mod3.5";
  char *expected = "       0.5";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_pow) {
  // // matrix_t matrix_group;
  char *str = "5^3.45";
  char *expected = " 257.89713";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_brackets) {
  // // matrix_t matrix_group;
  char *str = "(5.23+1.25)*(0.25+0.001)";
  char *expected = "   1.62648";
  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_sin) {
  // // matrix_t matrix_group;
  char *str = "sin(0.3*0.6)";
  char *expected = "0.17902957";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_cos) {
  // // matrix_t matrix_group;
  char *str = "cos(0.6-0.1+0.2/0.5)";
  char *expected = "0.62160997";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_tan) {
  // // matrix_t matrix_group;
  char *str = "tan(0.8/2)";
  char *expected = "0.42279322";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_sqrt) {
  // // matrix_t matrix_group;
  char *str = "sqrt(97.3456)";
  char *expected = " 9.8663874";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_ln) {
  // // matrix_t matrix_group;
  char *str = "ln(2.5+99)";
  char *expected = " 4.6200588";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_log) {
  // // matrix_t matrix_group;
  char *str = "log(1.8+256.34)";
  char *expected = " 2.4118553";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_asin) {
  // // matrix_t matrix_group;
  char *str = "asin(0.34)";
  char *expected = " 0.3469169";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_acos) {
  // // matrix_t matrix_group;
  char *str = "acos(-0.83)";
  char *expected = "  2.549904";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_atan) {
  // // matrix_t matrix_group;
  char *str = "atan(-0.669)";
  char *expected = "-0.58961625";
  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
  actual = NULL;
}
END_TEST

START_TEST(calc_test_1) {
  // // matrix_t matrix_group;
  char *str = "1-1";
  char *expected = "         0";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_4) {
  // // matrix_t matrix_group;
  char *str = "sin(0.1)";
  char *expected = "0.099833417";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

START_TEST(calc_test_5) {
  // // matrix_t matrix_group;
  char *str = "cos(sin(tan(-0.005)))";
  char *expected = " 0.9999875";

  // // s21_create_matrix(10, 15, &matrix_group);
  // // filter_list_to_matrix(str, &matrix_group);
  char *actual = s21_str_calc(str, &x);
  ck_assert_str_eq(expected, actual);
  // // s21_remove_matrix(&matrix_group);
  free(actual);
}
END_TEST

int main() {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, calc_test_plus);
  tcase_add_test(tc1_1, calc_test_minus);
  tcase_add_test(tc1_1, calc_test_mult);
  tcase_add_test(tc1_1, calc_test_div);
  tcase_add_test(tc1_1, calc_test_mod);
  tcase_add_test(tc1_1, calc_test_pow);
  tcase_add_test(tc1_1, calc_test_brackets);
  tcase_add_test(tc1_1, calc_test_sin);
  tcase_add_test(tc1_1, calc_test_cos);
  tcase_add_test(tc1_1, calc_test_tan);
  tcase_add_test(tc1_1, calc_test_sqrt);
  tcase_add_test(tc1_1, calc_test_ln);
  tcase_add_test(tc1_1, calc_test_log);
  tcase_add_test(tc1_1, calc_test_asin);
  tcase_add_test(tc1_1, calc_test_acos);
  tcase_add_test(tc1_1, calc_test_atan);
  tcase_add_test(tc1_1, calc_test_1);
  tcase_add_test(tc1_1, calc_test_4);
  tcase_add_test(tc1_1, calc_test_5);
  // tcase_add_test(tc1_1, calc_test_null);

  SRunner *sr = srunner_create(s1);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);

  return 0;
}
