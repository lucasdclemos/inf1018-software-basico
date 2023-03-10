#include <ctype.h>
#include <stdio.h>

int string2num (char *s, int base) {
  int a = 0;
  for (; *s; s++){
    if (isdigit(*s)){
        a = a*base + (*s - '0');
    }
    else{
        a = a*base + (*s - 'a' + 10);
    }
  }
  return a;
}

int main (void) {
  printf("==> %d\n", string2num("1234", 2));
  printf("==> %d\n", string2num("1234", 2) + 1);
  printf("==> %d\n", string2num("1234", 2) + string2num("1", 2));
  return 0;
}