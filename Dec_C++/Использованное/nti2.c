#include <stdio.h>
#include <string.h>

int main(){
	int a[26];
	int i, j, max;
	
	for(i=0;i<26;i++) a[i]=0;
	
	int kol, mus; scanf("%d %d", &kol, &mus);
	char str1[kol+mus+1]; char l;
	
	scanf("%s", str1);
	
	
	for(i=0;i<kol;i++){
		a[str1[i]-97]++;
	}
	
	max=0;
	
	
	for(i=0;i<26;i++){
		if(a[i]>max){
			max=a[i];
			j=i;
			
		}
	}
	
	

	
	l=97+j; 
	
	for(i=0;i<mus;i++) str1[kol+i]=l;
	str1[kol+mus]='\0';
	
	
	printf("%s", str1);
	return 0;
	
}
