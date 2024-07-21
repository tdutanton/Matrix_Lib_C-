#include "../s21_matrix_oop.h"

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows <= 0)
    throw std::out_of_range("Number of rows must be greater than zero");
  S21Matrix tmp(rows, cols_);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp.matrix_[i][j] = (i < rows_) ? matrix_[i][j] : 0;
    }
  }
  *this = std::move(tmp);
}

void S21Matrix::SetCols(int cols) {
  if (cols <= 0)
    throw std::out_of_range("Number of cols must be greater than zero");
  S21Matrix tmp(rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols; j++) {
      tmp.matrix_[i][j] = (j < cols_) ? matrix_[i][j] : 0;
    }
  }
  *this = std::move(tmp);
}
