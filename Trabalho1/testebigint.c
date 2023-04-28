/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */
#include <stdio.h>
#include "bigint.h"

int compara_resultados(BigInt a, BigInt b, char* funcao, int num_teste){
   int verifica_erro = 0;

      for (int i = 0; i<16; i++){
      if (a[i] != b[i]){
         verifica_erro = 1;
      }
   }
   if (verifica_erro == 1){
      printf("Erro em %s no teste %d\n", funcao, num_teste);
   } else{
      printf("Teste %d na função %s está OK\n", num_teste, funcao);
   }
   return verifica_erro;
}

int teste_big_val(char* funcao){
   printf("--------------------Testes para a função big_val--------------------\n\n");
   int erros = 0;
   BigInt res;

   /* Teste para um número positivo pequeno -> 2 */
   BigInt certo1 = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_val(res, 2);
   if (compara_resultados(res, certo1, funcao, 1)){
      erros = erros + 1;
   }

   /* Teste para um número negativo pequeno -> -2 */
   BigInt certo2 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   big_val(res, -2);
   if (compara_resultados(res, certo2, funcao, 2)){
      erros = erros + 1;
   }

   /* Teste para um número positivo grande -> 114748367 */
   BigInt certo3 = {0xfb, 0x24, 0xaf, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_val(res, 11478267);
   if (compara_resultados(res, certo3, funcao, 3)){
      erros = erros + 1;
   }

   /* Teste para um número negagivo grande -> -114748367 */
   BigInt certo4 = {0x05, 0xdb, 0x50, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   big_val(res, -11478267);
   if (compara_resultados(res, certo4, funcao, 4)){
      erros = erros + 1;
   }

   /* Teste para o zero -> 0 */
   BigInt certo5 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_val(res, 0);
   if (compara_resultados(res, certo5, funcao, 5)){
      erros = erros + 1;
   }
   
   printf("\n");
   
   return erros;
}

int teste_big_sum(char* funcao){
   printf("--------------------Testes para a função big_sum--------------------\n\n");
   int erros = 0;
   BigInt res;

   /* Teste para a soma de dois positivos pequenos */
   BigInt certo1 = {0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a1 = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b1 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a1, b1);
   if (compara_resultados(res, certo1, funcao, 1)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo pequeno com um positivo grande */
   BigInt certo2 = {0xe7, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a2 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b2 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a2, b2);
   if (compara_resultados(res, certo2, funcao, 2)){
      erros = erros + 1;
   }

   /* Teste para a soma de um negativo pequeno com um negativo pequeno */
   BigInt certo3 = {0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a3 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt b3 = {0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   big_sum(res, a3, b3);
   if (compara_resultados(res, certo3, funcao, 3)){
      erros = erros + 1;
   }

   /* Teste para a soma de um negativo pequeno com um negativo grande */
   BigInt certo4 = {0xfe, 0x46, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a4 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt b4 = {0x00, 0x47, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   big_sum(res, a4, b4);
   if (compara_resultados(res, certo4, funcao, 4)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo pequeno com um negativo pequeno */
   BigInt certo5 = {0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a5 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt b5 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a5, b5);
   if (compara_resultados(res, certo5, funcao, 5)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo pequeno com um negativo grande */
   BigInt certo6 = {0x03, 0x47, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a6 = {0x00, 0x47, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt b6 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a6, b6);
   if (compara_resultados(res, certo6, funcao, 6)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo grande com um negativo pequeno */
   BigInt certo7 = {0xe2, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a7 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt b7 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a7, b7);
   if (compara_resultados(res, certo7, funcao, 7)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo grande com um negativo grande */
   BigInt certo8 = {0xe4, 0x82, 0xaf, 0xd0, 0x89, 0x37, 0x1d, 0x20, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a8 = {0x00, 0x47, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt b8 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a8, b8);
   if (compara_resultados(res, certo8, funcao, 8)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo grande com um positivo grande */
   BigInt certo9 = {0xa4, 0x8b, 0x9f, 0x3a, 0x8b, 0xbf, 0x25, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a9 = {0xc0, 0x4f, 0x31, 0x9c, 0x03, 0xa9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b9 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a9, b9);
   if (compara_resultados(res, certo9, funcao, 9)){
      erros = erros + 1;
   }

   /* Teste para a soma de um negativo grande com um negativo grande */
   BigInt certo10 = {0x55, 0xf5, 0x66, 0x13, 0x24, 0xc4, 0x57, 0x65, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a10 = {0x00, 0x47, 0x41, 0x32, 0x02, 0x21, 0xfa, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt b10 = {0x55, 0xae, 0x25, 0xe1, 0x21, 0xa3, 0x5d, 0x45, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   big_sum(res, a10, b10);
   if (compara_resultados(res, certo10, funcao, 10)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo pequeno com zero */
   BigInt certo11 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a11 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b11 = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a11, b11);
   if (compara_resultados(res, certo11, funcao, 11)){
      erros = erros + 1;
   }

   /* Teste para a soma de um positivo grande com zero */
   BigInt certo12 = {0xc0, 0x4f, 0x31, 0x9c, 0x03, 0xa9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a12 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b12 = {0xc0, 0x4f, 0x31, 0x9c, 0x03, 0xa9, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a12, b12);
   if (compara_resultados(res, certo12, funcao, 12)){
      erros = erros + 1;
   }

   /* Teste para a soma de um negativo pequeno com zero */
   BigInt certo13 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt a13 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b13 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   big_sum(res, a13, b13);
   if (compara_resultados(res, certo13, funcao, 13)){
      erros = erros + 1;
   }

   /* Teste para a soma de um negativo grande com zero */
   BigInt certo14 = {0x55, 0xae, 0x25, 0xe1, 0x21, 0xa3, 0x5d, 0x45, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   BigInt a14 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b14 = {0x55, 0xae, 0x25, 0xe1, 0x21, 0xa3, 0x5d, 0x45, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff};
   big_sum(res, a14, b14);
   if (compara_resultados(res, certo14, funcao, 14)){
      erros = erros + 1;
   }
   
   /* Teste para a soma de zero com zero */
   BigInt certo15 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt a15 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   BigInt b15 = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_sum(res, a15, b15);
   if (compara_resultados(res, certo15, funcao, 15)){
      erros = erros + 1;
   }

   printf("\n");

   return erros;
}

int teste_big_comp2(char* funcao){
   printf("--------------------Testes para a função big_comp2--------------------\n\n");
   int erros = 0;
   BigInt res;

   /* Teste para um número positivo pequeno */
   BigInt certo1 = {0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt a1 = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_comp2(res, a1);
   if (compara_resultados(res, certo1, funcao, 1)){
      erros = erros + 1;
   }

   /* Teste para um número positivo grande */
   BigInt certo2 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
   BigInt a2 = {0xe4, 0x3b, 0x6e, 0x9e, 0x87, 0x16, 0x23, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
   big_comp2(res, a2);
   if (compara_resultados(res, certo2, funcao, 2)){
      erros = erros + 1;
   }
   

   printf("\n");

   return erros;
}


int main()
{
   int falhas = 0;
   
   //falhas += teste_big_val("big_val");
   falhas += teste_big_comp2("big_comp2");
   //falhas += teste_big_sum("big_sum");
   
   
   return 0;
}