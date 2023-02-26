#include "s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int res = 0;
  copy_decimal(value, result);
  set_sign(result, !get_sign(value));
  return res;
}
