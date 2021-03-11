#include <stdio.h>

int main(){
	int n; scanf("%d", &n);
	int last, tmp, len, kol;
	scanf("%d", &last);
	len = 1; kol = 0;
	
	while(scanf("%d", &tmp)==1){
		if(tmp <= last){
			len++;
			if(len==n) kol++;
			last = tmp; 
		} 
		else{
			last = tmp;
			len = 1;
		}
	}
	
	printf("%d", kol);
	
}
