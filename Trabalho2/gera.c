/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"

int i;

typedef struct desvios Desvios;
struct desvios{
    int pos_vazia;
    unsigned char end_origem;
    int linha_destino;
};


void realiza_operacoes(int ind_res, int ind_op1, int ind_op2, char op1, char op2, char operacao, unsigned char* codigo){
    // var = var (+,-,*) var
    if (op1 == 'v' && op2 == 'v'){
        codigo[i++] = 0x8b; 
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_op1 + 1;
        codigo[i++] = 0x8b;
        codigo[i++] = 0x5d;
        codigo[i++] = 255 - 4*ind_op2 + 1;
        // var = var + var
        if (operacao == '+'){
            codigo[i++] = 0x01;
            codigo[i++] = 0xd8;
        }
        // var = var - var
        else if (operacao == '-'){
            codigo[i++] = 0x29;
            codigo[i++] = 0xd8;
        }
        // var = var * var
        else if (operacao == '*'){
            codigo[i++] = 0x0f;
            codigo[i++] = 0xaf;
            codigo[i++] = 0xc3;
        }
        codigo[i++] = 0x89;
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_res + 1;
    }
    // var = var (+,-,*) constante
    if (op1 == 'v' && op2 == '$'){
        codigo[i++] = 0x8b;
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_op1 + 1;
        codigo[i++] = 0xbb;
        codigo[i++] = (ind_op2 << 24) >> 24;
        codigo[i++] = (ind_op2 << 16) >> 24;
        codigo[i++] = (ind_op2 << 8) >> 24;
        codigo[i++] = ind_op2 >> 24;
        // var = var + constante
        if (operacao == '+'){
            codigo[i++] = 0x01;
            codigo[i++] = 0xd8;
        }
        // var = var - constante
        else if (operacao == '-'){
            codigo[i++] = 0x29;
            codigo[i++] = 0xd8;
        }
        // var = var * constante
        else{
            codigo[i++] = 0x0f;
            codigo[i++] = 0xaf;
            codigo[i++] = 0xc3;
        }
        codigo[i++] = 0x89;
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_res + 1;
    }
    // var = constante (+,-,*) var
    if (op1 == '$' && op2 == 'v'){
        // var = constante + var
        if (operacao == '+'){
            codigo[i++] = 0xb8;
            codigo[i++] = (ind_op1 << 24) >> 24;
            codigo[i++] = (ind_op1 << 16) >> 24;
            codigo[i++] = (ind_op1 << 8) >> 24;
            codigo[i++] = ind_op1 >> 24;
            codigo[i++] = 0x8b;
            codigo[i++] = 0x5d;
            codigo[i++] = 255 - 4*ind_op2 + 1;
            codigo[i++] = 0x01;
            codigo[i++] = 0xd8;
        }
        // var = constante - var
        if (operacao == '-'){
            codigo[i++] = 0xb8;
            codigo[i++] = (ind_op1 << 24) >> 24;
            codigo[i++] = (ind_op1 << 16) >> 24;
            codigo[i++] = (ind_op1 << 8) >> 24;
            codigo[i++] = ind_op1 >> 24;
            codigo[i++] = 0x8b;
            codigo[i++] = 0x5d;
            codigo[i++] = 255 - 4*ind_op2 + 1;
            codigo[i++] = 0x29;
            codigo[i++] = 0xd8;
        }
        // var = constante * var
        if (operacao == '*'){
            codigo[i++] = 0x8b;
            codigo[i++] = 0x45;
            codigo[i++] = 255 - 4*ind_op2 + 1;
            codigo[i++] = 0xbb;
            codigo[i++] = (ind_op1 << 24) >> 24;
            codigo[i++] = (ind_op1 << 16) >> 24;
            codigo[i++] = (ind_op1 << 8) >> 24;
            codigo[i++] = ind_op1 >> 24;
            codigo[i++] = 0x0f;
            codigo[i++] = 0xaf;
            codigo[i++] = 0xc3;
        }
        codigo[i++] = 0x89;
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_res + 1;
    }
    // var = constante (+,-,*) constante
    if (op1 == '$' && op2 == '$'){
        codigo[i++] = 0xb8;
        codigo[i++] = (ind_op1 << 24) >> 24;
        codigo[i++] = (ind_op1 << 16) >> 24;
        codigo[i++] = (ind_op1 << 8) >> 24;
        codigo[i++] = ind_op1 >> 24;
        codigo[i++] = 0xbb;
        codigo[i++] = (ind_op2 << 24) >> 24;
        codigo[i++] = (ind_op2 << 16) >> 24;
        codigo[i++] = (ind_op2 << 8) >> 24;
        codigo[i++] = ind_op2 >> 24;
        // var = constante + constante
        if (operacao == '+'){
            codigo[i++] = 0x01;
            codigo[i++] = 0xd8;
        }
        // var = constante - constante
        else if (operacao == '-'){
            codigo[i++] = 0x29;
            codigo[i++] = 0xd8;
        }
        // var = constante * constante
        else{
            codigo[i++] = 0x0f;
            codigo[i++] = 0xaf;
            codigo[i++] = 0xc3;
        }
        codigo[i++] = 0x89;
        codigo[i++] = 0x45;
        codigo[i++] = 255 - 4*ind_res + 1;
    }
}

