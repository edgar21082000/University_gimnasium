#include <stdio.h>
#include <math.h>

int main(){
	double x, res;
	
	while(scanf("%lf", &x)==1){
	
	res = pow(x, 4)-4*pow(x, 3)+5*pow(x, 2)+22*x-24;
	printf("res = %lf\n", res);
}
	return 0;
}
