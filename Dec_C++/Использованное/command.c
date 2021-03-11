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
	scanf("%d %d %d %d", &a, &out, &k, &l);
	
	struct root *N;
	N=(struct root *)malloc(sizeof(struct root));
	N->val=a;
	N->left=NULL;
	N->right=NULL;
	
	create(N, out, k, l);
}

void create(struct root *N, int out, int k, int l){
	if ((N->val)==out) return;
	
	if ((N->val)%k==0){
		N->left=(struct root *)malloc(sizeof(struct root));
		N->left->val=(N->val)/k;
		N->left->left=NULL;
		N->left->right=NULL;
		create(N->left, out, k, l);
	}
	
	N->right=(struct root *)malloc(sizeof(struct root));
	N->right->val=(N->val)-l;
	N->right->left=NULL;
	N->left->right=NULL;
	
	
	create(N->right, out, k, l);
}
	
	
	

