#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *A0; A0=fopen("out.txt", "r");
	FILE *B; B=fopen("cod.txt", "w");
	
	int i, j, kol;
	
	char* buf; buf=(char *)malloc(128*sizeof(char));
	char** bin; bin=(char **)malloc(128*sizeof(char *));
	for(i=0;i<128;i++) bin[i]=(char *)malloc(32*sizeof(char));
	
	i=0; kol=0;
	
	while(fscanf(A0, "%s", &buf[i])==1){
		fscanf(A0, "%s", bin[i]);
		i++;
		kol++;
	}
	fclose(A0); //for(i=0;i<kol;i++) fprintf(B, "%c %s\n", buf[i], bin[i]); //Проверка считывания

	FILE *A; A=fopen("in.txt", "r");
	char let;
	while(fscanf(A, "%c", &let)==1) for(i=0;i<kol;i++) if(let==buf[i]) fprintf(B, "%s", bin[i]);
	
	return 0;
}
