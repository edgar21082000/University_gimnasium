#include <stdio.h>
int i=1;
double f (double);
int main () {
	double x=1.;
	printf ("%.10lf",f(x));
}
double f (double x) {
	if (i==200) return x;
	i++;
	return 1.+1./f(x);
}