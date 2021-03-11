#include <stdio.h>
#include <stdlib.h>

struct book{
	char name[20];
	char surname[20];
	char tel_num[12];
	char email[64];
};


int main(){
	int i, k;
	struct book *N0; N0=(struct book *)malloc(128*sizeof(struct book)); 
	for(i=0;i<128;i++) (N0[i].tel_num[0])='0';
	FILE *R; FILE *W; FILE *S;
	R=fopen("file.txt","r"); W=fopen("out.txt","wb"); S=fopen("size.txt","w");
	fscanf(R, "%d", &k); fprintf(S, "%d", k);
	for(i=0;i<k;i++) fscanf(R, "%s %s %s %s\n", &(N0[i].name), &(N0[i].surname), &(N0[i].tel_num), &(N0[i].email));
	for(i=0;i<k;i++) printf("%s %s %s %s\n", (N0[i].name), (N0[i].surname), (N0[i].tel_num), (N0[i].email));
	fwrite(N0, sizeof(struct book), k, W);
	free(N0);
	fclose(R); fclose(W); fclose(S);
	
	return 0;
}