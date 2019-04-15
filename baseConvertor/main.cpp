#include <algorithm>
#include <iostream>
#include <string>

int main() {
    unsigned int num;
    unsigned short int base;
    std::string result;

    std::cout << "Enter num: ";
    std::cin >> num;

    do {
        std::cout << "Enter base: ";
        std::cin >> base;
    } while (base < 2 || base > 16);

    while (num) {
        unsigned int rem = num % base;
        num /= base;

        if (rem >= 10) {
            switch (rem) {
                case 10:
                    result += 'A';
                    break;
                case 11:
                    result += 'B';
                    break;
                case 12:
                    result += 'C';
                    break;
                case 13:
                    result += 'D';
                    break;
                case 14:
                    result += 'E';
                    break;
                case 15:
                    result += 'F';
                    break;
                default:
                    break;
            }

        } else {
            result += std::to_string(rem);
        }
    }

    std::reverse(result.begin(), result.end());

    std::cout << result << '\n';

    return 0;
}