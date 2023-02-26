#include "s21_decimal.h"

int s21_is_less(s21_decimal value_1, s21_decimal value_2) {
  int res = 0;
  int sign1 = get_sign(value_1);
  int sign2 = get_sign(value_2);
  big_decimal tmp_1 = {0};
  big_decimal tmp_2 = {0};
  convert_to_big(value_1, &tmp_1);
  convert_to_big(value_2, &tmp_2);

  if (sign1 ^ sign2) {
    if (sign1 == 1 && check_if_zero(value_1) == 0 &&
        check_if_zero(value_2) == 0) {
      res = 1;
    }
  } else {
    normalize_big(&tmp_1, &tmp_2);
    // 0 - equal, 1 - first greater, 2 - second greater
    int compare = big_compare_bits(tmp_1, tmp_2);
    if (sign1 == 1) {
      if (compare == 1) {
        res = 1;
      }
    } else if (sign1 == 0) {
      if (compare == 2) {
        res = 1;
      }
    }
  }
  return res;
}
