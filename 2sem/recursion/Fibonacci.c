#include <stdio.h>
int Fib (int);
int main () {
	int n;
	scanf ("%d",&n);
	printf ("%d",Fib(n));
}

int Fib (int n) {
	if ((n==1)||(n==2)) return 1;
	return Fib(n-2)+Fib(n-1);
}