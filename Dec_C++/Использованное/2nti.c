#include <stdio.h>

int main(){
	double x0, x1, x2, x3;
	double a0, a1, a2, a3, a4;
	x0=1.;    a0=5.;
	x1=3.;    a1=-2.;
	x2=4.;	  a2=0.5;
	x3=4.5;	  a3=-0.1; 
	a4=0.003;
	
	double x=2.5;
	
	double res = a0+a1*(x-x0)+a2*(x-x0)*(x-x1)+a3*(x-x0)*(x-x1)*(x-x2)+a4*(x-x0)*(x-x1)*(x-x2)*(x-x3);
	printf ("%lf", res);
	
	return 0;
}
