#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i;
	int a1=1, a2=1, a, n; //n>2
	scanf("%d", &n);
	if(n<3)
	{
		printf("1");
		exit (1);
	}
	for (i=0;i<n-2;i++)
	{
		a=a1+a2;
		a1=a2;
		a2=a;
	}
	printf("%d", a);
	return 0;
}