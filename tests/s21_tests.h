#ifndef S21_MATRIX_OOP_TESTS_H
#define S21_MATRIX_OOP_TESTS_H

#include <gtest/gtest.h>

#include "../s21_matrix_oop.h"

#define TEST_3_X_3_RANGE_MATRIX \
  S21Matrix test(3, 3);         \
  test(0, 0) = 1;               \
  test(0, 1) = 2;               \
  test(0, 2) = 3;               \
  test(1, 0) = 4;               \
  test(1, 1) = 5;               \
  test(1, 2) = 6;               \
  test(2, 0) = 7;               \
  test(2, 1) = 8;               \
  test(2, 2) = 9;

#endif