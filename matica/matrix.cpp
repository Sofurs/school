#include "matrix.hpp"

Matrix::Matrix() {
}

Matrix::Matrix(std::fstream *file) : myFile(file) {
}

Matrix::Matrix(int row, int col) : matrixRows(row), matrixCols(col) {
    initMatrix();
}

Matrix::~Matrix() {
    for (int i = 0; i < matrixRows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

Matrix::Matrix(const Matrix &ptr) {
    matrixRows = ptr.matrixRows;
    matrixCols = ptr.matrixCols;

    initMatrix();

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            matrix[i][j] = ptr.matrix[i][j];
        }
    }
}

void Matrix::getSize() {
    *myFile >> matrixRows;
    *myFile >> matrixCols;
}

void Matrix::printSize() const {
    std::cout << "Matrix size: " << matrixRows << ", " << matrixCols << '\n';
}

void Matrix::initMatrix(int rows, int cols) {
    if (!rows && !cols) {
        rows = matrixRows;
        cols = matrixCols;
    }

    matrix = new int *[rows];
    for (int i = 0; i < rows; i++)
        matrix[i] = new int[cols];
}

void Matrix::fillMatrix() {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            *myFile >> matrix[i][j];
        }
    }
}

void Matrix::printMatrix() const {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

Matrix Matrix::operator=(const Matrix &ptr) {
    matrixRows = ptr.matrixRows;
    matrixCols = ptr.matrixCols;

    initMatrix(matrixRows, matrixCols);

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            matrix[i][j] = ptr.matrix[i][j];
        }
    }

    return *this;
}

Matrix Matrix::operator+(const Matrix &ptr) {
    try {
        if (matrixRows != ptr.matrixRows || matrixCols != ptr.matrixCols)
            throw "Different sizes of matrices : +";

        Matrix temp(matrixRows, matrixCols);

        for (int i = 0; i < matrixRows; i++) {
            for (int j = 0; j < matrixCols; j++) {
                temp.matrix[i][j] = matrix[i][j] + ptr.matrix[i][j];
            }
        }

        return temp;
    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        exit(1);
    }
}

Matrix Matrix::operator-(const Matrix &ptr) {
    try {
        if (matrixRows != ptr.matrixRows || matrixCols != ptr.matrixCols) {
            throw "Different sizes of matrices : -";
        }

        Matrix temp(matrixRows, matrixCols);

        for (int i = 0; i < matrixRows; i++) {
            for (int j = 0; j < matrixCols; j++) {
                temp.matrix[i][j] = matrix[i][j] - ptr.matrix[i][j];
            }
        }

        return temp;
    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        exit(1);
    }
}

Matrix Matrix::operator*(const Matrix &ptr) {
    try {
        if (matrixCols != ptr.matrixRows) {
            throw "Wrong sizes of matrices : *";
        }

        Matrix temp(matrixRows, ptr.matrixCols);

        int row;
        int col;

        for (row = 0; row < matrixRows; row++) {
            for (col = 0; col < ptr.matrixCols; col++) {
                int value = 0;
                for (int x = 0; x < matrixCols; x++) {
                    value += matrix[row][x] * ptr.matrix[x][col];
                }
                temp.matrix[row][col] = value;
            }
        }
        return temp;
    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        exit(1);
    }
}
