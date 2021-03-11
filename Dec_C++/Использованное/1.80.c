#include <stdio.h>

int main(){
	int len; int len_ans;
	int sum; int s_max;
	int tmp, last;
	
	scanf("%d", &last);
	sum = last; s_max = 0;
	len = 1;
	while(scanf("%d", &tmp)==1){
		if(tmp == last){
			//printf("rrrr\n");
			sum+=last;
			len+=1;
			//printf("%d -- %d\n", sum, len);
		}
		else{
			//printf("hhhhh\n");
			if(sum>s_max){ 
				s_max = sum;
				len_ans = len;
				last = tmp;
				sum = last;
				len = 1;
				//printf("%d -- %d __ %d\n", sum, len, len_ans);
			}
			else{
				//printf("xxxx\n");
				last = tmp;
				sum = last;
				len = 1;
			}
		}
	}
	
	if(sum>s_max) len_ans = len;
	
	printf("%d", len_ans);
	
}
