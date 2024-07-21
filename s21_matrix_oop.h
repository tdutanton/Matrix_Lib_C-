#ifndef S21_MATRIX_OOP_H
#define S21_MATRIX_OOP_H

#include <cmath>
#include <iostream>

#define ACCURACY 1.0E-7

class S21Matrix {
 private:
  // attributes
  int rows_, cols_;  // rows and columns attributes
  double** matrix_;  // pointer to the memory where the matrix will be allocated

 public:
  // constructors
  S21Matrix();  // Базовый конструктор, инициализирующий матрицу некоторой
                // заранее заданной размерностью.
  S21Matrix(int rows, int cols);  // Параметризированный конструктор с
                                  // количеством строк и столбцов.
  S21Matrix(const S21Matrix& other);  // Конструктор копирования.
  S21Matrix(S21Matrix&& other);  // Конструктор переноса.
                                 // destructor
  ~S21Matrix();

  // matrix operations
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // operators overloads
  S21Matrix operator+(
      const S21Matrix&
          other);  // Сложение двух матриц !!Различная размерность матриц!!
  S21Matrix operator-(
      const S21Matrix& other);  // Вычитание одной матрицы из другой !!Различная
                                // размерность матриц!!
  S21Matrix operator*(
      const S21Matrix& other);  // Умножение матриц !!Число столбцов первой
                                // матрицы не равно числу строк второй матрицы!!
  S21Matrix operator*(const double num);  // Умножение матрицы на число
  bool operator==(
      const S21Matrix& other);  // Проверка на равенство матриц (EqMatrix)
  S21Matrix& operator=(
      const S21Matrix& other);  // Присвоение матрице значений другой матрицы
  S21Matrix& operator+=(
      const S21Matrix& other);  // Присвоение сложения (SumMatrix) !!Различная
                                // размерность матриц!!
  S21Matrix& operator-=(
      const S21Matrix& other);  // Присвоение разности (SubMatrix) !!Различная
                                // размерность матриц!!
  S21Matrix& operator*=(
      const S21Matrix& other);  // Присвоение умножения на матрицу (MulMatrix)
                                // !!Число столбцов первой матрицы не равно
                                // числу строк второй матрицы!!
  S21Matrix& operator*=(
      const double num);  // Присвоение умножения на число (MulNumber)
  double& operator()(int row,
                     int col);  // Индексация по элементам матрицы (строка,
                                // колонка) !!Индекс за пределами матрицы!!
  double& operator()(int row, int col)
      const;  // Для вывода (без возможности изменения элементов)

  // accessors and mutators
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);
};

bool CompareMatrixElements(double a, double b);
double DeterminantOfTwo(const S21Matrix& matrix);
double DeterminantOfTriangle(const S21Matrix& matrix);
S21Matrix UpperTriangleMatrix(const S21Matrix& matrix, int* det_sign);
void SwapRows(S21Matrix& matrix, int row_1, int row_2);
void AddMultingRow(S21Matrix& matrix, int row_give, int row_take, double mult);
S21Matrix OneMinorMatrix(int row, int col, S21Matrix& matrix);

// void PrintMatrix(const S21Matrix& tmp); - if You want print matrix -
// uncomment it!

#endif