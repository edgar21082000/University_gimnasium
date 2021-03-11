#include <stdio.h>

int main(){
	unsigned char kol=1;
	unsigned char r=1;
	unsigned char buf[128];
	
	int i=0; int j;
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("cod.txt", "w");
	
	fscanf(A, "%c", &buf[i]); i++;
	
	while(fscanf(A, "%c", &buf[i])==1){
		if(buf[i]==buf[i-1]) {
			if (r>1){
				fprintf(B, "%c", r-1+128); 
				for(j=0;j<r-1;j++) fprintf(B, "%c", buf[j]);
				buf[0]=buf[i];
				i=1; r=1; kol=2;
			}
			else{
			kol++; 
			i++;
			}
		}
		else{
			if(kol>1){
				fprintf(B, "%c", kol);
				fprintf(B, "%c", buf[j]);
				buf[0]=buf[i];
				i=1;
				kol=1;
			}
			else{
				r++; i++;
			}
		}
	}
	
	//-------------------------------- last step
	if(buf[i]==buf[i-1]) {
			if (r>1){
				fprintf(B, "%c", r-1+128); 
				for(j=0;j<r-1;j++) fprintf(B, "%c", buf[j]);
				buf[0]=buf[i];
				i=1; r=1; kol=2;
			}
			else{
			kol++; 
			i++;
			}
		}
	else{
		if(kol>1){
			fprintf(B, "%c", kol);
			fprintf(B, "%c", buf[j]);
			buf[0]=buf[i];
			i=1;
			kol=1;
		}
		else{
			r++; i++;
		}
	}
	//-------------------------------- lasr step
	
	fclose(A); fclose(B);
	
	
	return 0;
}
