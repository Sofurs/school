#include <iostream>

int combination(int n, int k) {
    try {
        if (n < 0 || k < 0) {
            throw "N or k is lower than zero!";
        } else if (k > n) {
            throw "K cannot be greater that n!";
        }

        if (n == k) {
            return 1;
        } else if (k == 0) {
            return 1;
        } else {
            return combination(n - 1, k - 1) + combination(n - 1, k);
        }

    } catch (const char *ex) {
        std::cout << "**** " << ex << " ****\n";
        exit(1);
    }
}

int main() {
    std::cout << combination(12, 6) << '\n';
}