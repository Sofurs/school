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
            rowAddition(i, j + 1, i);
        }
    }
}

void Gem::reverseOperation() {
    result();

    for (int i = matrixRows - 1; i >= 0; i--) {
        variables[i] = calcVars(i);
    }
}

void Gem::copyMatrix() {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            buffer[i][j] = matrix[i][j];
        }
    }
}

void Gem::rowAddition(int row1, int row2, int pos) {
    int mult1 = abs(buffer[row2][pos]);
    int mult2 = abs(buffer[row1][pos]);

    if (buffer[row1][pos] * buffer[row2][pos] > 0) {
        for (int i = 0; i < matrixCols; i++) {
            buffer[row1][i] *= -1;
        }
    }

    for (int i = 0; i < matrixCols; i++) {
        buffer[row2][i] = buffer[row1][i] * mult1 + buffer[row2][i] * mult2;
    }

    diagCheck(pos);
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

void Gem::result() {
    if (buffer[matrixRows - 1][matrixCols - 1] == buffer[matrixRows - 1][matrixCols - 2])
        std::cout << "Infinite number of solutions\n";
    else if (!buffer[matrixRows - 1][matrixCols - 2])
        std::cout << "No solutions\n";
    else
        std::cout << "One solution\n";
}

double Gem::calcVars(int row) {
    double sum = 0;
    double bes = buffer[row][matrixCols - 1];

    for (int i = matrixRows - row; i > 0; i--) {
        if (matrixRows - row != i) {
            sum += buffer[row][matrixCols - i - 1] * variables[matrixRows - i];
        }

        if (sum > 0)
            bes += -sum;

        else if (sum < 0)
            bes += -sum;

        sum = 0;
    }

    return bes / buffer[row][row];
}

void Gem::printBuffer() const {
    for (int i = 0; i < matrixRows; i++) {
        for (int j = 0; j < matrixCols; j++) {
            std::cout.width(7);
            std::cout << buffer[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void Gem::printResult() const {
    for (int i = 0; i < matrixRows; i++) {
        std::cout << "x_" << i << " = " << variables[i] << '\n';
    }
}