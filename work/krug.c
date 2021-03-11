#include <stdio.h>
#include <math.h>

int main(void)
{
	double x, y, z , r;
	double k, D, z1, z2;
	y=24.5;
	r=0.5;
	/* (x-a)^2+(z-b)^2=r^2
		т.к у нас a=b, то получаем:
		x^2+z^2-2*a*(x+z)+2*a^2=r^2;
		
		
		Или втоой вариант через синус;
	*/
	for (x=8.0;x<9.1;x+=0.1)
	{
		k=r*r-x*x-2*r*r+2*r*x;
		D=sqrt(r*r+k);
		z1=D+r;
		z2=D-r;
		printf("%25.12lf%25.12lf", z1, z2);
	}
	return 0;	
}