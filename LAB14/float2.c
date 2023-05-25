#include <stdio.h>

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

typedef union { 
    float f;
    unsigned int i;
} U;


float float2(float f){
    U u;
    u.f = f;
    unsigned sinal = getsig(u.i);
    unsigned exp = getexp(u.i);
    unsigned frac = getfrac(u.i);
    exp++;
    u.i = makefloat(sinal, exp, frac);
    return u.f;
}

int main(void) {
	float valor = 50000.0;

	printf("Valor = %f\n", valor);
	valor = float2(valor);
	printf("Valor * 2 = %f\n", valor);

	return 0;
}