/* Lucas Demarco Cambraia Lemos 2110013 3WA */
/* Lucas de Oliveira Caúla 2020557 3WB */

#include <stdlib.h>
#include "gera.h"

int main(void){
    FILE *f = fopen("simples.txt", "r");
    if(f == NULL){
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    

    unsigned char codigo[300];
    funcp funcaoSimples = gera(f, codigo);
    printf("Retorno: %d\n", funcaoSimples(1, 2, 3));
    return 0;
}