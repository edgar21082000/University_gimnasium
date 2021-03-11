#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print( FILE *A, int *mas, int N);
void zap(FILE *A, int *mas, int N);

void print(FILE *A, int *mas, int N)                           // печать  массива //
{
	int i;
	for (i=0;i<N;i++)                  			
	{
		fprintf(A, "%d ", mas[i]);
	}
	return;
}
void zap(FILE *A, int *mas, int N)                               // заполнение массива //
{ 
	int i;
	for (i=0;i<N;i++) 
{
	fscanf(A,"%d", &mas[i]);
}
return;
}

int main(void)
{
FILE *A;
int *mas;
int N;											       //файл нас не интересуетб мы только скачиваем его//
A=fopen("a.txt", "r");						           // если не в текущей директори то пишем fopen("./название/a.input", "r") //
if (A==NULL)
{
	printf ("error");
	exit (1);
}
fscanf(A,"%d", &N);
mas=(int *)malloc(N*sizeof(int));
zap(A, mas, N);
fclose(A);
A=fopen("b.txt", "w");
print(A, mas, N);
fclose(A);
return 0;
}