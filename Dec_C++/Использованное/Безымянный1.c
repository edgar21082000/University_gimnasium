#include <stdio.h>
#include <stdlib.h>

unsigned char key = 53;

int main(){
	FILE *A; A=fopen("in.txt", "r");
	FILE *B1; B1=fopen("cod.txt", "w");
	
	
	unsigned char l;
	
	while(fscanf(A, "%c", &l)==1) fprintf(B1, "%c", l^key);
	fclose(A); fclose(B1);
	
	
	FILE *B2; B2=fopen("cod.txt", "r");
	FILE *C; C=fopen("decod.txt", "w");
	
	while(fscanf(B2, "%c", &l)==1) fprintf(C, "%c", l^key);
	fclose(B2); fclose(C);
	
	return 0;
}
