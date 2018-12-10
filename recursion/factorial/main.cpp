#include <iostream>

int factorial(int n) {
    try {
        if (n < 0) {
            throw "N is lower than zero!";
        }

        if (!n) {
            return 1;
        } else {
            return n * factorial(n - 1);
        }
    } catch (const char *ex) {
        std::cout << "**** " << ex << " ****\n";
        exit(1);
    }
}

int main() {
    std::cout << factorial(-1) << '\n';
}