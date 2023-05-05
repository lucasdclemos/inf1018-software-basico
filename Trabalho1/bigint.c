/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdio.h>
#include "bigint.h"

void big_copia (BigInt, BigInt);

/* Atribuição */
void big_val (BigInt res, long val){
    char* p = (char*) &val; // Linha para transformar o long em uma sequência de char
    int i;
    for (i = 0; i < 2*(sizeof(long)); i++){
        if (i > 7){ // Caso i > 7, copiar byte mais significativo do long
            res[i] = *(p + 7);
        } else{
            res[i] = *(p + i);
        }
    }
}

/* res = a + b */
void big_sum(BigInt res, BigInt a, BigInt b){
    /* A variável resto guarda o resto da soma de cada byte */
    unsigned char resto = 0;
    for (int i = 0; i < 2*(sizeof(long)); i++){
        /* A variável temp guarda a soma de a[i], b[i] e o resto da soma anterior. O tipo de temp é unsigned int, para ter espaço caso a soma tenha uma sobra */
        unsigned int temp = a[i] + b[i] + resto;
        /* O resultado da soma passa para a posição i do BigInt da resposta */
        res[i] = (unsigned char)temp;
        /* O resto é obtido pelo deslocamento de temp em 8 bits (1 byte), já que a sobra é tudo aquilo que passa o valor de 1 byte */
        resto = temp >> 8;
    }
}

/* res = -a */
void big_comp2(BigInt res, BigInt a){
    BigInt auxiliar;
    BigInt valor1; // A variável valor1 serve apenas para guardar o número 1 para somar
    for (int i = 0; i < 2*(sizeof(long)); i++){
        auxiliar[i] = ~a[i]; // Seguindo a lógica do cálculo do complemento a 2, esta linha inverte os bits da cada byte do BigInt
    }
    big_val(valor1, 1); // Em seguida, soma-se 1 ao resultado, utilizando a função big_sum implementada
    big_sum(res, auxiliar, valor1);
}

/* res = a - b */
void big_sub(BigInt res, BigInt a, BigInt b){
    /* A função big_sub pode ser realizada usando as funções big_sum e big_comp2, já que a - b = a + (-b) */
    /* Assim, -b é obtido pela função big_comp2 e o resultado é somado a BigInt a */
    BigInt auxiliar;
    big_comp2(auxiliar, b);
    big_sum(res, a, auxiliar);
}

/* res = a * b */
void big_mul(BigInt res, BigInt a, BigInt b){
    int i, j, auxiliar, resto;
    BigInt temp, auxiliar1;
    big_val(temp, 0);
    for(i = 0; i < 16; i++){
        big_val(auxiliar1, 0); // Guarda o que sobrar da operação
        resto = 0;
        for(j = i; j < 16; j++)
        {
            auxiliar = ((a[i] * b[j-i]) + resto); // Resultado da multiplicação de a por b, somando o resto da multiplicação anterior
            auxiliar1[j] = auxiliar & 0xFF; // Guarda o valor que irá caber no byte
            resto = auxiliar >> 8; // Preparar o resto para a próxima soma       
        }
        big_sum(temp, temp, auxiliar1);
    }
    big_copia(res, temp);

}

/* res = a */
void big_copia (BigInt res, BigInt a){
    /* Função criada pelo grupo para auxiliar nos casos em que é necessário copiar o BigInt de uma variável para outra */
    for (int i = 0; i < 16; i++){
        res[i] = a[i];
    }
}

/* res = a << n */
void big_shl(BigInt res, BigInt a, int n){
    /* Caso o deslocamento seja de 0, o valor de a continua o mesmo. Por isso, res = a */
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt multiplicadorDois; // Variável auxiliar que serve para armazenar o BigInt com valor 2
    BigInt auxiliar;
    big_val(multiplicadorDois, 2);
    /* Como um shift para a esquerda representa multiplicar o valor por 2, este loop multiplica o valor por 2 a quantidade de shift do BigInt */
    for (int i = n; i > 0; i--){
        big_copia(auxiliar, res);
        big_mul(auxiliar, a, multiplicadorDois);
        big_copia(a, auxiliar);
    }
    big_copia(res, auxiliar);
}

/* res = a >> n (lógico)*/
void big_shr(BigInt res, BigInt a, int n){
    /* Caso o deslocamento seja de 0, o valor de a continua o mesmo. Por isso, res = a */
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt resAuxiliar = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    int quociente = n/8; // Guarda a quantidade de bytes completos que foram shiftados
    unsigned char sobra = 0x00; 
    /* Para a quantidade de bytes completos, basta copiar o byte de a na posição i para a posição i-1, já que está em Little-Endian */
    for (int i = quociente; i > 0; i--){
        for (int j = 0; j <= 15; j++){
            resAuxiliar [15-(j+1)] = a[15-j];
        }
        big_copia (a, resAuxiliar);
    }
    /* Para o resto da divisão, é necessário shiftar byte e byte, sempre guardando a sobra de cada byte na variável sobra */
    if (n%8 > 0){
        for (int i = 15; i >= 0; i--){
            resAuxiliar[i] = (a[i] >> (n % 8))|sobra;
            sobra = a[i] << (8 - (n % 8)); // A sobra é obtida shiftando o byte 8 menos o resto da divisão
        }
    }
    big_copia (res, resAuxiliar);
}

/* res = a >> n (aritmético)*/
void big_sar(BigInt res, BigInt a, int n){
    /* Caso o deslocamento seja de 0, o valor de a continua o mesmo. Por isso, res = a */
    if (n == 0){
        big_copia(res, a);
        return;
    }
    BigInt resAuxiliar;
    int quociente = n/8; // Guarda a quantidade de bytes completos que foram shiftados
    unsigned char sobra = 0x00;
    // Verifica se é negativo, inicializando o vetor completo como 0xff
    if ((a[15] & 0x80) == 0x80){
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0xff;
        }
        /* Para a quantidade de bytes completos, basta copiar o byte de a na posição i para a posição i-1, já que está em Little-Endian */
        for (int i = quociente; i > 0; i--){
            for (int j = 0; j <= 15; j++){
                resAuxiliar [15-(j+1)] = a[15-j];
            }
            big_copia (a, resAuxiliar);
        }
        if ((n % 8) > 0){
            /* Para o resto da divisão, é necessário shiftar byte e byte, sempre guardando a sobra de cada byte na variável sobra */
            for (int i = 15; i >= 0; i--){
                resAuxiliar[i] = ((signed char)a[i] >> (n % 8))|sobra;
                sobra = a[i] << (8 - (n % 8));
            }
        }
    } else {
        // Verifica se é positivo, inicializando o vetor completo como 0x00
        for (int i = 0; i <= 15; i++) {
            resAuxiliar[i] = 0x00;
        }
        /* Para a quantidade de bytes completos, basta copiar o byte de a na posição i para a posição i-1, já que está em Little-Endian */
        for (int i = quociente; i > 0; i--){
            for (int j = 0; j <= 15; j++){
                resAuxiliar [15-(j+1)] = a[15-j];
            }
            big_copia (a, resAuxiliar);
        }
        if ((n % 8) > 0){
            /* Para o resto da divisão, é necessário shiftar byte e byte, sempre guardando a sobra de cada byte na variável sobra */
            for (int i = 15; i >= 0; i--){
                resAuxiliar[i] = (a[i] >> (n % 8))|sobra;
                sobra = a[i] << (8 - (n % 8));
            }
        }
    }

    big_copia (res, resAuxiliar);
}



