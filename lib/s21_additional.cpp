#include "../s21_matrix_oop.h"

bool CompareMatrixElements(double a, double b) {
  return (fabs(a - b) > ACCURACY) ? false : true;
}

double DeterminantOfTwo(const S21Matrix& matrix) {
  return (matrix(0, 0) * matrix(1, 1) - matrix(1, 0) * matrix(0, 1));
}

double DeterminantOfTriangle(const S21Matrix& matrix) {
  double pos_part = matrix(0, 0) * matrix(1, 1) * matrix(2, 2) +
                    matrix(1, 0) * matrix(0, 2) * matrix(2, 1) +
                    matrix(0, 1) * matrix(1, 2) * matrix(2, 0);
  double neg_part = matrix(0, 2) * matrix(1, 1) * matrix(2, 0) +
                    matrix(0, 1) * matrix(1, 0) * matrix(2, 2) +
                    matrix(1, 2) * matrix(2, 1) * matrix(0, 0);
  return pos_part - neg_part;
}

S21Matrix UpperTriangleMatrix(const S21Matrix& matrix, int* det_sign) {
  S21Matrix tmp = matrix;
  int swap_count = 0;
  for (int i = 1; i < tmp.GetRows(); i++) {
    for (int j = i; j < tmp.GetCols(); j++) {
      if (fabs(tmp(j, i - 1)) > ACCURACY) {
        if (fabs(tmp(i - 1, i - 1)) < ACCURACY) {
          SwapRows(tmp, i - 1, j);
          swap_count++;
        }
        double delta = tmp(j, i - 1) / tmp(i - 1, i - 1) * -1;
        AddMultingRow(tmp, j, i - 1, delta);
        tmp(j, i - 1) = 0;
      }
    }
  }
  *det_sign = (swap_count % 2 == 0) ? 1 : -1;
  return tmp;
}

void SwapRows(S21Matrix& matrix, int row_1, int row_2) {
  for (int i = 0; i < matrix.GetCols(); i++) {
    double temp = matrix(row_1, i);
    matrix(row_1, i) = matrix(row_2, i);
    matrix(row_2, i) = temp;
  }
}

void AddMultingRow(S21Matrix& matrix, int row_give, int row_take, double mult) {
  for (int i = 0; i < matrix.GetCols(); i++) {
    matrix(row_give, i) += matrix(row_take, i) * mult;
  }
}

S21Matrix OneMinorMatrix(int row, int col, S21Matrix& matrix) {
  S21Matrix result(matrix.GetRows() - 1, matrix.GetCols() - 1);
  int minor_row = 0;
  for (int i = 0; i < matrix.GetRows(); i++) {
    if (i == row - 1) continue;
    int minor_col = 0;
    for (int j = 0; j < matrix.GetCols(); j++) {
      if (j == col - 1) continue;
      result(minor_row, minor_col) = matrix(i, j);
      minor_col++;
    }
    minor_row++;
  }
  return result;
}

// If you want to print some matrix - uncomment it
/* void PrintMatrix(const S21Matrix& tmp) {
  int rows_t = tmp.GetRows();
  int cols_t = tmp.GetCols();
  for (int i = 0; i < rows_t; i++) {
    for (int j = 0; j < cols_t; j++) {
      std::cout << tmp(i, j) << " ";
    }
    std::cout << "\n";
  }
} */