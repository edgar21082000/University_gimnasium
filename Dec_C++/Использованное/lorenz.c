#include <stdio.h>
#include <stdlib.h>

int main(){
	double x, y ,z, tau, q, r, b;
	
	x=1.; y=0. ; z=0. ; tau = 0.001 ;
	q=10.; r=28; b=8/3;
	
	int i; FILE *A; A=fopen("lorenz.txt", "w");
	for(i=0;i<10000;i++){
		fprintf(A, "%lf %lf %lf\n", x ,y, z);
		x=x+tau*q*(y-x);
		y=y+tau*(x*(r-z)-y);
		z=z+tau*(x*y-b*z);
	} 
	return 0;
	
}
