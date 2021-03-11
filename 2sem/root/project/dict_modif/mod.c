#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct L1 
{
	char word[30];
	char w_trigramme[1024];
	struct L1 *next;
};

char** trigramme_creat(char *);

struct L1* L1_add(struct L1 *, char *, char *);
void L1_print(FILE *, struct L1 *, struct L1); 

int main()
{
	FILE *A; A=fopen("redact3.txt", "r");
	FILE *B; B=fopen("modification.txt", "w");
	
	int j;
	
	char b[7]; for (j=0;j<6;j++) b[j]='-';	
	
	struct L1 begin;
	struct L1 *run;
	
	strcpy(begin.word, b);
	begin.next=NULL;
	begin.next=(struct L1 *)malloc(sizeof(struct L1)); 
	run=begin.next;
	
	char **input; 
	char **dict_word;
	
	char tmp[30];
	char strtmp[1024];
	
	
	
	while (fscanf(A, "%s", &tmp)==1)
	{
		dict_word=trigramme_creat(tmp);
		
		for (j=0;j<strlen(tmp)+1;j++)
		{
			strcpy(&(strtmp[(4*j)]), dict_word[j]);
			strtmp[(4*j)+3]='0';
		}
		strcpy(&(strtmp[(4*j)]), dict_word[j]);
		strtmp[(4*j)+3]='\0';
		
		printf("%s\n", strtmp);
		
		run=L1_add(run, tmp, strtmp);
		
	}
	
	L1_print(B, run, begin);
	
	return 0;
}

char** trigramme_creat(char *cur)
{
	int j;
	char **temp;
	temp=(char **)malloc((strlen(cur)+2)*sizeof(char *));
	if (temp==NULL) {printf("Hjkhgh"); exit(1);}
	
	if (strlen(cur)>1)
	{
		for(j=0;j<strlen(cur)+2;j++)
		{
			temp[j]=(char *)malloc(4*sizeof(char));
			
			if (j>1 && j<strlen(cur))
			{
				temp[j][0]=cur[j-2];
				temp[j][1]=cur[j-1];
				temp[j][2]=cur[j];
			}
		
			if (j==0)
			{
				temp[j][0]='_';
				temp[j][1]='_';
				temp[j][2]=cur[0];
			}
		
			if (j==1)
			{
				temp[j][0]='_';
				temp[j][1]=cur[0];
				temp[j][2]=cur[1];
			}
		
			if (j==strlen(cur))
			{
				temp[j][0]=cur[strlen(cur)-2];
				temp[j][1]=cur[strlen(cur)-1];
				temp[j][2]='_';
			}
		
			if (j==strlen(cur)+1)
			{
				temp[j][0]=cur[strlen(cur)-1];
				temp[j][1]='_';
				temp[j][2]='_';
			}
		}
	}
	
	if (strlen(cur)==1)
	{
		for(j=0;j<strlen(cur)+2;j++) temp[j]=(char *)malloc(4*sizeof(char));
		
		temp[0][0]='_';
		temp[0][1]='_';
		temp[0][2]=cur[0];
		
		temp[1][0]='_';
		temp[1][1]=cur[0];
		temp[1][2]='_';
		
		temp[2][0]=cur[0];
		temp[2][1]='_';
		temp[2][2]='_';
	}
	
	return temp;
}

struct L1* L1_add(struct L1 *cur, char *slovo, char *trig) 
{ 
	stpcpy(cur->word, slovo);

	stpcpy(cur->w_trigramme,slovo);
	cur->w_trigramme[strlen(slovo)]='1';
	stpcpy(&(cur->w_trigramme[strlen(slovo)+1]), trig);

	cur->next=(struct L1 *)malloc(sizeof(struct L1)); 
	cur=cur->next; 
	cur->next=NULL;
	return cur;
} 

void L1_print(FILE *B, struct L1 *cur, struct L1 begin) 
{ 
	cur=begin.next; 
	while(cur->next!=NULL) 
	{ 
		fprintf(B, "%s\n",cur->w_trigramme);
		cur=cur->next; 
	} 
}