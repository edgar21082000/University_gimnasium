#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>
#include <math.h>
double metod_N (double b, double eps,double (*) (double),double (*) (double) );
double f (double x);
double df_1 (double a);
double df_2 (double a);
double df_3 (double a);


int main (){
	double a=1, b=1, eps=1e-14;
	metod_N (a,eps,f,df_1);
	return 0;
}

double f (double a){
	//printf ("res %lf %lf\n", a,a*a-2 );
	return (sin(a)-1);
}

double df_1 (double a){
	return cos(a);
}

double df_2 (double a){
	double h=1e-12;
	return((sin(a+h)-sin(a))/(h));
}

double df_3 (double a){
	double h=1e-12;
	return((sin(a+h)-sin(a-h))/(2*h));
}

double metod_N (double b, double eps,double (*f) (double),double (*df_1) (double)){
	int i=0;
	double b_pred;
	while (fabs(b-b_pred)>eps){
		i++;
		b_pred=b;
		b=b-f(b)/df_1(b);
		printf ("b=%.20lf\n",b);
		//printf ("%.20lf",fabs (f(a+eps/2)*f(a-eps/2)));
	}
	printf ("%.20lf\n",b);
	printf ("%.20lf\n",4*atan(1.)/2);
	printf ("kol-vo iter %d\n",i);
	return 0;
}
