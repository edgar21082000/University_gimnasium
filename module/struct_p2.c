#include <stdio.h>
#include <math.h>

int N=10;

struct p2{
		double x; 
		double y;
		};

void p2_prn(struct p2 X);
void prn(void);

void p2_prn(struct p2 B)
{
	printf("(%25.12lf %25.12lf)\n", B.x, B.y);

	return ;
}
void prn(void)
{
	extern int N;
	printf ("%d", N);
}

int main (void)
{
	struct p2 A, B;
	A.x=sqrt(3.);
	scanf("%lf",&A.y);
	B=A;
	p2_prn(B);
	prn();
	
	
		
	return 0;
}