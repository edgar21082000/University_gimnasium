#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int mas[10][20];
	int i, j;
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			mas[i][j] = rand()%100;
		}
	}
	
	FILE *A; A= fopen("in.txt", "w");
	for(i=0;i<10;i++){
		for(j=0;j<20;j++){
			fprintf(A, "%d ", mas[i][j]);
		}
		fprintf(A, "\n");
	}
	
}
