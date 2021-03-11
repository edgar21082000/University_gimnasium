#include<stdio.h>
#include<stdlib.h>
#include"Tr.h"


int main()
{
	struct Tr * root = NULL;
	struct Tr * tmp;
	int v;
	FILE * in;


	in = fopen("in.data","r");
	if(in==NULL){exit(0);}
	while(fscanf(in,"%d",&v)==1){
		tmp = Tr_Add(v,root);
		if(tmp!=NULL)root=tmp;
	}

	Tr_Prn(root);
	res(root, 4);
	return 0;
}
