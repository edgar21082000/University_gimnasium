#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int a);

int main(){
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	int n;
	fscanf(A, "%d", &n);
	if(prime(n)==1) fprintf(B, "%d", n);
	
	int i, key, st;
	
	st = n;
	
	

	
	for(i=2;i<(st/2 + 1); i++){
		key = prime(i);
		
		if(key == 1){
			while (n%i==0){
				fprintf(B, "%d*", i);
				n/=i;
			}
		}
		
	}
	
	return 0;
}

int prime(int a){
	int d=2;
	while (d<(int)sqrt(a) + 1){
		if (a%d == 0) return 0;
		d++;
	}
	return 1;
}
