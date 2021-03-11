#include <stdio.h>

double st(int, int);

int main(){
	int N, k;
	scanf("%d %d", &N, &k);
	
	int i, j;
	
	for(i=2;i<10;i++){
		for(j=2;j<30;j++){
			if(st(2, j)==st(N, i)) return j/i;
			if(st(2, j)<st(N, i) && st(N, i)<st(2, j+1)){
				printf("%d<=%d<%d\n", (int)st(2, j), (int)st(N, i), (int)st(2, j+1) );
				break;
			}
		}
		printf("++++%d++++%d\n", (int)(j*st(10,k)/i), (int)((j+1)*st(10,k)/i));
		if( (int)(j*st(10, k)/i) == (int)((j+1)*st(10, k)/i) ) {
			printf("-----%d\n", (int)(j*st(10,k)/i));
			break;	
		}
	}
	
	
	return 0;
}

double st(int a, int k){
	int i, res; res=a;
	for (i=2;i<=k;i++) res=res*a;
	return (double)res;
}


