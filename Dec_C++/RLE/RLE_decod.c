#include <stdio.h>

int main(){
	unsigned char kol, let;
	FILE *B; B=fopen("cod.txt", "r");
	FILE *C; C=fopen("decod.txt", "w");
	unsigned char i;
	while(fscanf(B, "%c%c", &kol, &let )==2){
		printf("%c", let);
		for(i=0;i<kol; i++) fprintf(C, "%c", let);
	}
	fclose (B); fclose(C);
	return 0;
}
