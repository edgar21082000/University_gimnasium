#include <stdio.h>
#include <stdlib.h>


struct TR2{
	int val;
	int level;
	struct TR2 *left;
	struct TR2 *right;
};

int tmp; int begin=0; int i, j;

 void TR_add(struct TR2 *, int, int);
 void TR_prn_level(struct TR2 *, int);
 void TR_prn_root(struct TR2 *, int);
 int  TR_depth(struct TR2 *, int);
 int max(int , int );

 int main()
{
	int depth=0; int depth_0=0;
	FILE *A;
	A=fopen("TR2-in", "r");

	struct TR2 *root;
	root==NULL;

	
	while(fscanf(A, "%d", &tmp)==1)
	{
		if (root==NULL)
		{
			root=(struct TR2 *)malloc(sizeof(struct TR2));
			root->val=tmp;
			root->right=NULL;
			root->left=NULL;
			root->level=0;
		}
		else TR_add(root, tmp, root->level);
	}
	
	
	depth=TR_depth(root, depth_0);
	printf("Глубина дерева = %d\n\n", depth);
	
	TR_prn_root(root, depth);
	
	return 0;
}

void TR_add(struct TR2 *cur, int k, int levcur)
{
	if (cur->val==k) return;
	 
	if (cur->val>k)
	{
		if (cur->left==NULL)
		{
			cur->left=(struct TR2 *)malloc(sizeof(struct TR2));
			cur->left->val=k;
			levcur++;
			cur->left->level=levcur;
			cur->left->right=NULL;
			cur->left->left=NULL;
			return ;
		}
		else 
		{
			TR_add(cur->left, k, levcur+1);
		}
	}
	 
	if (cur->val<k)
	{
		if (cur->right==NULL)
		{
			cur->right=(struct TR2 *)malloc(sizeof(struct TR2));
			cur->right->val=k;
			levcur++;
			cur->right->level=levcur;
			cur->right->right=NULL;
			cur->right->left=NULL;
			return ;
		}
		else 
		{
			TR_add(cur->right, k, levcur+1);
		}
	}
}
 
 void TR_prn_level(struct TR2 *cur, int lev) // печать одного уровня
{
	if (begin==lev) printf("%d'%d'  ", cur->val, cur->level);
	
	if (cur->left!=NULL)
	{
		begin++;
		TR_prn_level(cur->left, lev);
		begin--;
	}
	
	if (cur->right!=NULL)
	{
		begin++;
		TR_prn_level(cur->right, lev);
		begin--;
	}
}

int TR_depth(struct TR2 *cur, int a) // глубина дерева
{
	if (cur==NULL) return a;
	return max(TR_depth(cur->left, a+1), TR_depth(cur->right, a+1));
}

int max(int a, int b)
{
	if (a>=b) return a;
	else return b;
}

void TR_prn_root(struct TR2 *cur, int glub)
{
	for (j=0;j<glub;j++)
	{
		TR_prn_level(cur, j);
		printf("\n");
	}
	printf("\n");
}
