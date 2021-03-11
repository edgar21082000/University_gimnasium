#include <stdio.h>
#include <stdlib.h>

struct task{
	int num;
	int kol;
	struct task *next;
};

int main(){
	struct task *begin;
	begin = (struct task * )malloc(sizeof(struct task));
	struct task *start = begin;
	
	begin->kol = 0;
	begin->next = NULL;
	
	
	scanf("%d", &(begin->num));
	begin->kol++;
	
	int tmp;
	begin = start;
	
	while(scanf("%d", &tmp) == 1){
		while(begin!=NULL){
			if(begin->num == tmp){
				begin->kol++;
				break;
			}
			else{
				begin = begin->next;
			}
		}
		
		if(begin == NULL){
			begin = (struct task *)malloc(sizeof(struct task));
			begin->num = tmp;
			begin->kol = 1;
			begin->next = NULL;
		}
		
		begin = start;
	}
	
	begin = start;
	while(begin!=NULL) {printf("%d ", begin->num); begin = begin->next;}
	
	begin = start;
	while(begin!=NULL) {printf("%d ", begin->kol); begin = begin->next;}
	
}
