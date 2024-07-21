#include "../s21_matrix_oop.h"

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.cols_ || cols_ != other.rows_)
    throw std::invalid_argument("Both matrix must be the same size");
  S21Matrix result(rows_, other.cols_);
  for (int i = 0; i < result.rows_; i++) {
    for (int j = 0; j < result.cols_; j++) {
      int k = 0;
      while (k < cols_) {
        result.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
        k++;
      }
    }
  }
  *this = result;
}