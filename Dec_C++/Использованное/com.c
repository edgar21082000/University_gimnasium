#include <stdio.h>
#include <stdlib.h>

struct root{
	int val;
	struct root *left;
	struct root *right;
};

void create(struct root *, int, int, int);

int main(){
	int a, out, k, l;
	scanf("%d", &a); scanf("%d", &out); scanf("%d", &k); scanf("%d", &l);
	
	struct root *N;
	N=(struct root *)malloc(sizeof(struct root)); if(N==NULL) printf("daun");
	N->val=a;
	N->left=NULL;
	N->right=NULL;
	create(N, out, k, l);
	
	return 0;
}

void create(struct root *N, int out, int k, int l){
	if ((N->val)==out) return;
	
	
	if ((N->val)%k==0){
		N->left=(struct root *)malloc(sizeof(struct root)); //if(N->left==NULL) printf("lox"); else printf("daun");
		N->left->val=(N->val)/k; 
		N->left->left=NULL;
		N->left->right=NULL; 
		create(N->left, out, k, l);
	}
	
	N->right=(struct root *)malloc(sizeof(struct root));
	N->right->val=(N->val)-l;
	N->right->left=NULL;
	N->right->right=NULL;
	
	create(N->right, out, k, l); printf("right\n");
}