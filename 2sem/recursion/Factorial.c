#include <stdio.h>
int f (int);
int main () {
	int n;
	scanf ("%d",&n);
	printf ("%d",f(n));
}
int f (int n) {
	if (n==1) return 1;
	return n*f(n-1);
}