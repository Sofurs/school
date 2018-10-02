#include "fileParser.h"

fileParser::fileParser(std::string name) :
nameOfFile(name) {
  myFile.open(nameOfFile, std::fstream::in);

  if (myFile.is_open()) {
      while(!readLine() && !fileError)
        readLine();
  }
}

fileParser::~fileParser() {
    myFile.close();
}

bool fileParser::readLine() {
    getline(myFile, line, '\n');

    if(!headerChecked) {
        parseHeader();
        headerChecked = true;
    }
    else {
        parseLine();
    }

    if (myFile.eof())
        lineNumber = 0;

    return myFile.eof();
}

void fileParser::parseHeader() {
    if((int)line[0] - '0' != MAX_X || (int)line[2] - '0' != MAX_Y) {
        fileError = true;
        std::cout << "Wrong input file: " << nameOfFile << "\n";
    }
}

void fileParser::parseLine() {
    int position = 0;
    for (int i = 0; i < line.length(); i++) {
        if (line[i] != ' ') {
            mapChunks[lineNumber][position] = (int)line[i] - '0';
            position++;
        }
    }
    lineNumber++;
}

void fileParser::print2DArray() {
    if (!fileError) {
        for(int i = 0; i < MAX_X; i++) {
            for(int j = 0; j < MAX_Y; j++) {
                std::cout << mapChunks[i][j] << " ";
            }
            std::cout << '\n';
        }
        std::cout << "\n";
    }
}

void fileParser::copy2DArray(t_MapBig &arr, int start_x, int start_y) {
	for (int i = 0; i < MAX_X; i++, start_x++) {
		for (int j = 0; j < MAX_Y; j++, start_y++) {
			arr[start_x][start_y] = mapChunks[i][j];
		}
		start_y -= 3;
	}
}
