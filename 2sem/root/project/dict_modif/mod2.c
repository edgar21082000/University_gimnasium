#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct L1 
{
	char word[30];
	char w_trigramme[1024];
	struct L1 *next;
};

int main()
{
	FILE *A; A=fopen("modification.txt", "r");
	FILE *B; B=fopen("modification2.txt", "w");
	
	fseek(A, 0, SEEK_END);
	long int size = ftell(A);
	rewind(A);
	
	char *buffer = (char *)malloc(sizeof(char)*size);
	
	size_t result = fread(buffer, 1, size, A);
	if (result!=size)
	{
		printf("error");
		exit (1);
	}
	
	fwrite(buffer, 1, size, B);
	
	return 0;
}