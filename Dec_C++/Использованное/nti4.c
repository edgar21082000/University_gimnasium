#include <stdio.h>
#include <math.h>

int main(){
	int a0, a1, a2, b0, b1, b2;
	scanf("%d %d %d", &a0, &a1, &a2);
	scanf("%d %d %d", &b0, &b1, &b2);
	
	int xm, ym, rm, xb, yb, rb;
	
	if(a2>=b2){
		xm=b0; ym=b1; rm=b2;
		xb=a0, yb=a1; rb=a2;
	}
	else{
		xm=a0; ym=a1; rm=a2;
		xb=b0, yb=b1; rb=b2;
	}
	
	int i, j; int kol=0;
	for(i=0;i<=2*rm;i++){
		for(j=0;j<=2*rm;j++){
			
			
			if((((xm-(xm-rm+j))*(xm-(xm-rm+j)) + (ym-(ym+rm-i))*(ym-(ym+rm-i)))<=rm*rm) && (((xb-(xm-rm+j))*(xb-(xm-rm+j)) + (yb-(ym+rm-i))*(yb-(ym+rm-i)))<=rb*rb)){
			 kol++;
			 
			}
		}
	}
	printf("%d", kol);
	
}
