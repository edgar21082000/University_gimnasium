#include <stdio.h>
#include <stdio.h>

int main(){
	double k[10000]; double s[10000];
	k[0]=100;
	s[0]=20;
	int i, j; j=1;
	
	double tau = 0.01;
	for(i=1;i<10000;i++){
		
		k[i]=tau*10*k[i-1]-tau*0.002*k[i-1]*s[i-1]+k[i-1];
		s[i]=-tau*0.3*s[i-1]+tau*0.001*k[i-1]*s[i-1]+s[i-1];
		
		j++;
		if(k[i]<=0 || s[i]<=0) break;
	}
	
	FILE *A; A=fopen("fish_out.txt", "w");
	for(i=0;i<j;i++){
		fprintf(A, "%d %lf %lf\n", i, s[i], k[i]);
	}
	
	return 0;
}
