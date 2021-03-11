#include <stdio.h>

int main(){
	unsigned char kol;
	unsigned char buf[128];
	FILE *B; B=fopen("cod.txt", "r");
	FILE *C; C=fopen("decod.txt", "w");
	unsigned char i; unsigned char j=0;
	while(fscanf(B, "%c", &kol)==1){
		printf("%d ", kol);
		if(kol<128) {
			fscanf(B, "%c", &buf[j]);
			for(i=0;i<kol;i++ )fprintf(C, "%c", buf[j]);
		}
		if(kol>128){
			for(j=0;j<kol-128;j++) fscanf(B, "%c", &buf[j]); printf("%c\n", buf[j]);
			for(j=0;j<kol-128;j++)fprintf(C, "%c", buf[j]);
		}
	}
	fclose (B); fclose(C);
	return 0;
}
