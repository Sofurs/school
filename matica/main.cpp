#include <string>
#include <vector>

#include "matrix.hpp"

#define NUM_OF_FILES 2

int main() {
    std::vector<Matrix> matrix;

    for (int i = 0; i < NUM_OF_FILES; i++) {
        matrix.emplace_back("matica" + std::to_string(i) + ".txt");

        if (matrix.at(i).isFileOpen()) {
            matrix.at(i).getSize();
            matrix.at(i).printSize();

            matrix.at(i).initMatrix();
            matrix.at(i).fillMatrix();
            matrix.at(i).printMatrix();
        }
    }

    Matrix addition;
    addition = matrix.at(0) + matrix.at(1);
    addition.printMatrix();

    Matrix subtraction;
    subtraction = matrix.at(0) - matrix.at(1);
    subtraction.printMatrix();

    return 0;
}