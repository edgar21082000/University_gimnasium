#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n; scanf("%d", &n);
	int *mas; mas=(int *)malloc(n*sizeof(int));
	
	int i, j, k; 
	int l = 0;
	while(scanf("%d", &mas[l])==1 && l<n) l++;
	
	int *new_mas; new_mas=(int *)malloc(l*sizeof(int));
	k=0;
	for(i=0;i<=(l-1)/2;i++){
		new_mas[k] = mas[2*i];
		k++;
	}
	
	for(j=0;j<=(l-1)/2;j++){
		new_mas[k] = mas[2*j+1];
		k++; 
	}
	free(mas);
	
	
	for(k=0;k<l;k++) printf("%d ", new_mas[k]);
	return 0;
}
