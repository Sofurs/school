#pragma once

#include <fstream>
#include <iostream>

class Matrix {
   public:
    Matrix();
    Matrix(std::fstream *myFile);
    Matrix(int row, int col);
    Matrix(const Matrix &);
    ~Matrix();

    void printSize() const;
    void printMatrix() const;

    int getMatrixRows() const;
    int getMatrixCols() const;

    void swapRows(int **&arr, int row1, int row2);
    void swapCols(int **&arr, int row1, int row2);

    Matrix operator=(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);

   protected:
    int **matrix;
    int matrixRows;
    int matrixCols;

    void initMatrix(int **&arr);
    void initMatrix(int **&arr, int rows, int cols);
};