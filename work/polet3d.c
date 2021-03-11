#include <stdio.h>
#include <math.h>

int main()
{
	const double g = 9.8;
	double x0, y0, z0, v, Vx, Vy, Vz, a1, a2, t, dt, T;
	int i, k=0;
	t=0.;
	scanf("%lf", &x0);
	scanf("%lf", &y0);
	scanf("%lf", &z0);
	scanf("%lf", &v);
	scanf("%lf", &a1);
	scanf("%lf", &a2);
	scanf("%lf", &dt);
	scanf("%lf", &T);
	printf("%d) t = %lf  x = %lf  y = %lf  z = %lf\n", k, t, x0, y0, z0);
	Vx=v*cos(a1)*cos(a2);
	Vy=v*sin(a1);
	Vz=v*cos(a1)*sin(a2);
	while (t<T)
	{
		k+=1;
		t+=dt;
		x0=x0+Vx*dt;
		y0=y0+Vy*dt-(g*dt*dt)/2;
		z0=z0+Vz*dt;
		Vy=Vy-g*dt;
		printf("%d) t = %lf  x = %lf  y = %lf   z = %lf\n", k, t, x0, y0, z0); 
	}
}