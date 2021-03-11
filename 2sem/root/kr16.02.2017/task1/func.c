#include<stdio.h>
#include<stdlib.h>
#include"Tr.h"

int max=-2147483647; int begin=0;

void TR_func(struct Tr *, int);
void res(struct Tr *cur, int lev);
void Tr_max();
 
 void TR_func(struct Tr *cur, int lev) 
{
	int tmp; 
	if (begin==lev) 
	{
		tmp=cur->val;
		if (tmp>max) {
			max=tmp; 
			}
	}
	
	if (cur->left!=NULL)
	{
		begin++;
		TR_func(cur->left, lev);
		begin--;
	}
	
	if (cur->right!=NULL)
	{
		begin++;
		TR_func(cur->right, lev);
		begin--;
	}
}

void Tr_max()
{
	printf("/%d/", max);
}

void res(struct Tr *cur, int lev)
{
	TR_func(cur,lev);
	Tr_max();
}




