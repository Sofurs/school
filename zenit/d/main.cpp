#include <iostream>
#include <string>
#include <string.h>
#include <map>

int main() {

    int n, k;

    std::cin >> n >> k;
    
    if(n < 1 || k > 100000)
        return 0;

    std::string arr_string[n], buffer;
    int arr_int[n];

    for(int i = 0; i < n; i++) {
        getline(std::cin, buffer, ' ');
        arr_string[i] = buffer;
        getline(std::cin, buffer, '\n');
        arr_int[i] = std::stoi(buffer, nullptr);
    }

    int max = 0;
    int numOfRelatives = 0;
    int sumOfInts = 0;

    for(int i = 0; i < n ; i++) {
        sumOfInts += arr_int[i];
    }

    std::map<std::string, int> buf;

    for(int i = 0; i < n; i++) {
        buf[arr_string[i]] += arr_int[i];
    }

    for(std::map<std::string, int>::iterator it = buf.begin(); it != buf.end(); it++) {
        if (it->second > max)
            max = it->second;
    }

    // for(int i = 0, count = 0; i < n; i++) {
    //     buffer = arr_string[i];
    //     for(int j = 0; j < n; j++) {
    //         bool str = strstr(buffer.c_str(), arr_string[j].c_str());
    //         if(str) {
    //             count += arr_int[j];
    //             arr_string[j].empty();
    //             arr_int[j] = 0;
    //         }
    //     }
    //     if(count > max) {
    //         max = count;
    //     }
    //     numOfRelatives++;
    //     count = 0;
    // }

    std::cout << "size: " << buf.size() << '\n';

    if(numOfRelatives < k) {
        std::cout << sumOfInts << '\n';
    } else {
        std::cout << max << '\n';
    }

    return 0;
}