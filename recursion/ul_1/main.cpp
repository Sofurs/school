#include <iostream>

void a(int n) {
    if (n > 0) {
        if (!n % 2)
            a(n - 1);
        else
            a(n - 2);
        std::cout << n << '\n';
    }
}

int main() {
    a(6);
}