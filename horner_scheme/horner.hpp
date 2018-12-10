#pragma once

#include <fstream>
#include <iostream>

class Horner {
   public:
    Horner();
    Horner(std::fstream *file, int size);
    Horner(const Horner &);
    ~Horner();

    double calc();
    double calc(double val);
    double calcIntegral();
    double bisection();
    double regulaFalsi();

    void printArr() const;

    void setX(double val);
    void setLowerBound(double val);
    void setUpperBound(double val);
    void setPrecision(double val);

   private:
    double *koef;
    int sizeOfArr;
    double x;

    double lowerBound;
    double upperBound;
    double precision;

    void initArray();
};