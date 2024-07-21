#include "../s21_matrix_oop.h"

double S21Matrix::Determinant() {
  if (rows_ != cols_) throw std::invalid_argument("Matrix must be square");
  double result = 1;
  if (rows_ == 1)
    result = matrix_[0][0];
  else if (rows_ == 2)
    result = DeterminantOfTwo(*this);
  else if (rows_ == 3)
    result = DeterminantOfTriangle(*this);
  else {
    int sign = 0;
    S21Matrix tmp = UpperTriangleMatrix(*this, &sign);
    for (int i = 0; i < rows_; i++) {
      result *= tmp(i, i);
    }
    result *= sign;
  }
  return result;
}