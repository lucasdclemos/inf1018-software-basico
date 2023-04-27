#include <stdio.h>
#include "bigint.h"

int test_igual(BigInt a, BigInt b, char *msg, int test)
{
   int i;
   int deu_erro = 0;
   
   for (i=0; i<16; i++)
      if (a[i] != b[i]) deu_erro = 1;
      
   if (deu_erro)
      printf("Erro em %s no teste %d\n", msg, test);

   return deu_erro;
}

int test_big_val (char *msg)
{
   int falhas = 0;
   BigInt gab1 = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt res;
   big_val (res, 1);
   
   if (test_igual(res, gab1, msg, 1)) falhas += 1;

   BigInt gab2 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   big_val (res, -2);
   
   if (test_igual(res, gab2, msg, 2)) falhas += 1;

   return (falhas != 0);
}

int test_big_comp2(char *msg)
{
   
/* big_comp2(BigInt res, BigInt a)*/

   return 1;
}

int test_big_sum(char *msg)
{
   
/* big_sum(BigInt res, BigInt a, BigInt b) */

   return 1;
}


int main()
{
   int falhas = 0;
   
   falhas += test_big_val("big_val");
   falhas += test_big_comp2("big_comp2");
   falhas += test_big_sum("big_sum");
   
   printf("Total de falhas %d de 8\n", falhas);
   return 0;
}