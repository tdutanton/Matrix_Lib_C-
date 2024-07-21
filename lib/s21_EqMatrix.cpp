#include "../s21_matrix_oop.h"

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = false;
  if (rows_ == other.rows_ && cols_ == other.cols_) {
    result = true;
    for (int i = 0; i < rows_ && result; i++) {
      for (int j = 0; j < cols_ && result; j++) {
        result = CompareMatrixElements(matrix_[i][j], other.matrix_[i][j]);
      }
    }
  }
  return result;
}