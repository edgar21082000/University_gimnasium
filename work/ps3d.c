#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double g=9.81;

int main(void)
{
	int board_1x, board_1y, board_1z, i;
	int board_2x, board_2y, board_2z;
	double x, xb, y, yb, z, zb, V, Vx, Vy, Vz, D, a, t, t1, T, dt, tmp;
	double tk;
	scanf("%d%d%d", &board_1x, &board_1y, &board_1z); // верхняя //
	scanf("%d%d", &board_2y, &board_2z); // нижняя //
	scanf("%lf%lf%lf", &x, &y, &z);
	scanf("%lf%lf%lf", &Vx, &Vy, &Vz);
	board_2x=board_1x;
	
	t=0.0;
	t1=0.001;
	dt=0.001;
	
	
	while(x<((board_1x) - (Vx*dt)))
	{
		x=Vx*t;
		y=Vy*t-g*t*t/2; 
		z=Vz*t;
		if (y<0)
		{
			printf("\n%25.12Недолет щита, упал на землю");
			exit (1);
		}
		printf("%10.10lf %10.10lf %10.10lf   %10.10lf\n", t, x, y, z);
		t+=dt;
	}
	tk=(board_1x-x)/Vx;
	t+=tk;
	x=x+Vx*tk;
	y=y+Vy*tk-g*tk*tk/2;
	z=z+Vz*tk;
	printf("%10.10lf %10.10lf %10.10lf   %10.10lf\n", t, x, y, z);
	
	if (y>board_1y)
	{
		printf("\n%25.12Перелет щита");
		exit(1);
	}
	if (y<board_2y)
	{
		printf("\n%25.12Недолет щита");
		exit (1);
	}
	
	
	
	if (board_1z>board_2z)
	{
		if (z>board_1z)
		{
			printf("\n%25.12Перелет щита, слева");
			exit(1);
		}
		if (y<board_2z)
		{
			printf("\n%25.12Недолет щита, справа");
			exit (1);
		}
	}
	else
	{
		if (z>board_2z)
		{
			printf("\n%25.12Перелет щита, слева");
			exit(1);
		}
		if (z<board_1z)
		{
			printf("\n%25.12Недолет щита, справа");
			exit (1);
		}
	}
	
	/*printf("\n%25.12Удар о щит\n\n");*/
	
	Vx=-1.0*Vx;
	Vy=Vy-g*t;
	
	
	while(y+(Vy*t1-g*t1*t1/2)>0)
	{
		xb=Vx*t1;
		yb=Vy*t1-g*t1*t1/2; 
		zb=Vz*t1;
		printf("%10.10lf %10.10lf %10.10lf   %10.10lf\n", t+t1, x+xb, y+yb, z+zb);
		t1+=dt;
	}
	if (y+yb<0)
	{
		printf("\nERROR ниже земли");
		exit(1);
	}
	
	T=t+t1;
	Vy=-(Vy-g*t1); 
    D=4*Vy*Vy+8*g*(y+yb);
	D=sqrt(D);
	tk=(D-2*Vy)/(2*g);
	xb=xb+Vx*tk;
	yb=yb-(Vy*tk+g*tk*tk/2);
	zb=zb+Vz*tk;
	printf("%10.10lf %10.10lf %10.10lf   %10.10lf\n", T+tk, x+xb, y+yb, z+zb);
	
	
	return 0;
}