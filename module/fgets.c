#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main(void)
{
	char str[512];
	char mas[11];
	int i=0, j=0;
	
	
	while(fgets(str, 512, stdin)!=NULL)
	{
		while(str[i]!='\0')
		{
			if (str[i]>='0' && str[i]<='9')
			{
				mas[j]=str[i];
				if (mas[0]=='0')
				{
					i++;
					continue;
				}
				j++;
				if (j>10)
				{
					printf("\n\n\n");
					printf("Неадекватный телефон");
					exit(1);
				}
			}
			i++;
		}
		if (j<10)
		{
			printf("\n\n\n");
			printf("Неадекватный телефон");
			exit(1);
		}
	}
	printf("\n\n\n");
	
	fprintf(stdout, "%s", mas);
	/*fputs(mas, stdout);*/
	/*printf("%s", mas);*/
	return 0;
}

