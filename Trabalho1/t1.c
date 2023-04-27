/* TO-DO LIST 
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

void big_shl (BigInt, BigInt, int);

void big_shr (BigInt, BigInt, int);

void big_sar (BigInt, BigInt, int);

void big_copia (BigInt, BigInt);

int main(void){
    BigInt res = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    BigInt a = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff};
    /* BigInt b = {0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}; */
    /* big_val(a, (long) 255);
    big_val(b, (long) 2); */
    big_sar(res, a, 1);
    /* big_mul(res, a, b); */

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
            temp = ((int)a[i] * (int)b[j]) + (int)resto + (int)res[i + j];
            res[j + i] = (unsigned char) temp;
            resto = temp >> 8; 
        }
    }
}

/* res = a */
void big_copia (BigInt res, BigInt a){
    for (int i = 0; i < 16; i++){
        res[i] = a[i];
    }
}

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n){
    BigInt multiplicadorDois;
    BigInt auxiliar;
    big_val(multiplicadorDois, (long)2);
    for (int i = n; i > 0; i--){
        big_copia(auxiliar, res);
        big_mul(auxiliar, a, multiplicadorDois);
        big_copia(a, auxiliar);
    }
    big_copia(res, auxiliar);
}

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n){
    BigInt resAuxiliar = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    int quociente = n/8;
    int resto = n%8;
    unsigned char sobra = 0x00;
    for (int i = quociente; i > 0; i--){
        for (int j = 0; j <= 15; j++){
            resAuxiliar [15-(j+1)] = a[15-j];
        }
        big_copia (a, resAuxiliar);
    }
    if (resto > 0){
        for (int i = 15; i >= 0; i--){
            resAuxiliar[i] = (a[i] >> n)|sobra;
            sobra = a[i] << (8 - resto);
        }
    }
    big_copia (res, resAuxiliar);
}

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n){
    BigInt resAuxiliar;
    if ((a[15] & 0x80) == 0x80){
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0xff;
        }
    } else {
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0x00;
        }
    }
    int quociente = n/8;
    int resto = n%8;
    unsigned char sobra = 0x00;
    for (int i = quociente; i > 0; i--){
        for (int j = 0; j <= 15; j++){
            resAuxiliar [15-(j+1)] = a[15-j];
        }
        big_copia (a, resAuxiliar);
    }
    if (resto > 0){
        for (int i = 15; i >= 0; i--){
            resAuxiliar[i] = ((signed char)a[i] >> n)|sobra;
            sobra = a[i] << (8 - resto);
        }
    }
    big_copia (res, resAuxiliar);
}

void dumpTest (BigInt valor){
    for (int i = 0; i < 16; i++){
        printf("%02X\n", valor[i]);
    }
}

