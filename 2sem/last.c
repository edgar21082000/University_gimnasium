#include <stdio.h>
#include <stdlib.h>

int main(){
	unsigned char x[4];
	unsigned char mask[4];
	int res[4];
	int tmp[4]; int i;
	
    scanf("%d.%d.%d.%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
	for(i=0;i<4;i++) x[i]=(unsigned char)tmp[i];
	
	scanf("%d.%d.%d.%d", &tmp[0], &tmp[1], &tmp[2], &tmp[3]);
	for(i=0;i<4;i++) mask[i]=(unsigned char)tmp[i];
	
	for(i=0;i<4;i++) res[i]=(int)(x[i]&mask[i]);
	for(i=0;i<4;i++) printf("%d.", res[i]);
	
	return 0;
}