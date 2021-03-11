#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int i, j;
	double pi = 4. * atan(1.);
	
	int N = 100;
	double ty=1/(double)N; printf("%lf\n", ty);
	
	double* f; f=(double *)malloc(101*sizeof(double));
	double* t; t=(double *)malloc(101*sizeof(double));
	
	for(i=0;i<101;i++){
		t[i]=(double)i*ty;
		f[i]=-1.*(t[i]*t[i]-1)*t[i];
	}
	
	for(i=0;i<101;i++) printf("%lf - %lf\n", t[i], f[i]);
	printf("\n--------------\n");
	
	double* c; c=(double *)malloc(101*sizeof(double));
	
	double sum1 = 0;
	double sum2 = 0;
	FILE* A;A=fopen("out.txt", "w");
	
	for(i=1;i<100;i++){           //Заполнение c[i];
		for(j=1;j<N-1;j++) sum1+=f[j]*sin(pi*i*t[j]);
		for(j=1;j<N-1;j++) sum2+=(sin(pi*i*t[j]))*(sin(pi*i*t[j]));
		c[i]=sum1/sum2;
		printf("%d - %lf %lf: %lf\n", i, sum1, sum2, c[i]);
		fprintf(A, "%lf %lf\n", t[i], c[i]);
		sum1=0. ; sum2=0. ;
	}
	fclose(A);
	return 777;
}
