#include <stdio.h>
#include <stdlib.h>

int main(){
	int mas[26];
	int i;
	for(i=0;i<26;i++) mas[i] = 0;
	
	
	char let;
	while(scanf("%c", &let)==1){
		if(let=='.') break;
		if(let <= 'z' && let >= 'a') mas[let - 'a']++;
		if(let <= 'Z' && let >= 'A') mas[let - 'A']++;
	}
	
	
	int max = 0;
	for(i=0;i<26;i++) if(mas[i]>max) max = mas[i];
	for(i=0;i<26;i++) if(mas[i] == max) printf("%c %d\n", ('a'+i), mas[i]);
	return 0;
}
