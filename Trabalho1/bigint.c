/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdio.h>
#include "bigint.h"

void big_copia (BigInt, BigInt);

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
        unsigned int temp = a[i] + b[i] + auxiliar;
        res[i] = (unsigned char)temp;
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
    int i, j, auxiliar, resto;
    BigInt temp, parcial;
    big_val(temp, 0); //para que se possa fazer algo como a=a*b
    for(i = 0; i < 16; i++){
        big_val(parcial, 0);		// variavel para armazenar os resultados sem o overflow(parciais)
        resto = 0;
        for(j = i; j < 16; j++)
        {
            auxiliar = ((a[i] * b[j-i]) + resto);  // multiplica a com b e guarda em aux
            parcial[j] = auxiliar & 0xFF; //  parcial armazena apenas o que cabe em um byte
            resto = auxiliar >> 8;                
        }
        big_sum(temp, temp, parcial);
    }
    big_copia(res, temp);

}

/* res = a */
void big_copia (BigInt res, BigInt a){
    for (int i = 0; i < 16; i++){
        res[i] = a[i];
    }
}

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n){
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt multiplicadorDois;
    BigInt auxiliar;
    big_val(multiplicadorDois, 2);
    for (int i = n; i > 0; i--){
        big_copia(auxiliar, res);
        big_mul(auxiliar, a, multiplicadorDois);
        big_copia(a, auxiliar);
    }
    big_copia(res, auxiliar);
}

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n){
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt resAuxiliar = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    int quociente = n/8;
    unsigned char sobra = 0x00;
    for (int i = quociente; i > 0; i--){
        for (int j = 0; j <= 15; j++){
            resAuxiliar [15-(j+1)] = a[15-j];
        }
        big_copia (a, resAuxiliar);
    }
    if (n%8 > 0){
        for (int i = 15; i >= 0; i--){
            resAuxiliar[i] = (a[i] >> (n % 8))|sobra;
            sobra = a[i] << (8 - (n % 8));
        }
    }
    big_copia (res, resAuxiliar);
}

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n){
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt resAuxiliar;
    int quociente = n/8;
    unsigned char sobra = 0x00;
    if ((a[15] & 0x80) == 0x80){
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0xff;
        }
        for (int i = quociente; i > 0; i--){
            for (int j = 0; j <= 15; j++){
                resAuxiliar [15-(j+1)] = a[15-j];
            }
            big_copia (a, resAuxiliar);
        }
        if ((n % 8) > 0){
            for (int i = 15; i >= 0; i--){
                resAuxiliar[i] = ((signed char)a[i] >> (n % 8))|sobra;
                sobra = a[i] << (8 - (n % 8));
            }
        }
    } else {
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0x00;
        }
        for (int i = quociente; i > 0; i--){
            for (int j = 0; j <= 15; j++){
                resAuxiliar [15-(j+1)] = a[15-j];
            }
            big_copia (a, resAuxiliar);
        }
        if ((n % 8) > 0){
            for (int i = 15; i >= 0; i--){
                resAuxiliar[i] = (a[i] >> (n % 8))|sobra;
                sobra = a[i] << (8 - (n % 8));
            }
        }
    }

    big_copia (res, resAuxiliar);
}



