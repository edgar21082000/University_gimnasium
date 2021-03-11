#include <stdio.h>

int main(){
	int kol, p, a, a_pred, key, tmp;
	kol=0;
	scanf("%d", &a_pred);
	scanf("%d", &a);
	
	key=0;
	
	if(a_pred == 1 && a == 2){
		p = 2;
		key = 1; 
	}
	
	if(a == 1){
		p = 1;
		key = 1;
	}
	
	while(scanf("%d", &tmp)==1){
		if(key==1){
			if(tmp - a == 1){
				p++;
				if(p==100) kol++;
				a_pred = a;
				a = tmp;
			}
			else{
				if(tmp==1){
					p=1;
					a_pred = a;
					a = tmp;
				}
				else{
					p=0;
					a_pred = a;
					a = tmp;
				}
			}
		}
		else{
			if(tmp==1){
				key=1;
				p=1;
				a_pred=a;
				a=tmp;
				continue;
			}
			else{
				a_pred = a;
				a = tmp;
				key = 0;
			}
		}	
	}
	
	printf("%d", kol);
	
}
