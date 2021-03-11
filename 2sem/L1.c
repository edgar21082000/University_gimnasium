#include <stdio.h> 
#include <stdlib.h> 

struct L1 { 
	char str[30]; 
	struct L1 *next; 
}; 

void list_add(FILE * content, struct L1 *cur); 
void list_print(struct L1 *cur,struct L1 begin);

 
int main(void) { 
	FILE *content; 
	struct L1 begin; 
	struct L1 *cur; 

	content = fopen("numberone.txt","r"); 

	fscanf(content,"%s",&begin.str); 
	begin.next = NULL; 
	begin.next = (struct L1 *)malloc(sizeof(struct L1)); 
	cur = begin.next; 

	list_add(content,cur); 
	list_print(cur,begin); 

	fclose(content); 
	return 0; 
} 

void list_add(FILE *content, struct L1 *cur) { 
	while(fscanf(content,"%s",&(*cur).str)==1) { 
	(*cur).next = (struct L1 *)malloc(sizeof(struct L1)); 
	cur = (*cur).next; 
	(*cur).next = NULL; 
	} 
} 

void list_print(struct L1 *cur,struct L1 begin) { 
	cur = &begin; 
	while(cur != NULL) { 
		printf("%s\n",(*cur).str); 
		cur = (*cur).next; 
	} 
}