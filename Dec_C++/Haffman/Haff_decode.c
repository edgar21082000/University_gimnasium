#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Haff{
	struct Haff* left;
	struct Haff* right;
	char letter;
};

struct Haff* add_letter(struct Haff* root, char* bin, char let, int j, int k);
struct Haff* search_letter(struct Haff* root, char bit);

int main(){
	FILE *A0; A0=fopen("out.txt", "r");
	FILE *B; B=fopen("decod.txt", "w");
	
	struct Haff* root;
	root=(struct Haff*)malloc(sizeof(struct Haff));
	root->left=NULL;
	root->right=NULL;
	
	char* bin; bin=(char *)malloc(32*sizeof(char));
	char let;
	int i, j, k;
	
	struct Haff* begin; begin=(struct Haff*)malloc(sizeof(struct Haff));
	begin=root;
	
	while(fscanf(A0, "%s", &let)==1){
		fscanf(A0, "%s", bin);
		k=strlen(bin);
		j=0;
		root=add_letter(root, bin, let, j, k);
		root=begin;
		//printf("\n"); // часть проверка ф-ции add_letter;
	}
	fclose(A0);
	
	FILE *A; A=fopen("cod.txt", "r");
	char bit;
	
	while(fscanf(A, "%c", &bit)==1){
		//printf("%c", bit); // Проверка считывания
		root=search_letter(root, bit);
		if(root->left==NULL && root->right==NULL){
			//printf("%c+\n", root->letter); // Проверка поиска
			fprintf(B, "%c", root->letter);
			root=begin;
		}
	}
	fclose(A);
	fclose(B);
	
	return 0;	
}

struct Haff* add_letter(struct Haff* root, char* bin, char let, int j, int k){
	if(k==1){                     //Выход из рекурсии
		if(bin[j]=='1'){
			//printf("1"); // Проверка пути
			root->left=(struct Haff*)malloc(sizeof(struct Haff));
			root->left->left=NULL;
			root->left->right=NULL;
			root->left->letter=let;
			//printf("%c ", root->left->letter); // Проверка пути
			return root->left;
		}
		
		if(bin[j]=='0'){
			//printf("0"); // Проверка пути
			root->right=(struct Haff*)malloc(sizeof(struct Haff));
			root->right->left=NULL;
			root->right->right=NULL;
			root->right->letter=let;
		    //printf("%c ", root->right->letter); // Проверка пути
			return root->right;
		}
	}
	
	//-------------------------------------------------------------
	
	if(bin[j]=='1'){
		if(root->left==NULL){
			//printf("1"); // Проверка пути
			root->left=(struct Haff*)malloc(sizeof(struct Haff));
			root->left->left=NULL;
			root->left->right=NULL;
			root=add_letter(root->left, bin, let, j+1, k-1);
			return root;
		}
		else{
			//printf("1"); // Проверка пути
			root=add_letter(root->left, bin, let, j+1, k-1);
			return root;
		}
	}
	
	if(bin[j]=='0'){
		if(root->right==NULL){
			//printf("0"); //Проверка пути
			root->right=(struct Haff*)malloc(sizeof(struct Haff));
			root->right->left=NULL;
			root->right->right=NULL;
			root=add_letter(root->right, bin, let, j+1, k-1);
			return root;
		}
		else{
			//printf("0"); // Проверка пути
			root=add_letter(root->right, bin, let, j+1, k-1);
			return root;
		}
	}
}

struct Haff* search_letter(struct Haff* root, char bit){
	if(root->left==NULL && root->right==NULL) return root;
	
	if(bit=='1') return root->left;
	if(bit=='0') return root->right;
}
