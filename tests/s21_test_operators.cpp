#include "s21_tests.h"

TEST(OPERATORS, INDEX_1) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_ANY_THROW(test(-1, 2));
}

TEST(OPERATORS, INDEX_2) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_EQ(test(1, 1), 5);
}

TEST(OPERATORS, INDEX_3) {
  TEST_3_X_3_RANGE_MATRIX;
  test(1, 1) = 10;
  EXPECT_EQ(test(1, 1), 10);
}

TEST(OPERATORS, INDEX_CONST) {
  const TEST_3_X_3_RANGE_MATRIX;
  EXPECT_EQ(test(1, 1), 5);
}

TEST(OPERATORS, INDEX_CONST_BAD) {
  const TEST_3_X_3_RANGE_MATRIX;
  EXPECT_ANY_THROW(test(-1, 2));
}

TEST(OPERATORS, INDEX_CONST_BAD_2) {
  const TEST_3_X_3_RANGE_MATRIX;
  test(1, 2) = 10;
  EXPECT_EQ(test(1, 1), 5);
}

TEST(OPERATORS, EQUAL) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test;
  EXPECT_TRUE(check.EqMatrix(test));
}

TEST(OPERATORS, PLUS) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix test_2 = test;
  S21Matrix check = test_2 + test;
  EXPECT_TRUE(check(1, 1) == 10);
  EXPECT_EQ(check(0, 0), 2);
}

TEST(OPERATORS, PLUS_BAD) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix test_2(2, 3);
  EXPECT_ANY_THROW(S21Matrix check = test_2 + test);
}

TEST(OPERATORS, PLUS_EQUAL) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test;
  check += test;
  EXPECT_TRUE(check(1, 1) == 10);
  EXPECT_EQ(check(0, 0), 2);
}

TEST(OPERATORS, MINUS) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix test_2 = test;
  S21Matrix check = test_2 - test;
  EXPECT_TRUE(check(1, 1) == 0);
  EXPECT_EQ(check(0, 0), 0);
}

TEST(OPERATORS, MINUS_EQUAL) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test;
  check -= test;
  EXPECT_TRUE(check(1, 1) == 0);
  EXPECT_EQ(check(0, 0), 0);
}

TEST(OPERATORS, MULT_M) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix test_2 = test;
  S21Matrix check = test_2 * test;
  EXPECT_TRUE(check(1, 1) == 81);
  EXPECT_EQ(check(0, 0), 30);
}

TEST(OPERATORS, MULT_M_BAD) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix test_2(2, 1);
  EXPECT_ANY_THROW(S21Matrix check = test_2 * test);
}

TEST(OPERATORS, MULT_NUM) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test * 2;
  EXPECT_TRUE(check(1, 1) == 10);
  EXPECT_EQ(check(0, 0), 2);
}

TEST(OPERATORS, MULT_M_EQUAL) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test;
  check *= test;
  EXPECT_TRUE(check(1, 1) == 81);
  EXPECT_EQ(check(0, 0), 30);
}

TEST(OPERATORS, MULT_NUM_EQUAL) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix check = test;
  check *= 2;
  EXPECT_TRUE(check(1, 1) == 10);
  EXPECT_EQ(check(0, 0), 2);
}