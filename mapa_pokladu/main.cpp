#include "fileParser.h"

int main() {

  fileParser file1("data/1.txt");
  fileParser file2("data/2.txt");
  fileParser file3("data/3.txt");
  fileParser file4("data/4.txt");

  t_MapBig map;

  file1.copy2DArray(map, 0, 0);
  file2.copy2DArray(map, 0, 3);
  file3.copy2DArray(map, 4, 0);
  file4.copy2DArray(map, 4, 3);

  for (int i = 0; i < 8; i++) {
	  for (int j = 0; j < 6; j++) {
		  std::cout << map[i][j] << " ";
	  }
	  std::cout << '\n';
  }
  std::cout << '\n';

  return 0;
}
