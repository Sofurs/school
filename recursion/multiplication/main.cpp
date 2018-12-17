#include <iostream>

double multiplication(double a, double b) {
    if(b == 1) {
        return a;
    } else {
        return a + multiplication(a, b - 1);
    }
}

int main() {
   std::cout << multiplication(3, 2) << '\n';
}