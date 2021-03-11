#include <stdio.h>
#include <stdlib.h>

int main(){
	int size;
	scanf("%d", &size);
	
	int *mas; mas=(int *)malloc(size*sizeof(int));
	int i, j;
	int k=0;
	while(scanf("%d", &mas[k])==1 && k<size) k++;
	
	
	for(i=0;i<k;i++){
		if(mas[i]<0){
			for(j=i;j<k-1;j++){
				mas[j]=mas[j+1];
			}
			i--;
			k--;
		}
	}
	
	for(j=0;j<k;j++) printf("%d ", mas[j]);
}
