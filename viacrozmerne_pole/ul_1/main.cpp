#include <iostream>
#include <stdlib.h>
#include <time.h>

#define MAX_X 20
#define MAX_Y 20

#define MAX_NUM 100

typedef int t_2DArray[MAX_X][MAX_Y];

struct ValuesMaxMin {
    int max = 0;
    int max_pos_row;
    int max_pos_col;

    int min = MAX_NUM;
    int min_pos_row;
    int min_pos_col;

} S_2DArrayMaxMin;

struct ValuesMaxMinLine {
    int row_sum_max = 0;
    int row_index_max;

    int row_sum_min = MAX_NUM * MAX_X;
    int row_index_min;
} S_2DArrayMaxMinLine;

void fill2DArray(t_2DArray &arr) {
    srand(time(NULL));
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            arr[i][j] = rand() % MAX_NUM;
        }
    }
}

void print2DArray(t_2DArray &arr) {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << '\n';
    }
}

void findMaxMin(t_2DArray &arr) {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            if (arr[i][j] > S_2DArrayMaxMin.max) {
                S_2DArrayMaxMin.max = arr[i][j];
                S_2DArrayMaxMin.max_pos_row = i; 
                S_2DArrayMaxMin.max_pos_col = j; 
            }   
            if(arr[i][j] < S_2DArrayMaxMin.min) {
                S_2DArrayMaxMin.min = arr[i][j];
                S_2DArrayMaxMin.min_pos_row = i; 
                S_2DArrayMaxMin.min_pos_col = j; 
            }
        }
    }
}

void mirror2DArrayByX(t_2DArray &arr) {
    for(int j = 0; j < MAX_Y; j++) {
        for(int i = 0; i != MAX_X - i ; i++) {
            arr[i][j] ^= arr[MAX_X - 1 - i][j];
            arr[MAX_X - 1 - i][j] ^= arr[i][j];
            arr[i][j] ^= arr[MAX_X - 1 - i][j];
        }
    }
}

void mirror2DArrayByY(t_2DArray &arr) {
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j != MAX_Y - j ; j++) {
            arr[i][j] ^= arr[i][MAX_X - 1 - j];
            arr[i][MAX_X - 1 - j] ^= arr[i][j];
            arr[i][j] ^= arr[i][MAX_X - 1 - j];
        }
    }
}

void printMaxMin(t_2DArray &arr) {
    findMaxMin(arr);
    
    std::cout << "Maximalna hodnota: " << S_2DArrayMaxMin.max << ", s polohou x: " << S_2DArrayMaxMin.max_pos_row << ", s y: " << S_2DArrayMaxMin.max_pos_col << '\n';
    std::cout << "Minimalna hodnota: " << S_2DArrayMaxMin.min << ", s polohou x: " << S_2DArrayMaxMin.min_pos_row << ", s y: " << S_2DArrayMaxMin.min_pos_col << '\n';
}

void findMaxMinLine(t_2DArray &arr) {
    int sumOfLine = 0;
    for(int i = 0; i < MAX_X; i++) {
        for(int j = 0; j < MAX_Y; j++) {
            sumOfLine += arr[i][j];
        }

        if (sumOfLine > S_2DArrayMaxMinLine.row_sum_max) {
            S_2DArrayMaxMinLine.row_sum_max = sumOfLine;
            S_2DArrayMaxMinLine.row_index_max = i;
        }   
        if(sumOfLine < S_2DArrayMaxMinLine.row_sum_min) {
            S_2DArrayMaxMinLine.row_sum_min = sumOfLine;
            S_2DArrayMaxMinLine.row_index_min = i; 
        }

        sumOfLine = 0;   
    }
}

void printMaxMinLine(t_2DArray &arr) {
    findMaxMinLine(arr);
    
    std::cout << "Riadok s max hodnotou: " << S_2DArrayMaxMinLine.row_sum_max << ", s polohou x: " << S_2DArrayMaxMinLine.row_index_max << '\n';
    std::cout << "Riadok s min hodnotou: " << S_2DArrayMaxMinLine.row_sum_min << ", s polohou x: " << S_2DArrayMaxMinLine.row_index_min << '\n';
} 

int main() {

    t_2DArray arr;

    fill2DArray(arr);

    return 0;
}