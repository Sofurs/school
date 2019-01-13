#include <iostream>

void printRec(const char a, int n) {
    if(n <= 0) {
        return;
    } else {
        std::cout << a;
        printRec(a, n - 1);
    }
}

void printOut(const char a, const char b, const char c, int n) {
    printRec(a, n);
    std::cout << b;
    printRec(c, n);
}

int main() {
    printOut('x', 'y', 'z', 3);
}   