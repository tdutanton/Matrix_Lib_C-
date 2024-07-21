#include "../s21_matrix_oop.h"

/**
 * Create default matrix with sizes of 1x1
 */
S21Matrix::S21Matrix() : S21Matrix(1, 1) {}

S21Matrix::S21Matrix(int rows, int cols) {
  if (rows <= 0 || cols <= 0)
    throw std::out_of_range(
        "Number of rows and cols must be greater then zero");
  rows_ = rows;
  cols_ = cols;
  matrix_ = new double*[rows_];
  if (matrix_) {
    bool tmp_flag = true;
    for (int i = 0; i < rows_ && tmp_flag;) {
      matrix_[i] = new double[cols_];
      if (!matrix_[i]) tmp_flag = false;
      for (int j = 0; j < cols_; j++) matrix_[i][j] = 0;
      i++;
    }
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {  // copy
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other)
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {  // move
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}