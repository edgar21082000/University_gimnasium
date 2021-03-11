#include <stdio.h>

int f(int);

int f(int n)
{
	if (n==1) return 1;
	return n*f(n-1);
}

int main()
{
	int x;
	scanf("%d", &x);
	x=f(x);
	printf("||%d||", x);
	return 0;
}