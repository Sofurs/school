//Matej Las, 23.9.2018
//program zisli ci sa posledne bity dvoch cisel rovnaju alebo su rozdielne
#include <iostream>

int main() {
  int cislo_1, cislo_2;
  std::cout << "Zadaj prve cislo: ";
  std::cin >> cislo_1;
  std::cout << "Zadaj druhe cislo: ";
  std::cin >> cislo_2;

  if ((cislo_1 & 1) == (cislo_2 & 1)) {
    std::cout << "Zadane cisla maju posledny bit rovnaky.\n";
  }
  else {
    std::cout << "Zadane cisla maju posledny bit rozdielny.\n";
  }

  return 0;
}
