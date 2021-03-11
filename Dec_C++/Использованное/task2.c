#include <stdio.h>
#include <math.h>

int main(){
	double min, max, sr, sum, kol, tmp;
	
	scanf("%lf", &tmp);
	min = tmp;
	max = tmp;
	sum = tmp;
	kol = 1;
	sr = sum/kol;
	
	while(scanf("%lf", &tmp)==1){
		if(tmp<min) min = tmp;
		if(tmp>max) max = tmp;
		sum+=tmp;
		kol++;
	}
	sr=sum/kol;
	printf("%lf", fmax(fabs(sr - min), fabs(sr - max)));
	return 0;	
}
