#include <iostream>

void printLeft(const char left, int n) {
    if(n == 0) {
        return;
    } else {
        std::cout << left;
        printLeft(left, n - 1);
    }
}

void printRight(const char right, int n) {
    if(n == 0) {
        return;
    } else {
        std::cout << right;
        printRight(right, n - 1);
    }
}

void printOut(const char a, const char b, const char c, int n) {
    printLeft(a, n);
    std::cout << b;
    printRight(c, n);
}

int main() {
    printOut('x', 'y', 'z', 3);
}   