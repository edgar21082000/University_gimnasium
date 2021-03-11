#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct L1
{
	char word[30];
	struct L1 *next;
};

char** trigramme_creat(char *);
char* buffer_creat(FILE *);

struct L1* trigramme_compare_faulse_type1(struct L1 *, char **, char **, char *);
struct L1* trigramme_compare_faulse_type2(struct L1 *, char **, char **, char *, char *);

struct L1* L1_add(struct L1 *, char *);
void L1_print(struct L1 *, struct L1);

int main()
{
	FILE *A; A=fopen("modification.txt", "r");
	
//---------------------------------------------------//	
	
	int i, j, h, g, index;
	
	char b[7]; for (j=0;j<6;j++) b[j]='-';	
	
	struct L1 begin;
	struct L1 *run;
	
	strcpy(begin.word, b);
	begin.next=NULL;
	begin.next=(struct L1 *)malloc(sizeof(struct L1)); 
	run=begin.next;
	
//---------------------------------------------------//	

	char read[30];
	scanf("%s", &read);
	printf("\n");
	char **input=trigramme_creat(read);
	for(j=0;j<strlen(read)+2;j++) printf("%s\n ", input[j]);
	printf("\n");
	
//---------------------------------------------------//	

	char *dictionar = buffer_creat(A);
	
//---------------------------------------------------//	

	char *combination; combination=(char *)malloc(1024*sizeof(char));
	char *tmp; tmp=(char *)malloc(100*sizeof(char));
	char **dict_word;

//---------------------------------------------------//	
	
	//puts(dictionar);
	
	
	j=0;
	h=0;
	g=0;
	index=0;
	
	for(i=0;i<7999;i++)
	{
		while(dictionar[j]!='\0')
		{
			combination[j]=dictionar[j];
			j++;
		}
		
		j++;
		
		while(combination[h]!='1')
		{
			tmp[h]=combination[h];
			h++;
		}
		
		h++;
		
		for(g=0;g<strlen(tmp)+1;g++)
		{
			while(combination[h]!='0')
			{
				dict_word[g][index]=combination[h];
				h++;
				index++;
				if (combination[h]=='0') index=0;
			}
			
			h++;
		}
		
		
		
		
		if (strlen(read)==strlen(tmp))	 run=trigramme_compare_faulse_type1(run, input, dict_word, tmp);  
		if (strlen(read)==strlen(tmp)-1) run=trigramme_compare_faulse_type2(run, dict_word, input, tmp, read);                    
		if (strlen(read)==strlen(tmp)+1) run=trigramme_compare_faulse_type2(run, input, dict_word, tmp, read);
		
	}
	
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

struct L1* trigramme_compare_faulse_type1(struct L1 *cur, char **misprint, char **vocabulary, char *temp)
{
	int wrong=0;
	int j;
		
	for (j=0;j<strlen(temp)+2;j++)
	{
		if ((misprint[j][0]==vocabulary[j][0] && misprint[j][1]==vocabulary[j][1]) && (misprint[j][2]==vocabulary[j][2])) continue;
		else wrong++;
			
		if (wrong>3) return cur;
	}
	
	if (wrong==0) 
	{
		printf("Слово написано правильно\n");
		return NULL;
	}
		
	if (wrong==3)
	{
		cur=L1_add(cur, temp);
		return cur;
	}
}

struct L1* trigramme_compare_faulse_type2(struct L1 *cur, char **big_word, char **small_word, char *temp, char *my)
{
	int i, j, s;
	int koef=0;
	
	if (strlen(temp)>strlen(my)) s=strlen(temp);
	else s=strlen(my);
	
	for (i=0;i<s+1;i++)
	{
		for (j=0;j<s+2;j++)
		{
			
			if (((small_word[i][0]==big_word[j][0]) && (small_word[i][1]==big_word[j][1])) && (small_word[i][2]==big_word[j][2])) continue;
			else koef++;
		}
	}
	
	if (((koef==(s*s+2*s+3)) || (koef==(s*s+2*s+2))) || (koef==(s*s+2*s+1)))
	{
		cur=L1_add(cur, temp);
		return cur;
	}
	else return cur;
}

struct L1* L1_add(struct L1 *cur, char *slovo) 
{ 
	stpcpy(cur->word, slovo);
	cur->next=(struct L1 *)malloc(sizeof(struct L1)); 
	cur=cur->next; 
	cur->next=NULL;
	return cur;
} 

void L1_print(struct L1 *cur,struct L1 begin) 
{ 
	cur=begin.next; 
	while(cur->next!=NULL) 
	{ 
		printf("%s\n",cur->word);
		cur=cur->next; 
	} 
}

char* buffer_creat(FILE *B)
{
	fseek(B, 0, SEEK_END);
	long int size = ftell(B);
	rewind(B);
	
	char *buffer = (char *)malloc(sizeof(char)*size);
	
	size_t result = fread(buffer, 1, size, B);
	if (result!=size)
	{
		printf("error");
		exit (1);
	}
	 
	return buffer;
}

