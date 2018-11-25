#include "gem.hpp"

Gem::Gem() {
}

Gem::Gem(std::fstream *myFile) : Matrix(myFile) {
    initMatrix(buffer);

    variables = new double[matrixRows];
}

Gem::Gem(const Gem &ptr) : Matrix(ptr) {
}

Gem::~Gem() {
    for (int i = 0; i < matrixRows; i++) {
        delete[] buffer[i];
    }

    delete[] buffer;

    delete[] variables;
}

void Gem::directOperation() {
    for (int i = 0; i < matrixCols - 2; i++) {
        for (int j = i; j < matrixRows - 1; j++) {
            std::cout << "\n";
            rowAddition(i, j + 1, j + 1, i);
            printBuffer();
        }
    }
}

void Gem::reverseOperation() {
    // add reverse operation
}

void Gem::copyMatrix() {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            buffer[i][j] = matrix[i][j];
        }
    }
}

void Gem::rowAddition(int row1, int row2, int destRow, int pos) {
    int mult1 = abs(buffer[row2][pos]);
    int mult2 = abs(buffer[row1][pos]);

    if (buffer[row1][pos] * buffer[row2][pos] > 0) {
        for (int i = 0; i < matrixCols; i++) {
            buffer[row1][i] *= -1;
        }
    }

    for (int i = 0; i < matrixCols; i++) {
        buffer[destRow][i] = buffer[row1][i] * mult1 + buffer[row2][i] * mult2;
    }
}

void Gem::diagCheck(int row) {
    try {
        if (row > matrixRows - 1)
            throw "Matrix out of range\n";

        if (!buffer[row][row]) {
            swapRows(buffer, row, row + 1);
        }

    } catch (const char *ex) {
        std::cout << "\n*** " << ex << " ***\n";
        return;
    }
}

void Gem::printBuffer() const {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            std::cout << buffer[i][j] << " ";
        }
        std::cout << '\n';
    }
}