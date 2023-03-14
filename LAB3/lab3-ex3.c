#include <stdio.h>

unsigned char switch_byte(unsigned char x){
    unsigned char primeira_metade = x;
    unsigned char segunda_metade = x;
    primeira_metade = 0xf0;
    primeira_metade = primeira_metade & x;
    primeira_metade = primeira_metade >> 4;
    segunda_metade = x << 4;
    return (primeira_metade | segunda_metade);
}

unsigned char rotate_left(unsigned char x, int n){
    unsigned char auxiliar;
    while (n > 0){
        auxiliar = 0x80 & x;
        auxiliar = auxiliar >> 7;
        x = x << 1;
        x = x | auxiliar;
        n--;
    }
    return x;
}

int main(void){
    unsigned char teste= 0xab;
    unsigned char teste2 = 0x61;
    printf("%02x\n", switch_byte(teste));
    printf("%02x\n", rotate_left(teste2, 1));
    printf("%02x\n", rotate_left(teste2, 2));
    printf("%02x\n", rotate_left(teste2, 7));

    return 0;
}


