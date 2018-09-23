//Matej Las, 23.9.2018
//program urci pocet bitov s hodnotou 1 a 0 zadaneho cisla a potom ich vypise
#include <iostream>

int main() {
  int cislo_1, pocet_0 = 0, pocet_1 = 0;
  std::cout << "Zadaj cislo: ";
  std::cin >> cislo_1;

  for (int i = 32; i > 0; i--) {
    int temp = cislo_1;
    if ((temp &= 1) == 1)
      pocet_1++;
    else
      pocet_0++;

    // std::cout << temp << "\n";
    cislo_1 >>= 1;
  }

  std::cout << "Cislo " << cislo_1 << " obsahuje " << pocet_1 << " jednotiek a " << pocet_0 << " nul.\n";

  return 0;
}
