#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list{
	int index;
	int mark1;
	int mark2;
	char name[26];
	char surname[31];
}list;

int read(list*);
void mark1_sort(list *, int);
void replace_struct(list *, int);
void print_struct(list *, int);

int main(){
	list *mas;
	mas = (list *)malloc(1000*sizeof(list));
	int i = 0;
	while(read(&(mas[i]))==5) i++;
	//printf("%d\n", i);
	
	//print_struct(mas, i);
	mark1_sort(mas, i);
	print_struct(mas, i);
	
	return 0;
}

int read(list *k){
	int key = 0;
	if(scanf("%d", &(k->index))==1) key++;
	if(scanf("%s", k->name) == 1) key++;
	if(scanf("%s", k->surname)== 1) key++;
	if(scanf("%d", &(k->mark1))== 1) key++;
	if(scanf("%d", &(k->mark2))== 1) key++;
	return key;
}


void mark1_sort(list *a, int k){
	int len = k;
	int j;
	int flag = 1;
	while(flag == 1){
		flag = 0;
		k--;
		for(j=0;j<k;j++){
			if(a[j].mark1>a[j+1].mark1) replace_struct(a, j);
		}
	}
}

void replace_struct(list *a, int j){
	list tmp;
	tmp = a[j+1];
	a[j+1] = a[j];
	a[j] = tmp;
}

void print_struct(list *a, int k){
	int i;
	for(i=0;i<k;i++){
		printf("%d %s %s %d %d", a[i].index, a[i].name, a[i].surname, a[i].mark1, a[i].mark2);
		printf("\n");
	}
}
