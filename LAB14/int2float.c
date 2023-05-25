#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define makefloat(s,e,f) ((s & 1)<<31 | (((e) & 0xff) << 23) | ((f) & 0x7fffff))
#define getsig(x)  ((x)>>31 & 1)
#define getexp(x)  ((x)>>23 & 0xff)
#define getfrac(x) ((x) & 0x7fffff)

typedef union { 
    float f;
    unsigned int i;
} U;

float int2float(int i){
    U u;
    unsigned valor_absoluto = abs(i);
    unsigned frac_total;

    unsigned expoente = 0;
    for(unsigned num = valor_absoluto; num>=1; num=num/2){
        expoente++;
    }
    expoente--;
    unsigned exp = expoente + (unsigned)127;

    unsigned frac_1 = valor_absoluto - pow(2,expoente);
    if (expoente<=23)
		frac_total = frac_1<<(23-expoente);
	else
		frac_total = frac_1>>(expoente-23);
    
    unsigned sinal;
    if(i == 0){
        return 0.0;
    }
    else if(i > 0){
        sinal = 0;
    }else{
        sinal = 1;
    }

	u.i = makefloat(sinal, exp, frac_total);
	return u.f; 
}

int main() {
   int i;

   printf("\n******** int2float ****************\n");
   i = 0;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 1;  
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -1;  
   printf(" %d -> %10.4f\n", i, int2float(i));
   i = 0x7fffffff;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -i;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = -12345;
   printf(" %d -> %+10.4f\n", i, int2float(i));
   i = 86118465;          /*esse número tem 27 bits (mais que 23) e é não periódico: 101001000100001000001000001 */
   printf(" %d -> %+10.4f\n", i, int2float(i));
   return 0;
}



/* 
2²=4 exp=0
2¹=2 exp=1
2⁰=1 exp=2

 */