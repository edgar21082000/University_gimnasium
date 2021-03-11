#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){
	int mas[10][20];
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	int i, j;
	int sum_max, sum_tmp, index;
	sum_max = 0; sum_tmp = 0; index = 0;
	
	A = stdin;
	B = stdout;
	
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			fscanf(A, "%d", &mas[i][j]);
		}
	}
	
	for(j=0;j<20;j++) sum_max += mas[0][j];
	
	for(i=1;i<10;i++){
		for(j=0;j<20;j++){
			sum_tmp += mas[i][j];
		}
		
		printf("%d\n", sum_tmp);
		
		if(sum_tmp>sum_max){
			index = i;
			sum_max = sum_tmp;
		}
		
		sum_tmp = 0;
	}
	printf("\n%d", index);
	
	if(index == 0){
		for(i=0;i<10;i++){
			for(j=0;j<20;j++){
				fprintf(B, "%d ", mas[i][j]);
			}
			fprintf(B, "\n");
		}
	}
	else{
		int tmp;
		for(j=0;j<20;j++){
			tmp = mas[0][j];
			mas[0][j] = mas[index][j];
			mas[index][j] = tmp;
		}
			
		for(i=0;i<10;i++){
			for(j=0;j<20;j++){
				fprintf(B, "%d ", mas[i][j]);
			}
			fprintf(B, "\n");
		}
		
	}
	
	return 0;
	
}
