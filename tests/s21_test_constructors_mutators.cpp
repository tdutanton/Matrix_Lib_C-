#include "s21_tests.h"

TEST(CONSTRUCTORS, SIMPLE_CREATE) {
  S21Matrix test;
  EXPECT_EQ(test.GetRows(), 1);
  EXPECT_EQ(test.GetCols(), 1);
}

TEST(CONSTRUCTORS, R_C_NUMS_1) {
  S21Matrix test(2, 2);
  EXPECT_EQ(test.GetRows() + test.GetCols(), 4);
}

TEST(CONSTRUCTORS, R_C_NUMS_2) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_EQ(test.GetRows() + test.GetCols(), 6);
}

TEST(CONSTRUCTORS, BAD_R_C_NUMS) { EXPECT_ANY_THROW(S21Matrix test(-1, 2)); }

TEST(CONSTRUCTORS, COPY) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix copy(test);
  EXPECT_EQ(copy.GetRows() + copy.GetCols(), 6);
  EXPECT_EQ(test(1, 1), copy(1, 1));
}

TEST(CONSTRUCTORS, COPY_2) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix copy(test);
  EXPECT_TRUE(test == copy);
}

TEST(CONSTRUCTORS, MOVE) {
  TEST_3_X_3_RANGE_MATRIX;
  S21Matrix moved(std::move(test));
  EXPECT_EQ(moved.GetRows() + moved.GetCols(), 6);
  EXPECT_EQ(moved(1, 1), 5);
}

TEST(MUTATORS, SET_ROWS) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_ANY_THROW(test.SetRows(-2));
}

TEST(MUTATORS, SET_ROWS_2) {
  TEST_3_X_3_RANGE_MATRIX;
  test.SetRows(4);
  EXPECT_EQ(test.GetRows(), 4);
}

TEST(MUTATORS, SET_COLS) {
  TEST_3_X_3_RANGE_MATRIX;
  EXPECT_ANY_THROW(test.SetCols(-2));
}

TEST(MUTATORS, SET_COLS_2) {
  TEST_3_X_3_RANGE_MATRIX;
  test.SetCols(4);
  EXPECT_EQ(test.GetCols(), 4);
}