#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(FILE *A, double *V, int M);
void trans(double *V, double *V_new, int M);

double pi=4*atan(1.);

int main(){
	FILE *A; A=fopen("KR3_out.txt", "w");
	
	
	int i, j;
	
	int  M=20;
	double h=pi/(M-1);
	double t=0.1;
	
	double *V; V=(double *)malloc(M*sizeof(double));
	double x=0.;
	for(i=0;i<M-1;i++){
		V[i]=0.5*sin(x);
		x+=h;
	}
	V[M-1]=0;
	
	print(A, V, M);
	
	double *V_new; V_new=(double *)malloc(M*sizeof(double));
	
	
	for(i=0;i<10;i++){
		V_new[0]=0.;
		V_new[M-1]=0.;
		
		for(j=1;j<M-1;j++){
			V_new[j]=t*(V[j+1]-2*V[j]+V[j-1])/(h*h) + t*sin(j*h)+ V[j];
			
		}
		print(A, V_new, M);
		trans(V, V_new, M);
	}
	
	
fclose(A);

	
	return 0;
}

void print(FILE *A, double *V, int M){
	int i;
	for(i=0;i<M;i++) fprintf(A, "%7.2lf ", V[i]);
	fprintf(A, "\n");
	return; 
}

void trans(double *V, double *V_new, int M){
	int i;
	for(i=0;i<M;i++) V[i]=V_new[i];
	return;
}
