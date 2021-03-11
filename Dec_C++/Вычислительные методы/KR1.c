#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	FILE *A; A=fopen("kr1_out.txt", "w");
	
	int i;
	int N=11;
	double h=0.1;
	double x=0.;
	
	double Y0=1;
	double Y1=2;
	double Y2=3;
	
	fprintf(A, "%lf  %lf %lf %lf\n", x, Y0, Y1, Y2);
	
	x+=h;
	/*double *Y0; Y0=(double *)malloc(N*sizeof(double));
	double *Y1; Y1=(double *)malloc(N*sizeof(double));
	double *Y2; Y2=(double *)malloc(N*sizeof(double));*/
	
	double tmp0 = Y0;
	double tmp1 = Y1;
	double tmp2 = Y2;
	
	for(i=1;i<11;i++){
		Y0=(x*sin(tmp1))*h+tmp0;
		Y1=(x*x+sin(tmp0))*h+tmp1;
		Y2=(x+x*x+tmp1+tmp0+tmp2)*h+tmp2;
		
		fprintf(A, "%lf  %lf %lf %lf\n", x, Y0, Y1, Y2);
		x+=h;
		
		tmp0 = Y0;
		tmp1 = Y1;
		tmp2 = Y2;
	}
	
	return 0;	
	
	
	
}

/*double y0(double x){
	return x*sin(y1(x));
}

double y1(double x){
	return x*x + sin(y0(x))
}

double y2(double x){
	return x +x*x + sin(y0(x))+sin(y1(x))+sin(y2(x));
}*/
