#pragma once

#include <iostream>
#include <fstream>
#include <string>

#define MAX_X 4
#define MAX_Y 3

typedef int t_Map[MAX_X][MAX_Y];

class fileParser {
public:
  fileParser(std::string name);
  ~fileParser();

  bool readLine();
  void parseHeader();
  void parseLine();

  void print2Darray();

private:
  std::string nameOfFile;
  std::fstream myFile;
  std::string line;

  int lineNumber = 0;

  bool headerChecked = false;
  bool fileError = false;

  t_Map map;
};
