#include <stdio.h>
#include <math.h>

int main(){
	int constant; scanf("%d", &constant);
	
	int a, b;
	scanf("%d %d", &a, &b);
	
	if(abs(a-b)%2==1) printf("-1");
	else printf("%d", abs(a-b)/2);
	return 0;
}
