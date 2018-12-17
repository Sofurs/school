#include <iostream>

int gcd(int a, int b) {
    try {
        if (a < 0 || b < 0) {
            throw "A of b is lower than zero!";
        }

        if (a == b) {
            return a;
        } else if (a > b) {
            return gcd(a - b, b);
        } else {
            return gcd(a, b - a);
        }

    } catch (const char *ex) {
        std::cout << "**** " << ex << " ****\n";
        exit(1);
    }
}

int main() {
    std::cout << gcd(25, 5) << '\n';
}