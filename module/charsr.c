#include <stdio.h>
#include <stdlib.h>

void zap(char *);
void compaire(char *, char *, int, int, int); 
int str_len(char *);


const int N = 1000;

int main(void)
{
	char *a, *b, dl_a, dl_b, k;
	a=(char *)malloc(N*sizeof(char));
	b=(char *)malloc(N*sizeof(char));
	zap(a);
	zap(b);
	dl_a=str_len(a);
	dl_b=str_len(b);
	if (dl_a>=dl_b)
	{
		k=dl_b;
	}
	if (dl_a<dl_b)
	{
		k=dl_a;
	}
	compaire( a, b, k, dl_a, dl_b);
	return 0;
}

void zap(char *p)
{
	scanf("%s", p);
}
void compaire(char *p, char *q, int r, int s, int t)
{
	int i=0;
	while(i<=r)
	{
		if (s!=t)
		{
			if (i>r && s>t)printf("-1");
			if (i>r && s<t)printf("1");
			if (p[i]==q[i])
			{
				i++;
				continue;
			}
			if (p[i]>q[i]){printf("2 раньше");exit(1);}
			else{printf("1 раньше");exit(1);}
		}
		else
		{
			if (p[i]==q[i])
			{
				i++;
				if (i>s)
				{
					printf("равны");
					exit(1);
				}
				continue;
			}
			if (p[i]>q[i]){printf("2 раньше");exit(1);}
			else{printf("1 раньше");exit(1);}
		}
	}
	
} 

int str_len(char *p)
{
	int q=0;
	while (p[q]!='\0')q++;
	return q;
}
