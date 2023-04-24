/* TO-DO LIST 
    - res = a * b
    - res = a << n
    - res = a >> n (logico)
    - res = a >> n (aritmetico)
*/


#include <stdio.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

/* Atribuição */
void big_val (BigInt res, long val){
    char* p = (char*) &val;
    int i;
    for (i = 0; i < 2*(sizeof(long)); i++){
        if (i > 7){
            res[i] = *(p + 7);
        } else{
            res[i] = *(p + i);
        }
    }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b){
    unsigned char auxiliar = 0;
    for (int i = 0; i < 2*(sizeof(long)); i++){
        unsigned char temp = a[i] + b[i] + auxiliar;
        res[i] = temp;
        auxiliar = temp >> 8;
    }
}

/* res = -a */
void big_comp2(BigInt res, BigInt a){
    BigInt auxiliar;
    BigInt valor1;
    for (int i = 0; i < 2*(sizeof(long)); i++){
        auxiliar[i] = ~a[i];
    }
    big_val(valor1, (long) 1);
    big_sum(res, auxiliar, valor1);
}



void dumpTest (BigInt valor){
    for (int i = 0; i < 16; i++){
        printf("%02X\n", valor[i]);
    }
}

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b){
    BigInt auxiliar;
    big_comp2(auxiliar, b);
    big_sum(res, a, auxiliar);
}

int main(void){
    BigInt res;
    BigInt a;
    BigInt b;
    big_val(a, (long) 3);
    big_val(b, (long) 2);
    big_sub(res, a, b);
    dumpTest(res);

    return 0;
}