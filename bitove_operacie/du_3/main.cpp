//Matej Las, 23.9.2018
//program posuva bity az kym na poslednom mieste nieje bit s hodnotou 1 a vypise vysledok
#include <iostream>

int main() {
  int cislo_1;
  std::cout << "Zadaj cislo: ";
  std::cin >> cislo_1;

  while((cislo_1 & 1) == 0) {
    cislo_1 >>= 1;
  }

  std::cout << cislo_1 << "\n";

  return 0;
}
