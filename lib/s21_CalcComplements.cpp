#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) throw std::invalid_argument("Matrix must be square");
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix Minor = OneMinorMatrix(i + 1, j + 1, *this);
      double minor = Minor.Determinant();
      result.matrix_[i][j] = pow(-1, i + j) * minor;
    }
  }
  return result;
}