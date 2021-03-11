#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	double u0 = 2;
	double tau = 0.1;
	
	double res[1000];
	double eres[1000];
	
	res[0]=u0; eres[0]=u0;
	
	int i;
	for(i=1;i<1000;i++){
		res[i]=res[i-1]-tau*10*res[i-1];
		eres[i]=exp(-10*tau*(i-1))*2;
	}
	
	FILE *A; A=fopen("difur.txt", "w");
	for(i=0;i<1000;i++) fprintf(A, "%d %e %e\n", i, eres[i], res[i]);
	
	return;
	
	
}
