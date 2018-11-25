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
    void rowAddition(int row1, int row2, int destRow, int pos);
    void diagCheck(int row);

    void printBuffer() const;

   private:
    int **buffer;
    double *variables;
};