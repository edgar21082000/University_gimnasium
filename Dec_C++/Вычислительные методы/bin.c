#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double func(double x);
double find(double a, double b, double eps);

int main(){
	
	double a = -1;
	double b = 1;
	double eps = 1e-15;
	
	double res = find(a, b, eps);
	printf("%lf", res);
}

double func(double x){
	return x*x-2; 
}

double find(double a, double b, double eps){
	int k=0;
	double x, f;
	
	do{
    x = (a+b)/2; 
    f = func(x);
    if (f > 0) b = x;
    else a = x;
    k++;
  } while (fabs(f)>eps && k<10000);
  
  printf("iteration - %d\n", k);
  
  return x;
}


