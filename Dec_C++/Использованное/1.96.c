#include <stdio.h>

int main(){
	int sum_tmp, sum_max;
	int a, tmp;
	
	sum_tmp = 0;
	sum_max = 0;
	
	scanf("%d", &a);
	sum_tmp = a;
	sum_max = sum_tmp;
	
	while(scanf("%d", &tmp)==1){
		sum_tmp += tmp;
		if(sum_tmp > sum_max) sum_max = sum_tmp;
		if(tmp>sum_max) sum_max = tmp;
		
		if(sum_tmp<=0){
			if(tmp<=0) sum_tmp = 0;
			else sum_tmp = tmp;
		}
	}
	
	printf("%d", sum_max);
}
