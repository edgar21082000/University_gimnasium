#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double);
double U(double);
void prn(double *, int, FILE *);

double pi = 4*atan(1.);

int main(){
	FILE *A; A=fopen("teplo.txt", "w");
	
	int i;
	int N=10000000;
	double h = pi/N;
	
	double *V; V=(double *)malloc((N+1)*sizeof(double));
	double x=0.;
	V[0]=U(x);
	x+=h;
	V[1]=U(x);
	
	for(i=1;i<=N-1;i++){
		V[i+1]=f(x)*h*h+2*V[i]-V[i-1];
		x+=h;
	}
	fprintf(A, "%e", U(x)-V[N]);
	
	//prn(V, N, A);
	return 1;
}

double f(double x){
	return 0;
}

double U(double x){
	return x+2;
}

void prn(double *V, int N, FILE *A){
	int i;
	double x=0.;
	double h=pi/N;
	for(i=0;i<=N;i++){
		fprintf(A, "%lf %lf %lf %e\n", x, V[i], U(x), U(x)-V[i]);
		x+=h;
	}
	return;
}
