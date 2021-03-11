#include  <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (void){
	int i;
	FILE *f;
	char mass [10];
	for (i=0;i<12;i++){
		sprintf (&mass[0], "prn_%05d.txt",i);
		f=fopen(&mass[0],"w");
		
	   
	}
	return 0;
}