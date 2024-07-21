#include "s21_tests.h"

TEST(INVERSE, INVERSE_BAD) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_ANY_THROW(S21Matrix check = test.InverseMatrix());
}

TEST(INVERSE, INVERSE_GOOD) {
  S21Matrix test(3, 3);
  test(0, 0) = 2;
  test(0, 1) = 5;
  test(0, 2) = 7;
  test(1, 0) = 6;
  test(1, 1) = 3;
  test(1, 2) = 4;
  test(2, 0) = 5;
  test(2, 1) = -2;
  test(2, 2) = -3;

  S21Matrix res = test.InverseMatrix();
  S21Matrix check(3, 3);

  check(0, 0) = 1;
  check(0, 1) = -1;
  check(0, 2) = 1;
  check(1, 0) = -38;
  check(1, 1) = 41;
  check(1, 2) = -34;
  check(2, 0) = 27;
  check(2, 1) = -29;
  check(2, 2) = 24;

  EXPECT_EQ(res(1, 1), check(1, 1));
}