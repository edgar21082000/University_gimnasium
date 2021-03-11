#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(){
	int n; 
	scanf("%d", &n);
	
	int *a; a=(int *)malloc(n*sizeof(int));
	int i; int res=0;
	for(i=0;i<n;i++) scanf("%d", &a[i]);
	for(i=0;i<n;i++) res+=a[i];
	
	
	
	if(abs(res)%n!=0) printf("-1");
	else printf("%d", abs(res)/n);
	return 0;
}
