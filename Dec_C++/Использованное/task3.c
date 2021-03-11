#include <stdio.h>

int main(){
	int x, y;
	int otr = 0;
	int pol = 0;
	
	while(scanf("%d %d", &x, &y)==2){
		if(y>0) pol++;
		if(y<0) otr++;
	}
	printf("%d", otr*pol);
}
