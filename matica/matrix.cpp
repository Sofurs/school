#include "matrix.hpp"

Matrix::Matrix() {
}

Matrix::Matrix(int row, int col) : matrixRows(row), matrixCols(col) {
    initMatrix();
}

Matrix::Matrix(std::string name) : nameOfFile("data/" + name) {
    myFile.open(nameOfFile, std::ios::in);
}

Matrix::~Matrix() {
    myFile.close();

    for (int i = 0; i < matrixRows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

Matrix::Matrix(const Matrix &ptr) {
    nameOfFile = ptr.nameOfFile;

    matrixRows = ptr.matrixRows;
    matrixCols = ptr.matrixCols;

    initMatrix();

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            matrix[i][j] = ptr.matrix[i][j];
        }
    }
}

bool Matrix::isFileOpen() const {
    return myFile.is_open();
}

void Matrix::getSize() {
    myFile >> matrixRows;
    myFile >> matrixCols;
}

void Matrix::printSize() const {
    std::cout << "\nMatrix size: " << matrixRows << ", " << matrixCols << '\n';
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
            myFile >> matrix[i][j];
        }
    }
}

void Matrix::printMatrix() const {
    std::cout << '\n';
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
            throw "Different sizes of matrix";

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
            throw "Different sizes of matrix";
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

Matrix Matrix::operator*(const Matrix &) {
}
