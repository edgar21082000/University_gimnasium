#include <stdio.h>
#include <math.h>

int main()
{
	const double EPS = 0.25;
	const double g = 9.81;
	const double Pi = 4.*atan(1.);
	double x0, y0, z0, v0, Vx0, Vy0, Vz0, a01, a02, t, dt, T;                         double x1, y1, z1, v1, Vx1, Vy1, Vz1, a11, a12;      
    double u01, u02, u11, u12, k01, k02, k11, k12;
	

    int i, n=0;
	t=0.;
	
	
	scanf("%lf", &x0);                                                                scanf("%lf", &x1);
	scanf("%lf", &y0);                                                                scanf("%lf", &y1);
	scanf("%lf", &z0);                                                                scanf("%lf", &z1);
	scanf("%lf", &v0);                                                                scanf("%lf", &v1);
	scanf("%lf", &u01);                                                               scanf("%lf", &u11);
	scanf("%lf", &u02);                                                               scanf("%lf", &u12);
	k01=180./u01;                                                                     k11=180./u11;
	k02=180./u02;                                                                     k12=180./u12;
	a01=Pi/k01;                                                                        a11=Pi/k11 ;
    a02=Pi/k02;                                                                        a12=Pi/k12;

	scanf("%lf", &dt);
	scanf("%lf", &T);
	
	printf("%d) t = %lf  x = %lf  y = %lf  z = %lf  x1 = %lf  y1 = %lf  z1 = %lf\n", n, t, x0, y0, z0, x1, y1, z1);
	
	Vx0=v0*cos(a01)*cos(a02);                                                         Vx1=v1*cos(a11)*cos(a12);
	Vy0=v0*sin(a01);                                                                  Vy1=v1*sin(a11);
	Vz0=v0*cos(a01)*sin(a02);                                                         Vz1=v1*cos(a11)*sin(a12);
	while (t<T)
	{
		n+=1;
		t+=dt;
		x0=x0+Vx0*dt;                                                                 x1=x1+Vx1*dt;
		y0=y0+Vy0*dt-(g*dt*dt)/2;                                                     y1=y1+Vy1*dt-(g*dt*dt)/2;
		z0=z0+Vz0*dt;                                                                 z1=z1+Vz1*dt;
		Vy0=Vy0-g*dt;                                                                 Vy1=Vy1-g*dt;
		
		if (fabs(x0-x1)<EPS && fabs(y0-y1)<EPS && fabs(z0-z1)<EPS){
			printf("%d) t = %lf  x = %lf  y = %lf  z = %lf  x1 = %lf  y1 = %lf  z1 = %lf\n", n, t, x0, y0, z0, x1, y1, z1);
			break;
		}
		
		printf("%d) t = %lf  x = %lf  y = %lf  z = %lf  x1 = %lf  y1 = %lf  z1 = %lf\n", n, t, x0, y0, z0, x1, y1, z1);
	}
}