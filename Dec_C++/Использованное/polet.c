#include <stdio.h>
#include <stdlib.h>

int main(){
	double x = 5.0;
	double y = 2.0;
	double vx = 40.0;
	double vy = 50.0;
	double tau = 0.01;
	int i; FILE *fp; fp=fopen("out.txt", "w");
	for(i=0;i<1000;i++){
		x=x+vx*tau;
		y=y+vy*tau;
		vx=vx-4.0*tau;
		vy=vy-9.81*tau;
		fprintf(fp, "%lf %lf\n", x, y);
	}
	
	return 0;
	
}

