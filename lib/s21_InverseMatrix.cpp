#include "../s21_matrix_oop.h"

S21Matrix S21Matrix::InverseMatrix() {
  double det = this->Determinant();
  if (fabs(det) < ACCURACY)
    throw std::invalid_argument("Bad matrix! Determinant is equals Zero!");
  S21Matrix result(*this);
  result = result.CalcComplements();
  result = result.Transpose();
  result.MulNumber(-1);
  return result;
}