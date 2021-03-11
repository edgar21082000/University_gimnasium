#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 20 // Кол-во контейнеров(группп)
#define N 20 // Максимальная длина слова

int i;

struct L1 { 
	char word[20]; 
	struct L1 *next; 
}; 

unsigned hash(char *);
unsigned int HashRot13(char *);
unsigned int HashLy(char *);
void mas_struct_print(struct L1 **);
void mas_print(FILE *, unsigned int *);

int main()
{
	struct L1 **mas;
	mas=(struct L1 **)malloc(M*sizeof(struct L1 *));
	if(mas==NULL) printf("error");
	for(i=0;i<M;i++) mas[i]=(struct L1 *)malloc(sizeof(struct L1));
	for(i=0;i<M;i++) mas[i]->next=NULL;
	
	struct L1 **start;
	start=(struct L1 **)malloc(M*sizeof(struct L1 *));
	for(i=0;i<20;i++) start[i]=mas[i];
	
	
	//-------------------------------------------
	FILE *A; A=fopen("WS.txt", "r");
	FILE *B; B=fopen("hash_output.txt", "w");
	

	char word[1024];
	unsigned int mes[M];

	
	//_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_
	
	for(i=0;i<M;i++) mes[i]=0;
	
	while(fscanf(A, "%s", &word[0])==1) 
	{
		while (start[((HashLy(word))%M)]!=NULL){
			if (strcmp(start[((HashLy(word))%M)]->word,word)==0) continue;
			start[((HashLy(word))%M)]=start[((HashLy(word))%M)]->next;
		}
		
		mes[((HashLy(word))%M)]++;
		
		strcpy(mas[((HashLy(word))%M)]->word, word);
		mas[((HashLy(word))%M)]->next=(struct L1 *)malloc(sizeof(struct L1));
		mas[((HashLy(word))%M)]=mas[((HashLy(word))%M)]->next;
		mas[((HashLy(word))%M)]->next=NULL;
	}
	
	mas_print(B, mes);
	mas_struct_print(start);
	
	return 0;
}

unsigned hash(char *tmp){ 
	return (unsigned int)(strlen(tmp));
}

unsigned int HashRot13( char * str){
	unsigned int hash = 0;
	for(; *str; str++){
	hash += (unsigned char)(*str);
	hash -= (hash << 13) | (hash >> 19);
	}
	return hash;
}

void mas_print(FILE *A, unsigned int *mas){
	int i;
	for(i=0;i<M;i++) fprintf(A, "%d %lf\n", i+1, ((double)mas[i]/32000.0)*100.0);
	return ;
}

void mas_struct_print(struct L1 **cur){
	FILE *f;
	char mass [M];
	for (i=0;i<M;i++){
		sprintf (&mass[0], "hash_group_%02d.txt",i);
		f=fopen(&mass[0], "w");
		
		while(cur[i]!=NULL){
			 fprintf(f, "%s\n", cur[i]->word);
			 cur[i]=cur[i]->next;
		}
	}
	return ;
}

unsigned int HashLy(char * str){
	unsigned int hash = 0;
	for(; *str; str++)
	hash = (hash * 1664525) + (unsigned char)(*str) + 1013904223;
	return hash;
}



