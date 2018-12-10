#include <iostream>

int NSD(int a, int b) {
    try {
        if (a < 0 || b < 0) {
            throw "A of b is lower than zero!";
        }

        if (a == b) {
            return a;
        } else if (a > b) {
            return NSD(a - b, b);
        } else {
            return NSD(a, b - a);
        }

    } catch (const char *ex) {
        std::cout << "**** " << ex << " ****\n";
        exit(1);
    }
}

int main() {
    std::cout << NSD(25, 5) << '\n';
}