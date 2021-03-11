#include <stdio.h>
#include <math.h> 

int main(){
	double x = -1/3;
	double y = -5/3;
	
	double res = (sqrt((9-25*x*x+10*x*y-y*y)*(9-25*x*x+10*x*y-y*y)*(9-25*x*x+10*x*y-y*y)*(9-25*x*x+10*x*y-y*y)*(9-25*x*x+10*x*y-y*y)));
	//(5*x*x-8*x*y+5*y*y-10*x+14*y+55);
	printf("%lf", res);
	return 0;
	
}
