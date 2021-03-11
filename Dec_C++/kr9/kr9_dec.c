#include <stdio.h>

/* Кодировка
00 - 0
01 - 1
10 - 2
11 -3
*/

unsigned char bit_let(unsigned char bit);
unsigned char bit_kol(unsigned char bit, unsigned char let);


int main(){
	unsigned char bit;
	unsigned char let, kol;
	unsigned char i=0;
	
	FILE *A; A=fopen("cod.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	while(fscanf(A, "%c", &bit)==1){
		let=bit_let(bit);
		kol=bit_kol(bit, let);
		for(i=0;i<kol;i++) fprintf(B, "%c", let);
	}
	
	fclose(A), fclose(B);
	return 0;
}


unsigned char bit_let(unsigned char bit){
	unsigned char let;
	if(bit<64) let='0';
	if(bit>64 && bit<96) let='1';
	if(bit>128 && bit<160) let='2';
	if(bit>192) let='3';
	
	return let;
}

unsigned char bit_kol(unsigned char bit, unsigned char let){
	unsigned char tmp, kol;
	if(let=='0') tmp=0;
	if(let=='1') tmp=64;
	if(let=='2') tmp=128;
	if(let=='3') tmp=192;
	
	kol=bit-tmp;
	return kol;
}
