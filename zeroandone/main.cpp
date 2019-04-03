#include <iostream>
#include <string>

void print(unsigned int& num) {
    static unsigned int iter = 0;

    if (!(iter % 2)) {
        for (int i = 0; i < num; i++) {
            std::cout << '0';
        }
    } else {
        for (int i = 0; i < num; i++) {
            std::cout << '1';
        }
    }

    iter++;
}

int main() {
    std::string buffer;
    unsigned int nums[30];
    getline(std::cin, buffer);

    for (int i = 0; i < 30; i++) {
        nums[i] = 0;
    }

    int num = 0;

    for (int i = 0; i < buffer.length(); i++) {
        if (buffer[i] == ' ') {
            num++;
            continue;
        }

        nums[num] *= 10;
        nums[num] += buffer[i] - '0';
    }

    for (int i = 0; i <= num; i++) {
        print(nums[i]);
    }

    return 0;
}