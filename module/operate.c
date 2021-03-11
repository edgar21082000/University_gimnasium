#include <stdio.h>
#include <stdlib.h>

unsigned int N=1000;
unsigned int M=4;

int hash(unsigned int*, unsigned int a);
int hash_sravn(int, int);

int main(){
	unsigned int *mas;
	/*while(1){
		mas=(char *)malloc(N*sizeof(char));
		if (mas==NULL) break;
		N=N*1.5;
		free(mas);
	}*/
	int i;
	mas=(unsigned int *)malloc(N*sizeof(unsigned int));
	if (mas==NULL) {
		printf("1");
		return 0;
	}
	

	
	for(i=0;i<N;i++) mas[i]=(rand())%256;
	printf("yes");
	
	unsigned int *buf;
	buf=(unsigned int *)malloc(M*sizeof(unsigned int));
	for(i=0;i<M;i++) buf[i]=(rand())%256;
	
	int key=hash(buf, M); 
	int tmp=hash(mas, N);  
	
	int d=hash_sravn(key, tmp);
	if (d==1){
		for(i=0;i<M;i++){
			printf("%d ", mas[i]);
		}
		printf("\n");
	}
	
	for(i=0;i<N-6;i++){
		tmp=tmp-mas[i]+mas[i+6];
		d=hash_sravn(key, tmp);
		if (d==1){
			for(i=0;i<M;i++){
				printf("%d ", mas[i]);
			}
			printf("\n");
		}
	}
	
	return 0;
}


int hash(unsigned int *cur,unsigned int a){
	int k=0;int i;
	for(i=0;i<a;i++) k+=(int)cur[i];
	return k;
}

int hash_sravn(int a, int b){
	if (a==b){
		return 1;
	}
	else return 0;
}