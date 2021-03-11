#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int st(int x, int a);
int* bit_mas_create(int* bit, int a, int b);
void byte_create(int* bit, FILE *B);
int compare(char* W, char** dict, int d_size);

int main(){
	FILE* fp; fp=fopen("dictionar.txt", "r"); 
	int i, j;
	
	char** dict; dict=(char **)malloc(4096*sizeof(char *));
	for(i=0;i<4096;i++) dict[i]=(char *)malloc(4096*sizeof(char));
	
	char n[1]; n[0]='0'; // Íóëåâîé ýëåìåíò ïðåäóñìàòðèâàåòñÿ äëÿ äåêîäèðîâàíèÿ
	strcpy(dict[0], n); //printf("%s\n\n", dict[0]);
	i=1;
	while(fscanf(fp, "%s", dict[i])==1) i++;    // Ñ÷èòàë èìåþùèéñÿ ñëîâàðü
	int d_size=27;
	
	/*int* bit; bit=(int *)malloc(24*sizeof(int));
	bit = bit_mas_create(bit, 16 , 1);
	for(i=0;i<24;i++) printf("%d", bit[i]);                     // ÏÐÎÂÅÐÊÀ ÔÓÍÊÖÈÉ
	printf("\n");
	byte_create(bit);*/
	
	FILE* A; A=fopen("in.txt", "r");
	FILE* B; B=fopen("cod.txt", "wb");
	
	int* bit; bit=(int *)malloc(24*sizeof(int));
	char* W; W=(char *)malloc(4096*sizeof(char)); 
	int w_kol=0;
	int temp[2]; int flag=0;
	int num, nt;
	
	fscanf(A, "%c", &W[w_kol]); 
	W[w_kol+1]='\0'; 
	w_kol++;
	
	num=compare(W, dict, d_size);
	
	while(fscanf(A, "%c", &W[w_kol])==1){
		W[w_kol+1]='\0';			 						
		printf("W - %s\n", W);
		
		nt=compare(W, dict, d_size); 						
		printf("nt - %d\nd_size - %d\n", nt, d_size);
				
		if(nt<d_size){
			num=nt;
			w_kol++; 										
			printf("w_kol - %d\n", w_kol);
		}
		
		if(nt==d_size){
			temp[flag]=num; 								
			printf("++temp[%d] = %d\n", flag, temp[flag]);
			flag++;
			if(flag==2){
				bit=bit_mas_create(bit, temp[0], temp[1]);  
				for(i=0;i<12;i++) printf("%d", bit[i]); 
				printf("_"); 
				for(i=12;i<24;i++) printf("%d", bit[i]); 
				printf("\n"); 
				printf("----exit 1) %d\n----exit 2) %d\n", temp[0], temp[1]);
				byte_create(bit, B);
				flag=0;
			}
			
			strcpy(dict[d_size], W);
			d_size++;
			
			W[0]=W[w_kol];
			W[1]='\0';
			w_kol=1;
			
			num=compare(W, dict, d_size);
		}
		
		if(d_size==4096) d_size=27;
	}
	
	if(flag==1){
		temp[1]=num;
		bit=bit_mas_create(bit, temp[0], temp[1]);  		
		printf("----exit 1) %d\n----exit 2) %d\n", temp[0], temp[1]);
		byte_create(bit, B);
	}
	
	if(flag==0){
		bit=bit_mas_create(bit, num, 0);  					
		printf("----exit 1) %d\n----exit 2) %d\n", num, 0);
		byte_create(bit, B);
	}
	
	fclose(fp); fclose(A); fclose(B);
	
	return 777;
}

int * bit_mas_create(int* bit, int a, int b){
	int i, j;
	
	for(i=0;i<12;i++){
		if(st(2, 11-i)>a) bit[i]=0;
		if(st(2, 11-i)<=a){
			bit[i]=1;
			a=a-st(2, 11-i);
		}
	}
	
	for(j=0;j<12;j++){
		if(st(2, 11-j)>b) bit[12+j]=0;
		if(st(2, 11-j)<=b){
			bit[12+j]=1;
			b=b-st(2, 11-j);
		}
	}
	
	return bit;
}

int st(int x, int a){
	int i, res;
	res=x;
	
	if(a==0) return 1;
	for(i=1;i<a;i++) res=res*x;
	return res;
}

void byte_create(int* bit, FILE *B){
	int i, j;
	unsigned char byte[3]; for(i=0;i<3;i++) byte[i]=0;
	
	for(i=0;i<3;i++){
		for(j=8*i;j<8*i+8;j++){
			if(bit[j]==1) byte[i]+=st(2, 7-j+i*8);
		}
	}
	fwrite(byte, sizeof(char), 3, B);
	for(i=0;i<3;i++) 										
		printf("------------------------%d(%c)\n", byte[i], byte[i]); printf("\n");
}

int compare(char* W, char** dict, int d_size){
	int i;
	for(i=0;i<d_size;i++){
		if(strcmp(W, dict[i])==0) return i;
	}
	return d_size;
}