funcp gera(FILE* f, unsigned char codigo[]){
    unsigned char enderecos[30];
    Desvios vetor_desvios[30];
    int num_desvios = 0;
    enderecos[0] = 0x08;
    funcp f_codigo;
    char c;
    i = 0;
    int linha_atual = 0;

    // Criação da pilha e alocação do espaço para as 5 variáveis locais permitidas (subq $32)
    codigo[i++] = 0x55;
    codigo[i++] = 0x48;
    codigo[i++] = 0x89;
    codigo[i++] = 0xe5;
    codigo[i++] = 0x48;
    codigo[i++] = 0x83;
    codigo[i++] = 0xec;
    codigo[i++] = 0x20;

    while ((c = fgetc(f)) != EOF){
        switch(c){
            // Caso de retorno
            case 'r':{
                char tipo;
                int num;
                if (fscanf(f, "et %c%d\n", &tipo, &num) != 2){
                    printf("Comando não reconhecido pela Linguagem Simples");
                }
                // Verificar qual tipo (variável ou constante) está sendo retornado
                switch(tipo){
                    // Caso de retornar uma constante
                    case '$':{
                        codigo[i++] = 0xb8;
                        codigo[i++] = (num << 24) >> 24;
                        codigo[i++] = (num << 16) >> 24;
                        codigo[i++] = (num << 8) >> 24;
                        codigo[i++] = num >> 24;
                        codigo[i++] = 0xc9; // leave
                        codigo[i++] = 0xc3; // ret
                        break;
                    }
                    // Caso de retornar uma variável
                    case 'v':{
                        codigo[i++] = 0x8b;
                        codigo[i++] = 0x45;
                        codigo[i++] = 255 - 4*num + 1;
                        codigo[i++] = 0xc9; // leave
                        codigo[i++] = 0xc3; // ret
                        break;
                    }
                }
                break;
            }
            // Caso de atribuição e operação aritmética
            case 'v':{
                char operacao;
                char tipo;
                int indice1;
                int indice2;
                if (fscanf(f, "%d %c\n", &indice1, &operacao) != 2){
                    printf("Comando não reconhecido pela Linguagem Simples\n");
                    break;
                }
                // Verifica se o índice da variável criada é maior que o número de variáveis permitidas
                if (indice1 > 5){
                    printf("Número de variáveis excedido!\n");
                    break;
                }
                // Verificar se é atribuição ou operação aritmética
                switch(operacao){
                    case '<':{
                        if (fscanf(f, " %c%d\n", &tipo, &indice2) != 2){
                            printf("Comando não reconhecido pela Linguagem Simples\n");
                        }
                        switch(tipo){
                            // var = constante
                            case '$':{
                                codigo[i++] = 0xc7;
                                codigo[i++] = 0x45;
                                codigo[i++] = 255 - 4*indice1 + 1;
                                codigo[i++] = (indice2 << 24) >> 24;
                                codigo[i++] = (indice2 << 16) >> 24;
                                codigo[i++] = (indice2 << 8) >> 24;
                                codigo[i++] = indice2 >> 24;
                                break;
                            }
                            // var = var
                            case 'v':{
                                codigo[i++] = 0x8b;
                                codigo[i++] = 0x45;
                                codigo[i++] = 255 - 4*indice2 + 1;
                                codigo[i++] = 0x89;
                                codigo[i++] = 0x45;
                                codigo[i++] = 255 - 4*indice1 + 1;
                                break;
                            }
                            // var = parametro
                            case 'p':{
                                // Verificar se o número de parâmetros ultrapassou o máximo permitido
                                if(indice2 > 3){
                                    printf("Número máximo de parâmetros excedido");
                                    break;
                                }
                                // Verificar qual é o parâmetro (primeiro, segundo, terceiro)
                                switch(indice2){
                                    case 1:{
                                        codigo[i++] = 0x89;
                                        codigo[i++] = 0x7d;
                                        codigo[i++] = 255 - 4*indice1 + 1;
                                        break;
                                    }
                                    case 2:{
                                        codigo[i++] = 0x89;
                                        codigo[i++] = 0x75;
                                        codigo[i++] = 255 - 4*indice1 + 1;
                                        break;                                    
                                    }
                                    case 3:{
                                        codigo[i++] = 0x89;
                                        codigo[i++] = 0x55;
                                        codigo[i++] = 255 - 4*indice1 + 1;
                                        break;
                                    }
                                }
                                break;
                            }
                        }
                        break;
                    }
                    case '=':{
                        char operando1;
                        char operando2;
                        int ind_operando1;
                        int ind_operando2;
                        char sinal;
                        if (fscanf(f, " %c%d %c %c%d\n", &operando1, &ind_operando1, &sinal, &operando2, &ind_operando2) != 5){
                            printf("Comando não reconhecido pela Linguagem Simples\n");
                            break;
                        }
                        // Função responsável por tratar de todas as operações
                        realiza_operacoes(indice1, ind_operando1, ind_operando2, operando1, operando2, sinal, codigo);
                        break;
                    }
                }
                break;
            }
            // Caso de desvio condicional
            case 'i':{
                int indice1;
                int linha_destino;
                char auxiliar;
                if (fscanf(f, "flez %c%d %d\n", &auxiliar, &indice1, &linha_destino) != 3){
                    printf("Comando não reconhecido pela Linguagem Simples\n");
                    break;
                }
                // Verifica se o índice da variável criada é maior que o número de variáveis permitidas
                if (indice1 > 5){
                    printf("Número de variáveis excedido!\n");
                    return NULL;
                }
                // cmpl  $0, variavel
                codigo[i++] = 0x83;
                codigo[i++] = 0x7d;
                codigo[i++] = 255 - 4*indice1 + 1;
                codigo[i++] = 0x00;
                // jle
                codigo[i++] = 0x7e;
                // Deixa a posição do vetor codigo vazia, e irá preencher no final
                vetor_desvios[num_desvios].pos_vazia = i;
                vetor_desvios[num_desvios].end_origem = i;
                vetor_desvios[num_desvios].linha_destino = linha_destino - 1;
                i++;
                num_desvios++;
                break;
            }          
        }
        linha_atual++;
        enderecos[linha_atual] = i;
    }
    unsigned char auxiliar;
    // Preenche o vetor codigo com os deslocamentos calculados
    for (int x = 0; x < num_desvios; x++){
        auxiliar = enderecos[vetor_desvios[x].linha_destino] - vetor_desvios[x].end_origem - 1;
        codigo[vetor_desvios[x].pos_vazia] = auxiliar;
    }
    f_codigo = (funcp)codigo;
    return f_codigo;
}