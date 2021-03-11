#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char tmp[100];
int i;
int key=0;

int main()
{
	FILE *A, *B;
	A=fopen("1.txt", "r");
	B=fopen("2.txt", "w");

	while((fscanf(A, "%s", &tmp)==1))
	{
		if ((tmp[0]>='a' && tmp[0]<='z')) fprintf(B, "%s_", tmp);

		if (tmp[0]=='-') fprintf(B, "\n");




	}
	return 0;
}