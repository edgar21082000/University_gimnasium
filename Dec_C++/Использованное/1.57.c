#include <stdio.h>
#include <stdlib.h>

int main(){
	int n;
	int kol = 0;
	int last;
	
	while(scanf("%d", &n)==1){
		if(n%3 == n%5){
			kol++;
			last = n;
		}
	}
	
	printf("kol = %d\nlast = %d", kol, last);
	return 0;
}
