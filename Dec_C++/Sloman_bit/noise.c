#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int st(int x, int a);
unsigned char cod(unsigned char a);
unsigned char chet(unsigned char a);

int main(){
	FILE* A; A=fopen("potok.txt", "r");
	FILE* B; B=fopen("bag.txt", "w");
	int i, j;
	
	unsigned char* buf; buf=(unsigned char *)malloc(128*sizeof(unsigned char));
	for(i=0;i<128;i++) buf[i]=0; 
	i=0;
	while(fscanf(A, "%c", &buf[i])==1) i++;
	
	i=0; 
	unsigned char x; int key;
	srand(time(NULL));
	while(buf[i]!=0){
		key=rand()%2;
		if(key==0) {printf("\n\nalahalahalahalahalahalahalahalahalah\n"); x=chet(buf[i]);fprintf(B, "%c", x); i++;}
		else{
			x=cod(buf[i]);
			fprintf(B, "%c", x);
			i++;
		}
	}
	
	fclose(A); fclose(B);
	
	return 777;
}

unsigned char cod(unsigned char a){
	unsigned char res = a;
	int lom, sum, i, j;
	int bit[8];
	for(i=0;i<7;i++){
		if(st(2, 6-i)>a) bit[i+1]=0;
		else{
			bit[i+1]=1;
			a=a-st(2, 6-i);
		}
	}
															printf("----------------------------------%c(%d)\n", res, res);
	
	sum=0; for(j=1;j<8;j++) sum+=bit[j];					printf("sum = %d\n", sum);
	if(sum%2==0) bit[0]=0;
	else {bit[0]=1; res+=128;}
	
	for(i=0;i<8;i++) 										printf("[%d]", bit[i]); printf(" %d \n", res);
	
	lom=rand()%6 + 1;							 			printf("%d\n", lom);
	
	if(bit[7-lom]==1){res-=st(2, lom); bit[7-lom]=0;}
	else{res+=st(2, lom); bit[7-lom]=1;}
	
															for(i=0;i<8;i++) printf("[%d]", bit[i]); printf("\n");
															printf("----------------------------------%c(%d)\n\n", res, res);
	return res;
}

int st(int x, int a){
	int i, res;
	res=x;
	
	if(a==0) return 1;
	for(i=1;i<a;i++) res=res*x;
	return res;
}

unsigned char chet(unsigned char a){
	unsigned char res = a;
	int lom, sum, i, j;
	int bit[8];
	for(i=0;i<7;i++){
		if(st(2, 6-i)>a) bit[i+1]=0;
		else{
			bit[i+1]=1;
			a=a-st(2, 6-i);
		}
	}
															printf("----------------------------------%c(%d)\n", res, res);
	
	sum=0; for(j=1;j<8;j++) sum+=bit[j];					printf("sum = %d\n", sum);
	if(sum%2==0) bit[0]=0;
	else {bit[0]=1; res+=128;}
	
	for(i=0;i<8;i++) 										printf("[%d]", bit[i]); printf(" %d \n", res);
	
	return res;
}
