#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int kod(char t1, int s);

int main(){
	printf("     5    6    7    8    9");
	char t;
	while (scanf("%c", &t)==1){
		int k5 = kod(t, 5);
		int k6 = kod(t, 6);
		int k7 = kod(t, 7);
		int k8 = kod(t, 8);
		int k9 = kod(t, 9);
		
		printf("%c    %d    %d    %d    %d\n", t, k5, k6, k7, k8, k9);
	}
}

int kod(char t1, int s){
	int res, r, q, i;
	int t = (int)t1;
	res = 0;
	for (i=0;i<3;i++){
		q=t / s;
		r = t - q*s;
		res+=r*pow(10, i);
		t=q;
	}
	return res;
}
