#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//double power(double x, int N);
double fact(int N);

int main(){
	int i; int N=50;
	double res=1;
	double x=-15. ;
	
	for(i=1;i<=N;i++) res+=(pow(x, i)/pow(10, 3*i))/fact(i);
	
	printf("sum: %e\n", res);
	
	double real = exp(x);
	printf("exp: %e\n", real) ;
	
	return 0;
}


double fact(int N){
	int i;
	double res = 1;
	for(i=1;i<=N;i++) res=(res*i)/10;
	return res;
}

