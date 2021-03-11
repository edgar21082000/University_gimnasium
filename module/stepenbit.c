#include <stdio.h>

void prn_bit(char);
void zap_bit(char, int *);

int main(void)
{
	unsigned int N=27; int i;
	double x=2.07;
	int mas[32]; 
    unsigned char mask=1;
	char *c;
	c=(char *)(&N);
	printf("N = ");
    for (i=0;i<4;i++)
	{
		prn_bit(*c);
		zap_bit(*c, mas);
		c=c+1;
	}	
    for	(i=0;i<32;i++)printf("%d", mas [i]);
	return 0;
}


void prn_bit(char a)
{
	unsigned char read = 1;
	while(1)
	{
		if(a&read){printf("1");}
		else{printf("0");}
		if (read==128)break;
		read=read<<1;
	}	
	printf(" ");
}
void zap_bit(char a, int *mas)
{
	unsigned read = 1; int j=0; int tmp;
	while(1)
	{
		if(a&read){mas[j+tmp]=1;}
		else{mas[j]=0;}
		if (read==128)break;
		j++;
		tmp=j;
		read=read<<1;
	}
}
