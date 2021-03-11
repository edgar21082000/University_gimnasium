#include  <stdio.h>
#include <stdlib.h>

struct deck {
	int *mem;
	int * left;
	int * right;
	int n_max;
	int n_car;
};

int str_init (struct deck * B);
void st_prn (struct deck * B);
int st_push_left (int val,struct deck * B);
int st_push_right (int val,struct deck * B);
int st_ter(struct deck * B);
int st_pop_right(int* x,struct deck * B );
int st_pop_left(int* x,struct deck * B );


int main(void) {
	int x,k,side,val,m;
	struct deck A;
	while (1){
	printf ("MENU\n");
	printf ("Нажмите 1, чтобы создать dec\n");
	printf ("Нажмите 2, чтобы удалить dec\n");
	printf ("Нажмите 3, чтобы добавить элемент в dec\n");
	printf ("Нажмите 4, чтобы убрать элемент из dec\n");
	printf ("Нажмите 5, чтобы печатать dec\n");
	printf ("Нажмите 6, закончить работу\n");
	
	scanf ("%d",&x);
	if ((x!=1)&&(x!=2)&&(x!=3)&&(x!=4)&&(x!=5)&&(x!=6)){
		printf ("Такой команды нет\n");
		continue;
	}
	if (x==6){
		return 0;
	}
	if (x==1){
		if ((A.n_max)>0){
			printf("Deck уже создан\n"); 
			continue;
		}
		scanf ("%d", &(A.n_max));
		k=str_init(&A);
		if (k!=0) {
			printf ("Недостаточно памяти\n");
		}
		else {
			printf ("Выполнено\n");
		}
	}
	if (x==5){
		//printf ("OK_4\n");
		if (A.n_max==0){
			printf ("Decka'а нет\n");
			continue;
		}
		if ((A.n_car)==0){
			printf ("Нет элементов\n");
			continue;
		}
		st_prn(&A);
	}
	if (x==3){
		if (A.n_max==0){
			printf ("Stack'а нет\n");
			continue;
		}
		if ((A.n_car)==(A.n_max)){
			printf ("Количество элементов максимально\n");
			continue;
		}
		printf ("Введите элемент\n");
		scanf ("%d",&val);
		printf ("Нажмите 1 - добавить с левой стороны\nНажмите 2 - добавить с правой стороны\n");
		scanf ("%d", &side);
		if (side ==1){
			k=st_push_left(val,&A);
			if (k!=0) {
				printf ("Не выполнено\n");
			}
			else {
				printf ("Выполнено\n");
		}
		}
		if (side ==2){
			k=st_push_right(val,&A);
			if (k!=0) {
				printf ("Не выполнено\n");
			}
			else {
				printf ("Выполнено\n");
		}
		}		
	}
	if (x==2){
		if (A.mem!=NULL){
		k=st_ter(&A);
		if (k!=0) {
			printf ("Не выполнено\n");
		}
		else {
			printf ("Выполнено\n");
		}
		}
		else {printf ("Stack'а нет ");}
		}
	if (x==4){
		if (A.n_max==0){
			printf ("Stack'а нет\n");
			continue;
		}
		if (A.n_car==0){
			printf ("Нет элементов\n");
			continue;
		}
		printf ("Нажмите 1 - убрать с левой стороны\nНажмите 2 - убрать с правой стороны\n");
		scanf ("%d", &side);
		if (side ==1){
			k=st_pop_left(&m,&A);
			if (k!=0) {
				printf ("Не выполнено\n");
			}
			else {
				printf ("Последний элемент равен %d\n",m);
				printf ("Выполнено\n");
			}
		}
		if (side ==2){
			k=st_pop_right(&m,&A);
			if (k!=0) {
				printf ("Не выполнено\n");
			}
			else {
				printf ("Последний элемент равен %d\n",m);
				printf ("Выполнено\n");
			}
		}
		
	}
}
return 0;
}




int str_init (struct deck * B){
	int i;
	(*B).mem=(int*)malloc ((*B).n_max*sizeof(int));
	if ((*B).mem==NULL){
		return 1;
	}
	(*B).left = (*B).mem;
	(*B).right = ((*B).mem)+1;
	(*B).n_car=0;
	for (i=0;i<(*B).n_max;i++){
		(*B).mem[i]=0;
	}

	return 0;
}

void st_prn (struct deck * B){
	int i;
	if (((*B).left)+1>((*B).right)){
		printf ("from left\n");
		printf ("Start\n");
		printf ("------\n");
		for (i=((((*B).left)+1)-((*B).mem));i<(*B).n_max;i++){
			if (((*B).mem[i])==0){
			printf ("*\n");
			}
			else{
			printf ("%d\n",(*B).mem [i]);}
		}
		for (i=0;i<(((*B).right)-((*B).mem));i++){
			if (((*B).mem[i])==0){
			printf ("*\n");
			}
			else{
			printf ("%d\n",(*B).mem [i]);}
		}
		printf ("------\n");
		printf ("End\n");
		
	}
	printf ("from mem\n");
	printf ("Start\n");
	printf ("------\n");
	for (i=0;i<(*B).n_max;i++){
		if (((*B).mem[i])==0){
			printf ("*\n");
		}
		else{
		printf ("%d\n",(*B).mem [i]);}
	}
	printf ("------\n");
	printf ("End\n");
	return;
}

int st_push_left (int val,struct deck * B){
	*((*B).left)=val;
	if (*((*B).left)==val){
		((*B).n_car)++;
		(*B).left--;
		if ((*B).left<(*B).mem){
			(*B).left=(*B).mem +(*B).n_max-1;
		}
		return 0;
	}
	return 1;
}

int st_push_right (int val,struct deck * B){
	*((*B).right)=val;
	if (*((*B).right)==val){
		((*B).n_car)++;
		(*B).right++;
		if ((*B).right>(*B).mem+(*B).n_max-1){
			(*B).right=(*B).mem;
		}
		return 0;
	}
	return 1;
}

int st_ter(struct deck * B){
	free ((*B).mem);
	(*B).mem=NULL;
	(*B).n_max=0;
	if ((*B).n_max==0){
		(*B).n_max=0;
		(*B).n_car=0;
		(*B).left=NULL;
		(*B).right=NULL;
		return 0;
	}
	return 1;
	}
	
	int st_pop_left(int* x,struct deck * B ){
	(*B).left++;
	if ((*B).left>(*B).mem+(*B).n_max-1){
			(*B).left=(*B).mem;
		}
	*x=*((*B).left);
	(*B).n_car=(*B).n_car-1;
	*((*B).left)=0;
	return 0; 
}

int st_pop_right(int* x,struct deck * B ){
	(*B).right--;
	if ((*B).right<(*B).mem){
			(*B).right=(*B).mem +(*B).n_max-1;
		}
	*x=*((*B).right);
	(*B).n_car=(*B).n_car-1;
	*((*B).right)=0;
	return 0; 
}