#include <fstream>
#include <iostream>
#include <vector>

#include "horner.hpp"

#define NUM_OF_FILES 4

int main() {
    std::fstream myFile;
    std::vector<Horner> polynomial;

    for (int i = 0; i < NUM_OF_FILES; i++) {
        myFile.open("data/file" + std::to_string(i) + ".txt", std::ios::in);

        if (myFile.is_open()) {
            int size;
            myFile >> size;

            polynomial.emplace_back(&myFile, size + 1);
        }
        myFile.close();
    }

    // double x;
    // std::cout << "Zadaj x: ";
    // std::cin >> x;
    // polynomial.at(0).printArr();
    // polynomial.at(0).setX(x);
    // std::cout << "Vysledok: " << polynomial.at(0).calc() << '\n';

    polynomial.at(1).setLowerBound(-1);
    polynomial.at(1).setUpperBound(4);
    polynomial.at(1).setPrecision(0.01);
    polynomial.at(1).printArr();    
    std::cout << "Vysledok: " << polynomial.at(1).bisection() << '\n';

    polynomial.at(2).setLowerBound(-3);
    polynomial.at(2).setUpperBound(3);
    polynomial.at(2).setPrecision(0.001);
    polynomial.at(2).printArr();    
    std::cout << "Vysledok: " << polynomial.at(2).bisection() << '\n';

    polynomial.at(3).setLowerBound(-3);
    polynomial.at(3).setUpperBound(5);
    polynomial.at(3).setPrecision(0.0001);
    polynomial.at(3).printArr();    
    std::cout << "Vysledok: " << polynomial.at(3).bisection() << '\n';
}