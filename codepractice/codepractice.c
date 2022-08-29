#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int power(int m, int n);

int main(int argc, char* argv[]) {
	#0827
		int i;
	for (i = 0; i < 10; i++)
		printf("%d %d %d\n", i, power(2, i), power(-3, i));
	return 0;
}

int power(int base, int n)
{
	int i, p;
	int i, p;
	p = 1;
	for (i = 1; i <= n; i++)
		p = p * base;
	return p;
}