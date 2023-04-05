#include <stdio.h>

int main(void){
    int valor = 1;
    
    for(; valor <= 10; valor++){
        printf("Quadrado de %d: %d\n", valor, (valor*valor));
    }

    return 0;
}