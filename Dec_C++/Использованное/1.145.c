#include <stdio.h>
#include <stdlib.h>

int main(){
	//FILE *A; A=fopen("in.txt", "r");
	//FILE *B; B=fopen("out.txt", "w");
	
	//A = stdin;
	//B = stdout;
	
	
	int i, j, k;
	int a, b; 
	int *mas1, *mas2, *mas3;
	
	
	
	scanf("%d", &a);
	mas1 = (int *)malloc(a*sizeof(int));
	for(i=0;i<a;i++) scanf("%d", &mas1[i]);
	
	
	scanf("%d", &b);
	mas2 = (int *)malloc(b*sizeof(int));
	for(i=0;i<b;i++) scanf("%d", &mas2[i]);
	
	
	
	mas3 = (int *)malloc((a+b)*sizeof(int));
	i = 0; 
	j = 0;
	for(k=0;k<a+b;k++){
		if(i==a){
			mas3[k] = mas2[j];
			j++;
		}
		else
		if(j==b){
			mas3[k] = mas1[i];
			i++;
		}
		else
		if(mas1[i]>mas2[j]){
			mas3[k] = mas2[j];
			j++;
			printf("-%d\n",mas2[j-1]);
		}
		else{
			mas3[k] = mas1[i];
			i++;
			//printf("-%d\n",mas1[i-1]);
		}
		
	}
	
	for(k=0;k<a;k++) printf("%d ", mas1[k]); printf("\n");
	for(k=0;k<b;k++) printf("%d ", mas2[k]); printf("\n");
	
	for(k=0;k<a+b;k++) printf("%d ", mas3[k]);printf("\n");
}
