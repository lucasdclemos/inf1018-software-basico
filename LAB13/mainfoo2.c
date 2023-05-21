#include <stdio.h>

typedef int (*funcp) (int x);     // ponteiro para a função

int add (int x) {
  return x+1;
}

int main(void) {
	unsigned char codigo[] = {0x55, 0x48, 0x89, 0xe5, 0xe8, 0x00, 0x00, 0x00, 0x00, 0xc9, 0xc3};
	funcp f;   
	int i;
	int pos=5;
	int deslocamento=0;
	
	unsigned int dif = (unsigned int*)add - (unsigned int*)(codigo+9);
	for (int i=0; i<4; i++){
		codigo[pos] = dif>>deslocamento;
		pos++;
		deslocamento+=8;	
	}

	f = (funcp)codigo; 
	i = (*f)(10);
    printf("Valor de i: %d\n", i);
	
	return 0;
}