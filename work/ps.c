#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const double g=9.81;


int main(void)
{
	int board1, board2, board_x, i;
	double x, xb, y, yb, V, Vx, Vy, D, a, t, t1, T, dt, tmp;
	double tk;
	scanf("%d%d%d", &board1, &board2, &board_x);
	scanf("%lf%lf", &x, &y);
	scanf("%lf%lf", &Vx, &Vy);
	a=atan(Vy/Vx);               // угол полета в данный момент //
	
	
	t=0.0;
	t1=0.001;
	dt=0.001;
	
	while(x<=((board_x) - (Vx*dt)))
	{
		x=Vx*t;
		y=Vy*t-g*t*t/2; 
		if (y<0)
		{
			printf("\n%25.12Недолет щита, упал на землю");
			exit (1);
		}
		printf("%25.12lf%25.12lf%25.12lf\n", t, x, y);
		t+=dt;
	}
	tk=(board_x-x)/Vx;
	t+=tk;
	x=x+Vx*tk;
	y=y+Vy*tk-g*tk*tk/2;
	printf("%25.12lf%25.12lf%25.12lf\n", t, x, y);
	if (y>board1)
		{
			printf("\n%25.12Перелет щита");
			exit(1);
		}
	if (y<board2)
		{
			printf("\n%25.12Недолет щита");
			exit (1);
		}
	
	
	
	/*printf("\n%25.12Удар о щит\n\n");*/
	
	Vx=-1.0*Vx;
	Vy=Vy-g*t;
	
	
	while(y+(Vy*t1-g*t1*t1/2)>=0)
	{
		xb=Vx*t1;
		yb=Vy*t1-g*t1*t1/2; 		
		printf("%25.12lf%25.12lf%25.12lf\n", t+t1, x+xb, y+yb);
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
	printf("%25.12lf%25.12lf%25.12lf\n", T+tk, x+xb, y+yb);
	
	return 0;
}