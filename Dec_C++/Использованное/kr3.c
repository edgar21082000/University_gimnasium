#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double pi = 4*atan(1.);
	double tau = 0.001;
	int i;
	
	double x0=0. ; double x1=x0; double x, y, z;
	double y0=1. ; double y1=y0;
	double z0=0. ; double z1=z0;
	
	FILE *A; A=fopen("kr3_out.txt", "w");
	FILE *B; B=fopen("kr3_out2.txt", "w");
	fprintf(A, "%lf %lf %lf\n", x, y , z);
	
	for(i=1; i*tau<2*pi;i++){
		x=x0*tau+exp(i*tau)*y0+x0;
		y=-x0*exp(-i*tau)*tau+y0;
		z=y0*tau+z0;
		
		x0=x; y0=y;z0=z;
		
		x1=exp(i*tau)*sin(i*tau);
		y1=cos(i*tau);
		z1=sin(i*tau);
		
		fprintf(A, "%lf %lf %lf\n", x, y, z);
		fprintf(B, "%lf %lf %lf\n", x1, y1, z1);
	}
	return 0;
}
