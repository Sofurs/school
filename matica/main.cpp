#include <fstream>
#include <string>
#include <vector>

#include "matrix.hpp"

#define NUM_OF_FILES 2

int main() {
    std::fstream myFile;
    std::vector<Matrix> matrix;

    for (int i = 0; i < NUM_OF_FILES; i++) {
        myFile.open("data/matica" + std::to_string(i) + ".txt", std::ios::in);

        if (myFile.is_open()) {
            matrix.emplace_back(&myFile);

            std::cout << "Matrix " << i + 1 << ":\n";
            matrix.at(i).getSize();
            matrix.at(i).printSize();

            matrix.at(i).initMatrix();
            matrix.at(i).fillMatrix();
            matrix.at(i).printMatrix();
        }

        myFile.close();
    }

    Matrix addition;
    addition = matrix.at(0) + matrix.at(1);
    std::cout << "Addition:\n";
    addition.printMatrix();

    Matrix subtraction;
    subtraction = matrix.at(0) - matrix.at(1);
    std::cout << "Subtraction:\n";
    subtraction.printMatrix();

    Matrix multiplication;
    multiplication = matrix.at(0) * matrix.at(1);
    std::cout << "Multiplication:\n";
    multiplication.printMatrix();

    return 0;
}