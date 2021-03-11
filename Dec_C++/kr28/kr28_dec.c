#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	FILE* A;  A=fopen("in1.txt", "r");
	
	int i, j;
	
	int w_num, w_len;
	fscanf(A, "%d", &w_num);
	fscanf(A, "%d", &w_len);
	
	char** mas; mas=(char **)malloc(w_num*sizeof(char *));
	for(i=0;i<w_num;i++) mas[i]=(char *)malloc(w_len*sizeof(char));
	for(i=0;i<w_num;i++) fscanf(A, "%s", mas[i]);
	
	FILE* B; B=fopen("cod.txt", "r");
	FILE* C; C=fopen("decod.txt", "w");
	
	unsigned char kol, let;
	
	while(fscanf(B, "%c", &kol)==1){
		fscanf(B, "%c", &let);
		for(i=0;i<kol;i++) fprintf(C, "%s", mas[let]);
	}
	
	fclose(A); fclose(B); fclose(C);
	
	return 0;	
}
