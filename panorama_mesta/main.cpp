#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

#define MAX_X 30
#define MAX_Y 30

typedef int t_pano[MAX_X][MAX_Y];

int main() {
    std::fstream myFile;
    std::string text;
    t_pano panorama;

    const int numbers_first_line = 2;
    int row_col[numbers_first_line];
    int row = 0;

    myFile.open("data/mesto1.txt", std::fstream::in);

    if (myFile.is_open()) {
        int lineCount = 0;
        while (!myFile.eof()) {
            getline(myFile, text, '\n');

            if (!lineCount) {
                int position = 0;

                for (int i = 0; i < text.length(); i++) {
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

    for (int i = 0; i < row_col[0]; i++) {
        for (int j = 0; j < row_col[1]; j++) {
            std::cout << std::setw(3) << panorama[i][j] << " ";
        }
        std::cout << '\n';
    }
}