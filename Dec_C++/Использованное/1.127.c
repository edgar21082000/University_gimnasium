#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n; scanf("%d", &n);
	int *mas; mas=(int *)malloc(n*sizeof(int));
	
	
	int i, j; 
	int l = 0;
	while(scanf("%d", &mas[l])==1 && l<n) l++;
	
	int sum1 = 0;
	int sum2 = 0;
	
	//for(i=0;i<l;i++) printf("%d", mas[i]); printf("\n");
	
	for(i=0;i<l;i++){
		for(j=0;j<=i;j++) sum1+=mas[j];
		for(j=i+1;j<l;j++) sum2+=mas[j];
		
		//printf("%d) %d - %d\n", i, sum1, sum2);
		
		if(sum1 == sum2){
			printf("0");
			return 0;
		}
		else{
			sum1 = 0;
			sum2 = 0;
		}
	}
	
	printf("-1");
	return -1;
}

