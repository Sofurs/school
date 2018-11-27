#pragma once

#include <fstream>
#include <iostream>
#include <string>

#define MAX_X 4
#define MAX_Y 3

typedef int t_Map[MAX_X][MAX_Y];
typedef int t_MapBig[8][6];

class fileParser {
   public:
    fileParser(std::string name);
    ~fileParser();

    bool readLine();
    void parseHeader();
    void parseLine();

    void print2DArray();

    void copy2DArray(t_MapBig &arr, int start_x, int start_y);

   private:
    std::string nameOfFile;
    std::fstream myFile;
    std::string line;

    int lineNumber = 0;

    bool headerChecked = false;
    bool fileError = false;

    t_Map mapChunks;
};
