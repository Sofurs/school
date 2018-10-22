#pragma once

#include <fstream>
#include <iostream>

class Matrix {
   public:
    Matrix();
    Matrix(int row, int col);
    Matrix(std::string name);
    ~Matrix();

    Matrix(const Matrix &);

    bool isFileOpen() const;

    void getSize();
    void printSize() const;

    void initMatrix(int rows = 0, int cols = 0);

    void fillMatrix();
    void printMatrix() const;

    Matrix operator=(const Matrix &);
    Matrix operator+(const Matrix &);
    Matrix operator-(const Matrix &);
    Matrix operator*(const Matrix &);

   private:
    std::string nameOfFile;
    std::fstream myFile;
    int **matrix;
    int matrixRows;
    int matrixCols;
};