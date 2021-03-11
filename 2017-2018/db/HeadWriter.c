#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	FILE *A; A=fopen("In_file.txt","r");
	FILE *B; B=fopen("In_bin.txt", "wb");
	
	char db[2]; db[0]='d'; db[1]='b';
	fwrite(db, sizeof(char), 2, B);
	
	int tech[4];
	for(i=0;i<4;i++) fscanf(A, "%d", &tech[i]);
	fwrite(tech, sizeof(int), 4, B); 
	
	int *type; type=(int *)malloc(2*tech[0]*sizeof(int));
	for(i=0;i<2*tech[0];i++) fscanf(A, "%d", &type[i]);
	fwrite(type, sizeof(int), 2*tech[0], B);
	
	char *name; name=(char *)malloc(tech[2]*sizeof(char));
	for(i=0;i<tech[0];i++){
		fscanf(A, "%s", name);
		fwrite(name, sizeof(char), tech[2], B);
	}
	
	return 0;
}