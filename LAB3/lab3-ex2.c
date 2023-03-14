#include <stdio.h>

int odd_ones(unsigned int x) {
  /* escreva seu código aqui */
  unsigned int auxiliar = x;
  int contador = 0;
  while (auxiliar != 0x00000000){
    if (auxiliar & 0x80000000){
      if (contador == 0){
        contador = 1;
      }
      else{
        contador = 0;
      }
    }
    auxiliar = auxiliar << 1;
  }
  return contador;
}
int main() {
  printf("%x tem numero %s de bits\n",0x01010101,odd_ones(0x01010101) ? "impar":"par");
  printf("%x tem numero %s de bits\n",0x01030101,odd_ones(0x01030101) ? "impar":"par");
  return 0;
}   