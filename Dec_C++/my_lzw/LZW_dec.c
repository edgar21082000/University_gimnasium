#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int st(int x, int a);
int* debyte(unsigned char* byte, int* bit);
int* debit(int* bit, int* temp);

int main(){
	FILE* fp; fp=fopen("dictionar.txt", "r"); 
	int i, j;
	
	char** dict; dict=(char **)malloc(4096*sizeof(char *));
	for(i=0;i<4096;i++) { dict[i]=(char *)malloc(4096*sizeof(char)); memset(dict[i], 0, 4096);}
	
	char n[1]; n[0]='0'; // Нулевой элемент предусматривается для декодирования
	strcpy(dict[0], n); //printf("%s\n\n", dict[0]);
	i=1;
	while(fscanf(fp, "%s", dict[i])==1) i++;    // Считал имеющийся словарь
	int d_size=27;
	
	FILE* A; A=fopen("cod.txt", "rb");
	FILE* B; B=fopen("decod.txt", "w");
	
	unsigned char* byte; byte=(unsigned char *)malloc(3*sizeof(unsigned char));
	int* bit; bit=(int *)malloc(24*sizeof(int));
	
	char* W; W=(char *)malloc(4096*sizeof(char)); 
	int w_kol=0;
	
	char* last; last=(char *)malloc(4096*sizeof(char));
	
	int* temp; temp=(int *)malloc(2*sizeof(int)); 
	int flag=0;
	int num, nt;
	
	
	
	
	while(fread(byte, sizeof(char), 3, A)==3){
		temp[0]=0; 
		temp[1]=0;
															for(i=0;i<3;i++) printf("<<%d>> lol ",byte[i]);printf("\n");
															
		bit=debyte(byte, bit);								for(i=27;i<40;i++) printf("%s-%d ", dict[i], i); printf("\n");
															for(i=0;i<8;i++) printf("%d", bit[i]); printf("_"); for(i=8;i<16;i++) printf("%d", bit[i]); printf("_"); for(i=16;i<24;i++) printf("%d", bit[i]); printf("\n");
															for(i=0;i<12;i++) printf("%d", bit[i]); printf("_"); for(i=12;i<24;i++) printf("%d", bit[i]); printf("\n");
		temp=debit(bit, temp);								printf("temp[0]=%d\ntemp[1]=%d\n", temp[0], temp[1]);
		
		for(i=0;i<2;i++){
			if(temp[i]==0) break;
			
			if(temp[i]==d_size){
				strcpy(dict[d_size], last);
				dict[temp[i]][strlen(last)]=last[0];
				dict[temp[i]][strlen(last)+1]='\0';
				d_size++;
			}
			
			printf("W_KOL: %d\n", w_kol);
			if(w_kol > 4096) {
			printf("======================================\nW_KOL: %d\n", w_kol);
			return -1;
 			}
			
			W[w_kol]=dict[temp[i]][0];
			W[w_kol+1]='\0';
			
			//for(j=0;j<strlen(dict[temp[i]]);j++) fprintf(B, "%c", dict[temp[i]][j]);
			fprintf(B, "%s", dict[temp[i]]);				printf("out - %s\n", dict[temp[i]]);
			strcpy(last, dict[temp[i]]);					printf("W - %s\n", W);
			nt=compare(W, dict, d_size);					printf("nt - %d\n", nt);
			
			if(nt<d_size){
				//w_kol+=strlen(W);
				w_kol=strlen(W);
			}
			else{
				strcpy(dict[d_size], W);
				d_size++;									printf("d_size - %d\n", d_size);
				
				strcpy(W, dict[temp[i]]);					printf("W-new - %s\n", W);
				w_kol=strlen(dict[temp[i]]);				printf("w_kol - %d\n", w_kol);
			}
			
			if(d_size==4096) d_size=27;						printf("\n");
		}
		printf("\n");
		
	}
	
	fclose(fp); fclose(A); fclose(B);
	
	return 777;
}

int st(int x, int a){
	int i, res;
	res=x;
	
	if(a==0) return 1;
	for(i=1;i<a;i++) res=res*x;
	return res;
}

int compare(char* W, char** dict, int d_size){
	int i;
	for(i=0;i<d_size;i++){
		if(strcmp(W, dict[i])==0) return i;
	}
	return d_size;
}

int* debyte(unsigned char* byte, int* bit){
	int i, j;
	
	for(i=0;i<3;i++){
		for(j=0;j<8;j++){
			if(byte[i]>=st(2, 7-j)){
				bit[8*i+j]=1;
				byte[i]=byte[i]-st(2, 7-j);
			}
			else bit[8*i+j]=0;
		} 
	}
	return bit;
}

int* debit(int* bit, int* temp){
	int i, j;
	
	for(i=0;i<12;i++) if(bit[i]==1) temp[0]+=st(2, 11-i);
	for(j=12;j<24;j++) if(bit[j]==1) temp[1]+=st(2, 23-j); 
	
	return temp;
}




