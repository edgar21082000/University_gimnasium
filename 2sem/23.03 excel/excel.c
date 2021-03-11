#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct L1
{
	char word[256];
	int kol;
	struct L1 *next;
};

struct L1 * special_list_add(struct L1*, struct L1*, struct L1, char *);
void list_print(struct L1 *, FILE *);

int main()
{
	FILE *A; FILE *B;
	A=fopen("WS.txt", "r"); B=fopen("newres.txt", "w");
	
	char tmp[256];
	struct L1 begin;
	struct L1 *run;
	struct L1 *start;
	start=&begin;
	fscanf(A, "%s", &begin.word);
	begin.kol=1;
	begin.next=NULL;
	begin.next=(struct L1 *)malloc(sizeof(struct L1));
	run=begin.next;
	int lol=1;
	
	while(fscanf(A, "%s", &tmp)==1) run=special_list_add(start, run, begin, tmp);
		
	list_print(start, B);	
	
	return 0 ;
}

struct L1 * special_list_add(struct L1 *st, struct L1 *cur, struct L1 b, char *temp) 
{ 
	while(st->next!=NULL)
	{
		if (strcmp(st->word,temp)==0)
		{			
			st->kol++;
			st=&b;
			return cur;
		}
		st=st->next;
	}
	
	stpcpy(cur->word,temp);
	cur->kol=1;
	cur->next = (struct L1 *)malloc(sizeof(struct L1)); 
	cur = cur->next; 
	cur->next = NULL;
	return cur;
} 

void list_print(struct L1 *st, FILE *A)
{
	while(st->next!=NULL) 
	{
		fprintf(A, "%25s" "%25d\n" , st->word, st->kol);
		st=st->next;
	}
	return;
}
