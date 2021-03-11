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
	
	
	char let[w_len]; char tmp[w_len]; unsigned char kol=1; unsigned num;
	FILE* B; B=fopen("in2.txt", "r");
	FILE* C; C=fopen("cod.txt", "w");
	
	for(i=0;i<w_len;i++) fscanf(B, "%c", &let[i]);
	for(j=0;j<w_num;j++) if(strcmp(let, mas[j])==0) num=j;
	
	while(fscanf(B, "%c", &tmp[0])==1){
		for(i=1;i<w_len;i++) fscanf(B, "%c", &tmp[i]);
		if(strcmp(let, tmp)==0){
			kol++;
			if(kol==256){
				fprintf(C, "%c%c", kol-1, num);
				kol=1;
			}
		}
		else{
			//printf("%d_%d(%s)\n", kol, num, let);
			fprintf(C, "%c%c", kol, num);
			kol=1;
			for(j=0;j<w_num;j++) if(strcmp(tmp, mas[j])==0) num=j;
			strcpy(let, tmp);
		}
	}
	//printf("%d_%d(%s)", kol, num, let);
	fprintf(C, "%c%c", kol, num);
	
	fclose(A); fclose(B); fclose(C);
	
	return 0;
}
