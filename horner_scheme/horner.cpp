#include "horner.hpp"

#include <cmath>

Horner::Horner() {
}

Horner::Horner(std::fstream *file, int size) : sizeOfArr(size) {
    initArray();
    for (int i = sizeOfArr - 1; i >= 0; i--) {
        *file >> koef[i];
    }
}

Horner::Horner(const Horner &ptr) {
    sizeOfArr = ptr.sizeOfArr;

    initArray();

    for (int i = 0; i < sizeOfArr; i++) {
        koef[i] = ptr.koef[i];
    }

    x = ptr.x;

    lowerBound = ptr.lowerBound;
    upperBound = ptr.upperBound;
    precision = ptr.precision;
}

Horner::~Horner() {
    delete[] koef;
}

double Horner::calc() {
    double result = 0;

    for (int i = sizeOfArr - 1; i >= 0; i--) {
        result = result * x + koef[i];
    }
    return result;
}

double Horner::calc(double val) {
    double result = 0;

    for (int i = sizeOfArr - 1; i >= 0; i--) {
        result = result * val + koef[i];
    }
    return result;
}

double Horner::calcIntegral() {
    double result = 0;

    for (double i = lowerBound + ((upperBound - lowerBound) * precision); i <= upperBound - ((upperBound - lowerBound) * precision); i += (upperBound - lowerBound) * precision) {
        result += calc(i);
    }

    result += (calc(lowerBound) + calc(upperBound) / 2);
    result *= (upperBound - lowerBound) * precision;

    return result;
}

double Horner::bisection() {
    double middlePoint;

    if (calc(lowerBound) * calc(upperBound) >= 0) {
        std::cout << "Wrong boundaries";
        return (double)NULL;
    }

    do {
        middlePoint = (lowerBound + upperBound) / 2;

        if (calc(middlePoint) == 0) {
            return middlePoint;
        } else if (calc(lowerBound) * calc(middlePoint) < 0) {
            upperBound = middlePoint;
        } else {
            lowerBound = middlePoint;
        }

    } while (abs(upperBound - lowerBound) >= precision);

    return middlePoint;
}

void Horner::printArr() const {
    for (int i = sizeOfArr - 1; i >= 0; i--) {
        std::cout << koef[i] << " ";
    }
    std::cout << '\n';
}

void Horner::setX(double val) {
    x = val;
}

void Horner::setLowerBound(double val) {
    lowerBound = val;
}

void Horner::setUpperBound(double val) {
    upperBound = val;
}

void Horner::setPrecision(double val) {
    precision = val;
}

void Horner::initArray() {
    koef = new double[sizeOfArr];
}
