/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdlib.h>
#include <string.h>
#include "gera.h"

int testa_gera (char nome[], unsigned char codigo[]){
    FILE *f = fopen(nome, "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    if (gera(f, codigo) != NULL){
        funcp funcaoSimples = gera(f, codigo);
        //printf("Retorno: %d\n", funcaoSimples(6));
        return funcaoSimples(1, 2, 3);
    }
    return 0;
}

int main(){
    unsigned char codigo[1000];

    // Caso de retornos simples de variáveis e atribuição de parâmetros
    if (testa_gera("testes/simples1.txt", codigo) == 4){
        printf("OK -> retorno e atribuição de uma variável (v1)\n");
    }else{
        printf("ERRO -> retorno e atribuição de uma variável (v1)\n");
    }
    
    if (testa_gera("testes/simples2.txt", codigo) == 4){
        printf("OK -> retorno e atribuição de uma variável (v1)\n");
    }else{
        printf("ERRO -> retorno e atribuição de uma variável (v1)\n");
    }

    if (testa_gera("testes/simples3.txt", codigo) == 4){
        printf("OK -> retorno e atribuição de uma variável (v3)\n");
    }else{
        printf("ERRO -> retorno e atribuição de uma variável (v3)\n");
    }
    
    if (testa_gera("testes/simples4.txt", codigo) == 4){
        printf("OK -> retorno e atribuição de uma variável (v4)\n");
    }else{
        printf("ERRO -> retorno e atribuição de uma variável (v4)\n");
    }

    if (testa_gera("testes/simples5.txt", codigo) == 4){
        printf("OK -> retorno e atribuição de uma variável (v5)\n");
    }else{
        printf("ERRO -> retorno e atribuição de uma variável (v5)\n");
    }

    if (testa_gera("testes/simples6.txt", codigo) == 1){
        printf("OK -> retorno de uma constante positiva\n");
    }else{
        printf("ERRO -> retorno de uma constante positiva\n");
    }

    if (testa_gera("testes/simples7.txt", codigo) == -1){
        printf("OK -> retorno de uma constante negativa\n");
    }else{
        printf("ERRO -> retorno de uma constante negativa\n");
    }
    
    if (testa_gera("testes/simples8.txt", codigo) == 0){
        printf("OK -> retorno de uma constante igual a 0\n");
    }else{
        printf("ERRO -> retorno de uma constante igual a 0\n");
    }

    // Atribuição variavel = parametro
    if (testa_gera("testes/simples9.txt", codigo) == 1){
        printf("OK -> variavel = parametro\n");
    }else{
        printf("ERRO -> variavel = parametro\n");
    }

    // Atribuição variavel = varivavel 
    if (testa_gera("testes/simples10.txt", codigo) == 10){
        printf("OK -> variavel = variavel\n");
    }else{
        printf("ERRO -> variavel = variavel\n");
    }

    // Soma variavel + varivavel 
    if (testa_gera("testes/simples11.txt", codigo) == 3){
        printf("OK -> variavel = variavel + variavel\n");
    }else{
        printf("ERRO -> variavel = variavel + variavel\n");
    }

    if (testa_gera("testes/simples12.txt", codigo) == 3){
        printf("OK -> variavel = variavel + constante\n");
    }else{
        printf("ERRO -> variavel = variavel + constante\n");
    }
    
    if (testa_gera("testes/simples13.txt", codigo) == 3){
        printf("OK -> variavel = constante + variavel\n");
    }else{
        printf("ERRO -> variavel = constante + variavel\n");
    }
    return 0;
}