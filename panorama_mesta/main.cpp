#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#define MAX_X 30
#define MAX_Y 30

typedef int t_pano[MAX_X][MAX_Y];

std::fstream myFile;
std::string text;
t_pano panorama;

const int numbers_first_line = 2;
int row_col[numbers_first_line];

void parseFile(std::string nameOfFile) {
    int row = 0;

    myFile.open(nameOfFile.c_str(), std::fstream::in);

    if (myFile.is_open()) {
        int lineCount = 0;
        while (!myFile.eof()) {
            getline(myFile, text, '\n');

            if (!lineCount) {
                int position = 0;

                for (int i = 0; i < text.length(); i++) {
                    if (text[i] == '-') {
                        std::cout << "Bad file formatting: Negative number!\n";
                        std::cout << "Name of file: " << nameOfFile << '\n';
                        exit(1);
                    }
                    if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
                        if (text[i + 1] != ' ' && text[i + 1] != '\t' && text[i + 1] != '\n') {
                            row_col[position] = text[i] - '0';
                            row_col[position] *= 10;
                            row_col[position] += text[i + 1] - '0';
                            position++;
                            i++;
                        } else {
                            row_col[position] = text[i] - '0';
                            position++;
                        }
                    }
                }
                lineCount++;
            } else {
                int col = 0;
                for (int i = 0; i < text.length(); i++) {
                    if (text[i] == '-') {
                        std::cout << "Bad file formatting: Negative number!\n";
                        std::cout << "Name of file: " << nameOfFile << '\n';
                        exit(1);
                    }
                    if (text[i] != ' ' && text[i] != '\t' && text[i] != '\n') {
                        if (text[i + 1] != ' ' && text[i + 1] != '\t' && text[i + 1] != '\n' && i + 1 != text.length()) {
                            panorama[lineCount - 1][col] = text[i] - '0';
                            panorama[lineCount - 1][col] *= 10;
                            panorama[lineCount - 1][col] += text[i + 1] - '0';
                            col++;
                            i++;
                        } else {
                            panorama[lineCount - 1][col] = text[i] - '0';
                            col++;
                        }
                    }
                }
                lineCount++;
            }
        }
    }
}

void printFile() {
    for (int i = 0; i < row_col[0]; i++) {
        for (int j = 0; j < row_col[1]; j++) {
            std::cout << std::setw(3) << panorama[i][j] << " ";
        }
        std::cout << '\n';
    }
    std::cout << '\n';
}

void viewFromSide(char side) {
    switch (side) {
        default:
            std::cout << "Wrong function parameter: " << side;
            break;
        case 'n':
            std::cout << "North: ";
            for (int i = 0; i < row_col[1]; i++) {
                int max = 0;
                for (int j = 0; j < row_col[0]; j++) {
                    if (panorama[j][i] > max) {
                        max = panorama[j][i];
                    }
                }
                std::cout << max << " ";
            }
            std::cout << '\n';
            break;
        case 'e':
            std::cout << "East: ";
            for (int i = 0; i < row_col[0]; i++) {
                int max = 0;
                for (int j = row_col[1] - 1; j >= 0; j--) {
                    if (panorama[i][j] > max) {
                        max = panorama[i][j];
                    }
                }
                std::cout << max << " ";
            }
            std::cout << '\n';
            break;
        case 's':
            std::cout << "South: ";
            for (int i = 0; i < row_col[1]; i++) {
                int max = 0;
                for (int j = row_col[0] - 1; j >= 0; j--) {
                    if (panorama[j][i] > max) {
                        max = panorama[j][i];
                    }
                }
                std::cout << max << " ";
            }
            std::cout << '\n';
            break;
        case 'w':
            std::cout << "West: ";
            for (int i = 0; i < row_col[0]; i++) {
                int max = 0;
                for (int j = 0; j < row_col[1]; j++) {
                    if (panorama[i][j] > max) {
                        max = panorama[i][j];
                    }
                }
                std::cout << max << " ";
            }
            std::cout << '\n';
            break;
    }
}

int main() {
    parseFile("data/mesto1.txt");
    printFile();

    viewFromSide('n');
    viewFromSide('e');
    viewFromSide('s');
    viewFromSide('w');
}