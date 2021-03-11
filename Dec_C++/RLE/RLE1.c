#include <stdio.h>

int main(){
	unsigned char kol=1;
	unsigned char let, tmp;
	
	int i;
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("cod.txt", "w");
	
	fscanf(A, "%c", &let);
	
	while(fscanf(A, "%c", &tmp)==1){
		if(tmp==let) {
			kol++;
			let=tmp;
			if(kol==10){
				fprintf(B, "%d%c", kol-1, let);
				kol=1;
			}		
		}
		else{
			fprintf(B, "%d%c", kol, let );
			let=tmp;
			kol=1;
		}
	}
	
	fprintf(B, "%d%c", kol, let);
	
	
	fclose(A); fclose(B);
	
	
	return 0;
}
