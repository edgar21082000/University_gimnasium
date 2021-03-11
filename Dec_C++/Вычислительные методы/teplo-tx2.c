#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(FILE *A, double *V, int M);
void trans(double *V, double *V_new, int M);

double pi=4*atan(1.);

int main(){
	FILE *A; A=fopen("matr_out2.txt", "w");
	FILE *B; B=fopen("matr_out2_U.txt", "w");
	
	int i, j;
	
	int  M=100;
	double h=pi/(M-1);
	double t=(1e-3)/2;
	
	double *V; V=(double *)malloc(M*sizeof(double));
	double x=0.;
	for(i=0;i<M-1;i++){
		V[i]=sin(x);
		x+=h;
	}
	V[M-1]=1.;
	
	print(A, V, M);
	
	double *V_new; V_new=(double *)malloc(M*sizeof(double));
	
	
	for(i=0;i<100;i++){
		V_new[0]=0.;
		V_new[M-1]=1.;
		
		for(j=1;j<M-1;j++){
			V_new[j]=t*(V[j+1]-2*V[j]+V[j-1])/(h*h) + 10*t*exp(-(j*h-pi/2)*(j*h-pi/2))+ V[j];
		}
		print(A, V_new, M);
		trans(V, V_new, M);
	}
	
	
	double *W; W=(double *)malloc(M*sizeof(double));
	for(i=0;i<100;i++){
		for(j=0;j<M;j++) W[j]=exp(-t*i)*sin(j*h);
		print(B, W, M);
	}
	
	
	fclose(A);
	fclose(B);
	
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
