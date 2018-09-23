//Matej Las, 23.9.2018
//program zisti ci su ip adresy z rovnakej siete
#include <iostream>

#define VELKOST_IPv4 5

void nacitajIp(int *pole) {
    for(int i = 0; i < VELKOST_IPv4; i++) {
    std::cin >> pole[i];
    std::cin.ignore(1);
  }
}

void vypisIp(int *pole) {
  for(int i = 0; i < VELKOST_IPv4; i++) {
    std::cout << pole[i] << (i < VELKOST_IPv4 - 2 ? "." : (i > VELKOST_IPv4 - 2 ? "" : "/"));
  }
}

void vytvorMasku(int index, int *maska) {
  unsigned int zasobnik = 0;
  zasobnik = ~zasobnik;
  zasobnik <<= (32 - index);

  maska[3] = (zasobnik & 255);
  maska[2] = ((zasobnik >> 8) & 255);
  maska[1] = ((zasobnik >> 16) & 255);
  maska[0] = ((zasobnik >> 24) & 255);  
}

bool porovnajIp(int *ip_1, int *ip_2) {
  int maska_1[VELKOST_IPv4 - 1];
  int maska_2[VELKOST_IPv4 - 1];

  vytvorMasku(ip_1[4], maska_1);
  vytvorMasku(ip_2[4], maska_2);

  int vyslednaIp_1[VELKOST_IPv4 - 1]; 
  int vyslednaIp_2[VELKOST_IPv4 - 1];

  for(int i = 0; i < VELKOST_IPv4 - 1; i++) {
    vyslednaIp_1[i] = (ip_1[i] & maska_1[i]); 
    vyslednaIp_2[i] = (ip_2[i] & maska_2[i]); 

    if (vyslednaIp_1[i] != vyslednaIp_2[i])
      return false;
  }
  return true;
}

int main() {
  int ip_1[VELKOST_IPv4];
  int ip_2[VELKOST_IPv4];

  std::cout << "Zadaj prvu IP adresu vo formate CIDR notacie(a.b.c.d/e): ";
  nacitajIp(ip_1);
  std::cout << "Zadaj druhu IP adresu vo formate CIDR notacie(a.b.c.d/e): ";
  nacitajIp(ip_2);

  std::cout << "Ip adresy "; 
  vypisIp(ip_1);
  std::cout << " a ";
  vypisIp(ip_2);

  if (porovnajIp(ip_1, ip_2))
    std::cout << " su v rovnakej sieti.\n";
  else
    std::cout << " nie su v rovnakej sieti.\n";

  return 0;
}