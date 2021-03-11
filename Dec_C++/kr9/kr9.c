#include <stdio.h>

/* Кодировка
00 - 0
01 - 1
10 - 2
11 -3
*/

unsigned char bit(unsigned char let, unsigned char kol);

int main(){
	unsigned char let, tmp, bin; unsigned char kol=1;
	
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("cod.txt", "w");
	
	fscanf(A, "%c", &let);
	
	while(fscanf(A, "%c", &tmp)==1){
		if(tmp==let) {
			kol++;
			let=tmp;		
		}
		else{
			bin=bit(let, kol);
			fprintf(B, "%c", bin); printf("++%d++\n", bin);
			let=tmp;
			kol=1;
		}
	}
	fprintf(B, "%c", bit(let, kol));
	
	return 0;
}

unsigned char bit(unsigned char let, unsigned char kol){
	unsigned char bit;
	if(let=='0') bit=0;
	if(let=='1') bit=64;
	if(let=='2') bit=128;
	if(let=='3') bit=192;
	
	//kol<=32
	
	bit=bit+kol;
	printf("--%d--\n", bit);
	return bit;
}
