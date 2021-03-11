#include <stdio.h>
#include <stdlib.h>

#define N 15

int main(){
	int Y[N]; int G[N];
	Y[0]=1; G[0]=1;
	Y[1]=2; G[1]=2;
	
	int i;
	for(i=2;i<=N;i++){
		Y[i]=5*Y[i-1]-6*Y[i-2];
		G[i]=pow(2, i);
	}
	
	FILE *A; A=fopen("kr2_out.txt", "w");
	for(i=0;i<=N;i++) fprintf(A, "%d _ %d _ %d\n", i, Y[i], G[i]);
	
	return 0;
}
