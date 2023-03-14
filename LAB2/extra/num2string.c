#include <stdio.h>

void num2string(char *s, int num, int base){
    int contador = num;
    char c;
    while ((num) >= 1){
        if (base > 10){
            if ((num%base) == base){
                c = 97;
                s[contador-1] = c;
            }
            else{
                c = 97 + ((num%base) - 10);
                s[contador-1] = c;
            }
        }
        else{
            s[contador-1] = num%base;
            num = num/base;
            contador--;
        }
        
    }

}

int main(void){
    char s[8];
    num2string(s, 8, 2);
    printf("%s", s);

    return 0;
}