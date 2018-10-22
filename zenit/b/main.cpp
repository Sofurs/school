#include <iostream>

int main() {

    short num;
    
    std::cin >> num;

    if(num < 0 || num > 100) {
        return 0;
    }

    if(num < 50) {
        std::cout << 100 - num << '\n';
    } else {
        std::cout << num << '\n';
    }

    return 0;
}