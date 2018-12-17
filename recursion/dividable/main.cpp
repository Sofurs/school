#include <iostream>

bool dividable(int n) {
    if(n < 0) {
        return false;
    } else if(n == 0) {
        return true;
    } else {
        return dividable(n - 17);
    }
}

int main() {
    std::cout << dividable(56) << '\n';
}