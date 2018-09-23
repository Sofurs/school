//Matej Las, 23.9.2018
//program vypise vsetky cisla, pre ktore plati:
//číslo je tvorené súvislou postupnosťou bitov s hodnotou 1 (aspoň jedna 1), za ktorou sa nachádza súvislá postupnosť bitov s hodnotou 0
#include <iostream>

int main() {
  int cislo = 0;
  cislo = ~cislo;
  cislo *= -1;

  std::cout << "\n" << cislo << "\n";

  for (int i = 31; i > 0; i--) {
    std::cout << (cislo & 1);
    cislo >>= 1;
  }

  return 0;
}