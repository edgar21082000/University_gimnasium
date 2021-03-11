#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	int m, n, k, max, sum, tmp;
	fscanf(A, "%d %d %d", &m, &n, &max);
	
	k=1; sum=0;
	tmp = sum;
	if (m>max) fprintf(B, "0");
	else tmp+=m;
	
	while(tmp<max){
		sum=tmp;
		tmp+=(m+k*n);
		k++;
	}
	
	fprintf(B, "%d", sum);
	
	printf("%lf", sqrt(26));
	
	return sum;
}
