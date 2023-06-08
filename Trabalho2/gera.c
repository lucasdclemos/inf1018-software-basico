/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gera.h"

int i;

void realiza_operacoes(int ind_res, int ind_op1, int ind_op2, char op1, char op2, char operacao, unsigned char* codigo){
    if (op1 == 'v' && op2 == 'v'){
        if (operacao == '+'){
            codigo[i++] = 0x8b; 
            codigo[i++] = 0x45;
            codigo[i++] = 255 - 4*ind_op1 + 1;
            codigo[i++] = 0x8b;
            codigo[i++] = 0x5d;
            codigo[i++] = 255 - 4*ind_op2 + 1;
            codigo[i++] = 0x01;
            codigo[i++] = 0xd8;
            codigo[i++] = 0x89;
            codigo[i++] = 0x45;
            codigo[i++] = 255 - 4*ind_res + 1;
        }
        
    }
}

funcp gera(FILE* f, unsigned char codigo[]){
    funcp f_codigo;
    char c;
    i = 0;

    // Criação da pilha e alocação do espaço para as 5 variáveis locais permitidas
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
                if (fscanf(f, "et %c%d", &tipo, &num) != 2){
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
                    }
                    // Caso de retornar uma variável
                    case 'v':{
                        codigo[i++] = 0x8b;
                        codigo[i++] = 0x45;
                        codigo[i++] = 255 - 4*num + 1;
                        codigo[i++] = 0xc9; // leave
                        codigo[i++] = 0xc3; // ret
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
                if (fscanf(f, "%d %c", &indice1, &operacao) != 2){
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
                        if (fscanf(f, " %c%d", &tipo, &indice2) != 2){
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
                        if (fscanf(f, " %c%d %c %c%d", &operando1, &ind_operando1, &sinal, &operando2, &ind_operando2) != 5){
                            printf("Comando não reconhecido pela Linguagem Simples\n");
                            break;
                        }
                        realiza_operacoes(indice1, ind_operando1, ind_operando2, operando1, operando2, sinal, codigo);
                    }
                }
            }          
        }
    }
    f_codigo = (funcp)codigo;
    return f_codigo;
}