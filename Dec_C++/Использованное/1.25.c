#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int a);

int main(){
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	int n;
	fscanf(A, "%d", &n);
	
	
	int i, key;
	for(i=1;i<(int)sqrt(n) + 1; i++){
		printf("%d\n", i);
		
		key = prime(i);
		if(key == 1){
			if (n%i == 0) fprintf(B, "%d ", i);
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
