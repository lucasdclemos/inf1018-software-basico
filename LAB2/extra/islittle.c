#include <stdio.h>
//00000001 00000000

int is_little()
{
	int i = 1;
	char* p = (char*)&i;
    printf("%c\n", *p + 48);
    if ((*p + 48) == '1'){
        return 1;
    }
    else{
        return 0;
    }
}

int main(void)
{
	printf("A memória deste computador tem organização ");
	if (is_little())
		printf("little endian.\n\n");
	else
		printf("big endian.\n\n");
		
	return 0;
}