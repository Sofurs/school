//Matej Las, 23.9.2018
//program urci pocet bitov s hodnotou 1 a 0 zadaneho cisla a potom ich vypise
#include <iostream>

int main() {
  int cislo_1, pocet_1 = 0;
  int velkost_premennej = sizeof(cislo_1) * 8;
  std::cout << "Zadaj cislo: ";
  std::cin >> cislo_1;

  int temp = cislo_1;
  for (int i = velkost_premennej; i > 0; i--) {
    pocet_1 += temp & 1;

    // std::cout << temp << "\n";
    temp >>= 1;
  }

  std::cout << "Cislo " << cislo_1 << " obsahuje " << pocet_1 << " jednotiek a " << velkost_premennej - pocet_1 << " nul.\n";

  return 0;
}
