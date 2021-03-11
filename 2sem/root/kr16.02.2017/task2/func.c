#include<stdio.h>
#include<stdlib.h>
#include"Tr.h"

int kol=0;

void Tr_sc(struct Tr *);
void res(struct Tr *);
void Tr_kol();

void Tr_sc(struct Tr *cur)
{
	if (cur==NULL) return;
	if (cur->left==NULL && cur->right==NULL) kol++;
	else 
	{
		Tr_sc(cur->left);
		Tr_sc(cur->right);
	}
}

void Tr_kol()
{
	printf("/%d/", kol);
}

void res(struct Tr *cur)
{
	Tr_sc(cur);
	Tr_kol();
}




