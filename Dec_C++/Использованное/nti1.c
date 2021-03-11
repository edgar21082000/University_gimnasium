#include <stdio.h>

int main(){
	int a[4];
	int max=0; int sum=0;
	int j, i;
	
	for(i=0;i<4;i++){
		scanf("%d", &a[i]);
		if(a[i]>=max){
			max=a[i];
			j=i;
		}
	}
	
	for(i=0;i<4;i++){
		if(i==j) continue;
		sum+=a[i];
	}
	
	if(sum>max) printf("Yes");
	else printf("No");
	return 0;
}
