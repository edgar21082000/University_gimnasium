#include <stdio.h>
#include <math.h>

int main()
{
	const double g = 9.8;
	double x0, h, v, a, i, t, x, y;
	int k=0;
	scanf("%lf", &h);
	scanf("%lf", &v);
	scanf("%lf", &a);
	x0=0;
	t=0.0;
	for (i=0;i<100;i++)
	{
		k+=1;
		t+=0.01;
		x=x0+v*t*cos(a);
		y=h+v*t*sin(a)-(g*t*t)/2;
		printf("%d) t = %lf   x = %lf   y = %lf \n  ",k ,  t, x, y);
	}
	
}