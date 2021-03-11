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
	A=fopen("in_1", "r");
	P1=fopen("out_1", "w");
	P2=fopen("out_2", "w");

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
	
	TR_prn_prefics(P1, root);
	TR_prn_infics(P2, root);
	
	fclose(A);fclose(P1);fclose(P2);
	
	depth=TR_depth(root, depth_0);
	printf("Глубина дерева = %d\n\n", depth);
	
	TR_prn_root(root, depth);
	
	while(1)          // печать любого существующего уровня
	{ 
		printf("Введите номер уровня, который хотите распечатать (-1 -- выход из программы) :");
		scanf("%d", &level);
		if (level==-1) break;
		if (level<depth){ TR_prn_level(root, level); printf("\n\n");}
		else printf("\nERROR: Дерево - меньшей глубины\n\n");
	}
	
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
 
void TR_prn_prefics(FILE *B, struct TR *cur) // печать, опускаясь влево конца...
{
	if (cur==NULL) return;
	fprintf (B, "%s\n", cur->word);
	TR_prn_prefics(B, cur->left);
	TR_prn_prefics(B, cur->right);
}

void TR_prn_infics(FILE *B, struct TR *cur) // печать по алфавиту
{
	if (cur==NULL) return;
	TR_prn_infics(B, cur->left);
	fprintf (B, "%s\n", cur->word);
	TR_prn_infics(B, cur->right);
}

void TR_prn_level(struct TR *cur, int level) // печать одного уровня
{
	if (begin==level) printf("%s  ", cur->word);
	
	if (cur->left!=NULL)
	{
		begin++;
		TR_prn_level(cur->left, level);
		begin--;
	}
	
	if (cur->right!=NULL)
	{
		begin++;
		TR_prn_level(cur->right, level);
		begin--;
	}
}

void TR_prn_root(struct TR *cur, int glub)
{
	for (j=0;j<glub;j++)
	{
		TR_prn_level(cur, j);
		printf("\n");
	}
	printf("\n");
}

int TR_depth(struct TR *cur, int a) // глубина дерева
{
	if (cur==NULL) return a;
	return max(TR_depth(cur->left, a+1), TR_depth(cur->right, a+1));
}	

int max(int a, int b)
{
	if (a>=b) return a;
	else return b;
}





