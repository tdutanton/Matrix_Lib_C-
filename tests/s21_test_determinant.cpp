#include "s21_tests.h"

TEST(DETERMINANT, C_R_1) {
  S21Matrix test(1, 1);
  test(0, 0) = 1;
  double check = test.Determinant();
  EXPECT_EQ(test(0, 0), check);
}

TEST(DETERMINANT, C_R_4) {
  S21Matrix test(4, 4);

  test(0, 0) = 0;
  test(0, 1) = 1;
  test(0, 2) = 3;
  test(0, 3) = 1;
  test(1, 0) = 10;
  test(1, 1) = 56;
  test(1, 2) = 4;
  test(1, 3) = 8;
  test(2, 0) = 9;
  test(2, 1) = 10;
  test(2, 2) = 23;
  test(2, 3) = 4;
  test(3, 0) = 6;
  test(3, 1) = 4;
  test(3, 2) = 5;
  test(3, 3) = 9;

  double check = test.Determinant();
  double check_manual = -13522;
  EXPECT_DOUBLE_EQ(check_manual, check);
}