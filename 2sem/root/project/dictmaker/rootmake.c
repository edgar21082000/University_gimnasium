#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TR{
	char word[20];
	struct TR *right;
	struct TR *left;
};

 char tmp[30];
 int i, j;
 int begin=0;


 void TR_add(struct TR *, char*);
 void TR_prn_prefics(FILE *, struct TR *); 
 void TR_prn_infics(FILE *, struct TR *);
 void TR_prn_level(struct TR *, int);
 void TR_prn_root(struct TR *, int);
 int  TR_depth(struct TR *, int);
 int  max(int, int);

 
int main()
{
	int level, depth; int depth_0=0;
	FILE *A; FILE *P1; FILE *P2; 
	A=fopen("redact2.txt", "r");
	
	P2=fopen("redact3.txt", "w");

	struct TR *root;
	root==NULL;
	
	while(fscanf(A, "%s", &tmp)==1)
	{
		if (root==NULL)
		{
			root=(struct TR *)malloc(sizeof(struct TR));
			stpcpy(root->word, tmp);
			root->right=NULL;
			root->left=NULL;
		}
		else TR_add(root, tmp);
	}
	
	
	TR_prn_infics(P2, root);
	
	fclose(A);fclose(P2);
	
	
	
	return 0;
}

void TR_add(struct TR *cur, char *tmp)
{
	if (strcmp(cur->word, tmp)==0) return;
	
	if (strcmp(cur->word, tmp)>0)
	{
		if (cur->left==NULL)
		{
			cur->left=(struct TR *)malloc(sizeof(struct TR));
			stpcpy(cur->left->word, tmp);
			cur->left->left=NULL;
			cur->left->right=NULL;
		}
		else
		{
			TR_add(cur->left, tmp);
		}
	}
	
	if (strcmp(cur->word, tmp)<0)
	{
		if (cur->right==NULL)
		{
			cur->right=(struct TR *)malloc(sizeof(struct TR));
			stpcpy(cur->right->word, tmp);
			cur->right->left=NULL;
			cur->right->right=NULL;
		}
		else
		{
			TR_add(cur->right, tmp);
		}
	}
	 
}
	
	void TR_prn_infics(FILE *B, struct TR *cur) // печать по алфавиту
{
	if (cur==NULL) return;
	TR_prn_infics(B, cur->left);
	fprintf (B, "%s\n", cur->word);
	TR_prn_infics(B, cur->right);
}