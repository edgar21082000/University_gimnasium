#include <stdio.h>
#include <stdlib.h>

int main(){
	char a[20], b[20];
	int c,d, i;
	int n, cost92=3001, cost95=3001, cost98=3001, n92=0, n95=0, n98=0;
	scanf("%d", &n);
	for( i=0;i<n;i++){
		scanf("%s%s%d%d", a,b,&c,&d);
		if(c==92){
		
			if(cost92>d){
				n92=0;
				cost92=d;
			}
			if(cost92==d){
				n92+=1;
			}
		}
		
		if(c==95){
			if(cost95>d){
				n95=0;
				cost95=d;
			}
			if(cost95==d){
				n95+=1;
			}
		}
		
		if(c==98){
			if(cost98>d){
				n98=0;
				cost98=d;
			}
			if(cost98==d){
				n98+=1;
			}
		}
	}
	printf("%d %d %d", n92, n95, n98);
	return 0;
}
