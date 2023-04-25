/* TO-DO LIST 
    - res = a * b
    - res = a << n
    - res = a >> n (logico)
    - res = a >> n (aritmetico)
*/

#include <stdio.h>

#define NUM_BITS 128
typedef unsigned char BigInt[NUM_BITS/8];

void big_val (BigInt, long);

void big_sum (BigInt, BigInt, BigInt);

void big_comp2 (BigInt, BigInt);

void big_sub (BigInt, BigInt, BigInt);

void big_mul (BigInt, BigInt, BigInt);

void dumpTest (BigInt);

int main(void){
    BigInt res = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    BigInt a = {0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    BigInt b = {0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    /* big_val(a, (long) 255);
    big_val(b, (long) 2); */
    big_mul(res, a, b);
    dumpTest(res);

    return 0;
}

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

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b){
    BigInt auxiliar;
    big_comp2(auxiliar, b);
    big_sum(res, a, auxiliar);
}

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b){
    unsigned char resto = 0;
    int temp = 0;
    for (int i = 0; i < 2*(sizeof(long)); i++){
        for (int j = 0; j < 2*(sizeof(long)); j++){
            temp = ((int)a[i] * (int)b[j]) + (int)resto + (int)res[j];
            res[j] = (unsigned char) temp;
            resto = temp >> 8; 
        }
    }
}

void dumpTest (BigInt valor){
    for (int i = 0; i < 16; i++){
        printf("%02X\n", valor[i]);
    }
}

