#include <stdio.h>
#include <math.h>

int main()
{
	const double g = 9.81;
	double Vn, dt, a, Vxn, Vyn, tn, T, xtn, ytn;
	int i;
    scanf ("%lf", &Vn);
	scanf ("%lf", &a);
	scanf ("%lf", &T);
	dt=0.01;
	tn=0.00;
	xtn=0.0;
	ytn=5.0;
	printf("%lf %lf %lf \n", tn, xtn, ytn);
	Vxn=Vn*cos(a);
	Vyn=Vn*sin(a);
	while (tn<=T)
	{
		xtn=xtn+Vxn*dt;
		ytn=ytn+Vyn*dt;
		Vyn=Vyn-dt*g;
		tn+=dt;
		printf ("%lf %lf %lf \n", tn, xtn, ytn);
		
	}
}