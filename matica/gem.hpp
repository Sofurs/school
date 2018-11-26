#pragma once

#include <fstream>

#include "matrix.hpp"

class Gem : public Matrix {
   public:
    Gem();
    Gem(std::fstream *myFile);
    Gem(const Gem &);
    ~Gem();

    void directOperation();
    void reverseOperation();

    void copyMatrix();
    void rowAddition(int row1, int row2, int pos);
    void diagCheck(int row);
    void result();
    double calcVars(int row);

    void printBuffer() const;
    void printResult() const;

   private:
    int **buffer;
    double *variables;
};