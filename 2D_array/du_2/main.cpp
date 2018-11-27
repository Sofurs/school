#include <iostream>
#include <iomanip>

#define MAX_X 20
#define MAX_Y 20

typedef int t_2DArray[MAX_X][MAX_Y];

void fill2DArray(t_2DArray &arr) {
    for(int i = 0, num = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++, num++) {
            arr[i][j] = num;
        }
    }
} 

int main() {
    t_2DArray arr;

    fill2DArray(arr);

    std::cout << std::setw(3) << "  # | ";

    for(int i = 0; i < MAX_Y; i++) {
        std::cout << std::setw(3) << i << " ";
    }

    std::cout << '\n';

    for(int i = 0; i < MAX_Y * 4.5; i++) {
        std::cout << "-";
        if(i == 3) {
            std::cout << "+";
        }
    }

    std::cout << '\n';
 
    for(int i = 0; i < MAX_X; i++) {
        std::cout << std::setw(3)    << i << " | ";
        for(int j = 0; j < MAX_Y; j++) {
            
            std::cout << std::setw(3) << arr[i][j] << " ";
        }
        std::cout << '\n';
    }

    std::cout << '\n';


    return 0;
}