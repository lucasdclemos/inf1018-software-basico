#include <stdio.h>

int* foo (int a[], int n);

int main (void)
{
	int a[6] = {1, 2, 3, 4, 5, 6};
	int *b = foo(a, 6); // void, como testar?
    
	for (int i = 0; i < 6; i++){
        printf("%d\n", b[i]);
    }
	return 0;
}