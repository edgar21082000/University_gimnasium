#include <stdio.h>
#include <stdlib.h>

int main(){
	int i;
	
	char db[2];
	int tech[4];
	FILE *A; A=fopen("In_bin.txt","rb");
	
	fread(db, sizeof(char), 2, A);
	fread(tech, sizeof(int), 4, A);
	
	int *type; type=(int *)malloc(2*tech[0]*sizeof(int));
	fread(type, sizeof(int), 2*tech[0], A);
	
	char **name;
	name=(char **)malloc(tech[0]*sizeof(char *));
	for(i=0;i<tech[0];i++) name[i]=(char *)malloc(tech[2]*sizeof(char));
	for(i=0;i<tech[0];i++) fread(name[i], sizeof(char), tech[2], A);
	
	//--------------------------------------------------------------
	printf("Кол-во столбцов - %d\nКол-во строк - %d\nРазмер названия столбца - %d\nАдрес начала БД - %d\n\n", tech[0], tech[1], tech[2], tech[3]);
	printf("Типы столбцов: ");
	for(i=0;i<tech[0];i++){
		if(type[i]==0) printf("char ");
		if(type[i]==1) printf("int ");
		if(type[i]==2) printf("double ");
	}
	printf("\n");
	printf("Названия столбцов: ");
	for(i=0;i<tech[0];i++) printf("%s ", name[i]);
	
	return 0;
}
