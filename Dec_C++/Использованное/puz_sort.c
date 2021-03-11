#include <stdio.h>
#include <stdlib.h>

int main(){
	int *a;
	a=(int *)malloc(1000*sizeof(int));
	int k = 0;
	while(scanf("%d", &a[k])==1) k++;
	int tmp, i, j;
	
	
	/*for(i=0;i<k-1;i++){
		for(j=0;j<k-1-i;j++){
			if(a[j]>a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
			}
		}
	}*/
	int len = k;
	int flag = 1;
	while(flag == 1){
		flag = 0;
		k--;
		for(j=0;j<k;j++){
			if(a[j]>a[j+1]){
				tmp = a[j+1];
				a[j+1] = a[j];
				a[j] = tmp;
				flag = 1;
			}
		}
	}
	
	for(i=0;i<len;i++) printf("%d ", a[i]);
	return 0;
}
