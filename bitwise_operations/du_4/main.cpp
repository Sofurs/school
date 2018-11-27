//Matej Las, 23.9.2018
//program vypise vsetky cisla, pre ktore plati:
//číslo je tvorené súvislou postupnosťou bitov s hodnotou 1 (aspoň jedna 1), za ktorou sa nachádza súvislá postupnosť bitov s hodnotou 0
#include <iostream>

int main() {
  int cislo = 0 ^ (1 << 31);
  int modifikator = 0;
  cislo = ~cislo;

  for(int i = 1; i < 31; i++) {
    int temp = (cislo ^ (modifikator |= 1));
    std::cout << i << (i < 10 ? " ." : ".") << "cislo je: " << temp << ", Bin: ";
    for(int j = 31; j >= 0; j--) {
      std::cout << (j % 4 == 3 ? " " : "") << ((temp >> j) & 1);
    }
    std::cout << "\n";
    modifikator <<= 1;
  }

  return 0;
}