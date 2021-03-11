#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char x[4];
	unsigned char mask=255;
	int res[4]; 
	int tmp[4]; int i, k; int co=128;
	for(i=0;i<4;i++) res[i]=0;
	
    scanf("%d.%d.%d.%d/%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3], &k);
	for(i=0;i<4;i++) x[i]=(unsigned char)tmp[i];
	
	if(k<=8){
		mask=0; for(i=1;i<=k;i++) mask=mask+(unsigned char)(co/i); printf("%d", mask);
		res[0]=(int)(x[0]&mask);
	}
	
	if(k>8 && k<=16){
		mask=255;
		res[0]=(int)(x[0]&mask);
		mask=0; for(i=1;i<=(k%8);i++) mask=mask+(unsigned char)(co/i);
		res[1]=(int)(x[1]&mask);
	}
	
	if(k>16 && k<=24){
		mask=255;
		res[0]=(int)(x[0]&mask);
		res[1]=(int)(x[1]&mask);
		mask=0; for(i=1;i<=(k%8);i++) mask=mask+(unsigned char)(co/i);
		res[2]=(int)(x[2]&mask);
	}
	
	if(k>24 && k<=32){
		mask=255;
		res[0]=(int)(x[0]&mask);
		res[1]=(int)(x[1]&mask);
		res[2]=(int)(x[2]&mask);
		mask=0; for(i=1;i<=(k%8);i++) mask=mask+(unsigned char)(co/i);
		res[3]=(int)(x[3]&mask);
	}
	
	for(i=0;i<4;i++) printf("%d.", res[i]);
	
	return 0;
}