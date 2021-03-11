#include <stdio.h>
#include <stdlib.h>

int st(int x, int a);
unsigned char decod(unsigned char a);

int main(){
	FILE* A; A=fopen("bag.txt", "r");
	FILE* B; B=fopen("decod.txt", "w");
	int i, j;
	
	unsigned char* buf; buf=(unsigned char *)malloc(128*sizeof(unsigned char));
	for(i=0;i<128;i++) buf[i]=0;
	
	i=0;
	while(fscanf(A, "%c", &buf[i])==1) i++;
	
	
	i=0;
	unsigned char x;
	while(buf[i]!=0){
		printf("|||||||||||||||||||||||%c-%d||||||||||||||||||||||||\n", buf[i], buf[i]);
		x=decod(buf[i]);
		fprintf(B, "%c", x);
		i++;
	}
	
	fclose(A); fclose(B);
	
	return 777;
}

unsigned char decod(unsigned char a){
	int sum, i, j;
	unsigned char res = a;
	int bit[8];
	for(i=0;i<8;i++){
		if(st(2, 7-i)>a) bit[i]=0;
		else{
			bit[i]=1;
			a=a-st(2, 7-i);
		}
	}
															printf("----------------------------------%c(%d)\n", res, res);
	
	sum=0; for(j=1;j<8;j++) sum+=bit[j];					for(i=0;i<8;i++) printf("[%d]", bit[i]); printf("sum = %d\n", sum);
	if(sum%2 != bit[0]%2) {res='*'; return res;}
	else{
		if(bit[0]==1) res-=128;
	}
	
															printf("+++++++++++++++++++++++++++++++++++%c(%d)\n\n", res, res);
	return res;
}

int st(int x, int a){
	int i, res;
	res=x;
	
	if(a==0) return 1;
	for(i=1;i<a;i++) res=res*x;
	return res;
}
