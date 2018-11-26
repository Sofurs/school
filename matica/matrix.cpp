#include "matrix.hpp"

Matrix::Matrix() {
}

Matrix::Matrix(std::fstream *myFile) {
    *myFile >> matrixRows;
    *myFile >> matrixCols;

    initMatrix(matrix);

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            *myFile >> matrix[i][j];
        }
    }
}

Matrix::Matrix(int row, int col) : matrixRows(row), matrixCols(col) {
    initMatrix(matrix);
}

Matrix::Matrix(const Matrix &ptr) {
    matrixRows = ptr.matrixRows;
    matrixCols = ptr.matrixCols;

    initMatrix(matrix);

    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            matrix[i][j] = ptr.matrix[i][j];
        }
    }
}

Matrix::~Matrix() {
    for (int i = 0; i < matrixRows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;
}

void Matrix::printSize() const {
    std::cout << "Matrix size: " << matrixRows << ", " << matrixCols << '\n';
}

void Matrix::initMatrix(int **&arr) {
    arr = new int *[matrixRows];
    for (int i = 0; i < matrixRows; i++)
        arr[i] = new int[matrixCols];
}

void Matrix::initMatrix(int **&arr, int rows, int cols) {
    arr = new int *[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = new int[cols];
}

void Matrix::printMatrix() const {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

int Matrix::getMatrixRows() const {
    return matrixRows;
}

int Matrix::getMatrixCols() const {
    return matrixCols;
}

void Matrix::swapRows(int **&arr, int row1, int row2) {
    try {
        if (row1 == row2)
            throw "Why to swap same rows?\n";
        if (row1 > matrixRows - 1 || row2 > matrixRows - 1)
            throw "Matrix out of range\n";

        for (int i = 0; i < matrixCols; i++) {
            int temp = arr[row1][i];
            arr[row1][i] = arr[row2][i];
            arr[row2][i] = temp;
        }

    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        return;
    }
}

void Matrix::swapCols(int **&arr, int col1, int col2) {
    try {
        if (col1 == col2)
            throw "Why to swap same cols?\n";
        if (col1 > matrixCols - 1 || col2 > matrixCols - 1)
            throw "Matrix out of range\n";

        for (int i = 0; i < matrixRows; i++) {
            int temp = arr[i][col1];
            arr[i][col1] = arr[i][col2];
            arr[i][col2] = temp;
        }

    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        return;
    }
}

Matrix Matrix::operator=(const Matrix &ptr) {
    matrixRows = ptr.matrixRows;
    matrixCols = ptr.matrixCols;

    initMatrix(matrix, matrixRows, matrixCols);

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
