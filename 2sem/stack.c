# include <stdio.h>
#include <stdlib.h>

int *mem;
int Nmax;
int Ncur;
int a;

int st_create();
int st_prn();
int st_term();
int st_push();
int st_pop();
void st_exit();



int main()
{
	while(1){
	int  key;
	printf("\n1 - добавить число\n2 - удалить число\n3 - удалить стек\n4 - распечатать стек\n5 - создать стек\n6 - завершить программу\n");
	printf("_ _ _ _ _ _ _ _ _ _ _\n");
	printf("\nВведите число от 1 до 6: ");
	scanf("%d", &a);
	if (a>6 || a<0) printf("\nОшибка ввода");
	if (a==6) st_exit();
	if (a==5)
	{
		key=st_create();
		if (key==1) printf("\nОперация успешно выполнена");
		if (key==0) printf("\nСбой при выполнении операции");
	}
	if (a==4)
	{
		key=st_prn(mem);
		if (key==1) printf("\nОперация успешно выполнена");
		if (key==0) printf("\nСбой при выполнении операции");
	}
	if (a==3) 
	{
		key=st_term();
		if (key==1) printf("\nОперация успешно выполнена");
		if (key==0) printf("\nСбой при выполнении операции");
	}
	if (a==2) 
	{
		key=st_pop();
		if (key==1) printf("\nОперация успешно выполнена");
		if (key==0) printf("\nСбой при выполнении операции");
	}
	if (a==1) 
	{
		key=st_push();
		if (key==1) printf("\nОперация успешно выполнена");
		if (key==0) printf("\nСбой при выполнении операции");
	}
	}
	return 0;
} 

int st_create()
{
	if (Nmax>0) return 0;
	printf("\nВведите размер стека: ");
	scanf("%d", &Nmax);
	Ncur=0;
	mem=(int *)malloc(Nmax*sizeof(int));
	if (mem==NULL) return 0;
	else return 1;
}

int st_push()
{
	Ncur++;
	if (Ncur<=Nmax)
	{
		printf("\nВведите число: ");
		scanf("%d", &a);
		mem[Ncur-1]=a;
		return 1;
	}
	if (Ncur>Nmax) 
	{
		Ncur--;
		return 0;
	}
}

int st_pop()
{
	Ncur--;
	if (Ncur>=0) return 1;
	if (Ncur<0) 
	{
		Ncur++;
		return 0;
	}
}	

int st_term()
{
	if (Nmax>0)
	{
		free(mem);
		Nmax=0;
		Ncur=0;
		return 1;
	}
	if (Nmax<=0) return 0;	
}	

int st_prn()
{
	int i;
	if (Nmax>0)
	{
		for (i=0;i<Ncur;i++)
		{
			printf("%d ", mem[i]);
		}
		return 1;
	}
	if (Nmax<=0) return 0;
}

void st_exit()
{
	printf("\n\n\n ДО СВИДАНИЯ!!!");
	exit (1);
}
