#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>
double metod_hord (double a, double b, double eps,double (*) (double));
double f (double x);
int main (){
	double a=1, b=2, eps=1.e-15;
	metod_hord (a,b,eps,f);
	return 0;
}

double f (double a){
	//printf ("res %lf %lf\n", a,a*a-2 );
	return (a*a-2);
}

double metod_hord (double a, double b, double eps,double (*f) (double)){
	int i=0;
	double xn_1;
	while ((f(a+eps/2)*f(a-eps/2))>=0){
		i++;
		xn_1=a-((a-b)/(f(a)-f(b)))*f(a);
		b=a;
		a=xn_1;
		//printf ("!a=%.20lf, b=%.20lf\n",a,b);
		//printf ("%.20lf",fabs (f(a+eps/2)*f(a-eps/2)));
	}
	printf ("%.20lf\n",a);
	printf ("%.20lf\n",sqrt(2));
	printf ("kol-vo iter %d\n",i);
	return 0;
}