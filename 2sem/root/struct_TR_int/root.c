#include <stdio.h>
#include <stdlib.h>

struct TR{
	int word;
	struct TR * right;
	struct TR * left;
};

 int tmp;
 int i, j, s;
 int begin=0;

 void TR_add(struct TR *, int);
 void TR_prn_infics(FILE *, struct TR *);
 void TR_prn_level(struct TR *, int);
 void TR_prn_root(struct TR *, int);
 int  TR_depth(struct TR *, int);
 int  max(int, int);
 struct TR * TR_find(struct TR *, int);
 
int main()
{
	int level, depth; int depth_0=0;
	FILE *A;  FILE *P2; 
	A=fopen("in", "r");
	P2=fopen("kr2", "w");
	
	struct TR *root, *pop;
	root==NULL;
	
	while(fscanf(A, "%d", &tmp)==1)
	{
		if (root==NULL)
		{
			root=(struct TR *)malloc(sizeof(struct TR));
			root->word=tmp;
			root->right=NULL;
			root->left=NULL;
		}
		else TR_add(root, tmp);
	}
	
	depth=TR_depth(root, depth_0);
	printf("Глубина дерева = %d\n\n", depth);
	
	TR_prn_infics(P2, root);
	TR_prn_root(root, depth);
	
	scanf("%d", &s);
	pop=TR_find(root, s);
	if (pop!=NULL) printf("%d", pop->word);
	else printf("net");
	
	return 0;
}

void TR_add(struct TR *cur, int k)
{
	 if (cur->word==k) return;
	 
	 if (cur->word>k)
	 {
		 if (cur->left==NULL)
		 {
			 cur->left=(struct TR *)malloc(sizeof(struct TR));
			 cur->left->word=k;
			 cur->left->right=NULL;
			 cur->left->left=NULL;
			 return ;
		 }
		 else 
		 {
			 TR_add(cur->left, k);
		 }
	 }
	 
	 if (cur->word<k)
	 {
		 if (cur->right==NULL)
		 {
			 cur->right=(struct TR *)malloc(sizeof(struct TR));
			 cur->right->word=k;
			 cur->right->right=NULL;
			 cur->right->left=NULL;
			 return ;
		 }
		 else 
		 {
			 TR_add(cur->right, k);
		 }
	 }
	 
 }
 
void TR_prn_infics(FILE *B, struct TR *cur) // печать по алфавиту
{
	if (cur==NULL) return;
	TR_prn_infics(B, cur->left);
	fprintf (B, "%d\n", cur->word);
	TR_prn_infics(B, cur->right);
}

void TR_prn_level(struct TR *cur, int level) // печать одного уровня
{
	if (begin==level) printf("%d  ", cur->word);
	
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

struct TR * TR_find(struct TR *cur, int x)
{
	struct TR *p=cur;
	while(1)
	{
		if (p==NULL) return NULL;
		if (x<p->word) p=p->left;
		else if (x>p->word) p=p->right;
		else return p;
	}
}
