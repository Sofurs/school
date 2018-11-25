#include <fstream>
#include <string>
#include <vector>

#include "gem.hpp"
#include "matrix.hpp"

#define NUM_OF_FILES 1

int main() {
    std::fstream myFile;
    // std::vector<Matrix> matrix;
    std::vector<Gem> gem;

    for (int i = 0; i < NUM_OF_FILES; i++) {
        myFile.open("data/file" + std::to_string(i) + ".txt", std::ios::in);

        if (myFile.is_open()) {
            // matrix.emplace_back(&myFile);
            gem.emplace_back(&myFile);

            // matrix.at(i).printSize();
            gem.at(i).printSize();
            // matrix.at(i).printMatrix();
            gem.at(i).printMatrix();
        }

        myFile.close();
    }

    gem.at(0).copyMatrix();
    gem.at(0).directOperation();

    // Matrix addition;
    // addition = matrix.at(0) + matrix.at(1);
    // std::cout << "Addition:\n";
    // addition.printMatrix();

    // Matrix subtraction;
    // subtraction = matrix.at(0) - matrix.at(1);
    // std::cout << "Subtraction:\n";
    // subtraction.printMatrix();

    // Matrix multiplication;
    // multiplication = matrix.at(0) * matrix.at(1);
    // std::cout << "Multiplication:\n";
    // multiplication.printMatrix();

    return 0;
}