#include <stdio.h>
#include <stdlib.h>

struct Haff{
	struct Haff *left;
	struct Haff *right;
	int poss;
	int bit;
	char letter;
};

int alpha_min(struct Haff** alpha, int size);
int alpha_min_2(struct Haff** alpha, int size, int min_index);
struct Haff** redact(struct Haff** alpha, struct Haff* par, int size, int min_index, int min_index_2);
struct Haff** create(struct Haff** alpha, int alpha_size, int min_index, int min_index_2, int STOP);
void print(struct Haff* root, int* bin, int end, FILE *B);
void bin_code_init(struct Haff* root);


int main(){
	
	FILE *A; A=fopen("in.txt", "r");
	FILE *B; B=fopen("out.txt", "w");
	
	int i, j; int alpha_size = 0;
	char tmp;
	
	int mas[26]; for(i=0;i<26;i++) mas[i]=0;
	while(fscanf(A, "%c", &tmp)==1) mas[tmp-97]++;
	for(i=0;i<26;i++) if(mas[i]!=0) alpha_size++; 
	 
	struct Haff **alpha; alpha=(struct Haff **)malloc(alpha_size*sizeof(struct Haff*));
	for(i=0;i<alpha_size;i++) {
		alpha[i]=(struct Haff *)malloc(sizeof(struct Haff));
		alpha[i]->left=NULL;
		alpha[i]->right=NULL;
	}
	
	char* let; let=(char *)malloc(alpha_size*sizeof(char));
	int* buf; buf=(int *)malloc(alpha_size*sizeof(int)); // Массив дубликат частоты повторений буквы.
	for(i=0;i<alpha_size;i++) buf[i]=0; 
	
	j=0;
	int STOP=0;
	for(i=0;i<26;i++){
		if(mas[i]!=0){
			buf[j]=mas[i];
			let[j]=97+i;
			alpha[j]->poss=mas[i];
			alpha[j]->letter=let[j];
			STOP+=mas[i];
			j++;
		}
	}
	
	//for(i=0;i<alpha_size;i++) fprintf(B, "%c- %d\n", let[i], alpha[i]->poss); // Просмотр алфавита
	
	int min_index = alpha_min(alpha, alpha_size);  
	int min_index_2 = alpha_min_2(alpha, alpha_size, min_index);

	//printf("\n min - %d / min_2 - %d/n", min_index, min_index_2); 
	//for(i=0; i<alpha_size; i++) printf("%d ", alpha[i]->poss); printf("\n"); // Проверка массива
	
	alpha = create(alpha, alpha_size, min_index, min_index_2, STOP);
	bin_code_init(alpha[0]);
	
	int* bin; bin=(int *)malloc(32*sizeof(int)); int end=0; // Массивчик с кодами
	
	print(alpha[0], bin, end, B); // ИТОГ
	
	
	return 0;
}

int alpha_min(struct Haff** alpha, int size){
	int min_index; int i = 0;
	min_index = i;
	for(i=1;i<size;i++) if( alpha[i]->poss < alpha[min_index]->poss) min_index = i;
	return min_index;
}

int alpha_min_2(struct Haff** alpha, int size, int min_index){
	int min_index_2; int i = 0;
	if(min_index!=i) min_index_2 = i; 
	else min_index_2 = 1;
	
	for(i=1;i<size;i++){
		if(i==min_index) continue;
		if(alpha[i]->poss < alpha[min_index_2]->poss) min_index_2 = i;
	}
	return min_index_2;
}

struct Haff** redact(struct Haff** alpha, struct Haff* par, int size, int min_index, int min_index_2){
	int i;
	for(i=min_index;i<size-1;i++) alpha[i]=alpha[i+1];
	if(min_index<min_index_2) min_index_2--;
	for(i=min_index_2;i<size-2;i++) alpha[i]=alpha[i+1];

	alpha[size-2]=par;
	return alpha;
}

struct Haff** create(struct Haff** alpha, int alpha_size, int min_index, int min_index_2, int STOP){
	if(alpha[0]->poss==STOP) return alpha;
	int i;
	
	//for(i=0; i<alpha_size; i++) printf("%d ", alpha[i]->poss); printf("\n"); //Проверка - печать массива
	
	struct Haff* par; par=(struct Haff*)malloc(sizeof(struct Haff));
	
	par->left=(struct Haff*)malloc(sizeof(struct Haff));
	par->left=alpha[min_index];
	
	par->right=(struct Haff*)malloc(sizeof(struct Haff));
	par->right=alpha[min_index_2];
	
	par->poss = par->left->poss + par->right->poss;

	alpha = redact(alpha, par, alpha_size, min_index, min_index_2);
	alpha_size--;
	
	min_index=alpha_min(alpha, alpha_size);
	min_index_2=alpha_min_2(alpha, alpha_size, min_index);
	//system("pause");
	alpha = create(alpha, alpha_size, min_index, min_index_2, STOP);
	return alpha;
}

void print(struct Haff* root, int* bin, int end, FILE *B){
	if(root==NULL) return; 
	bin[end]=root->bit;
	
	if(root->left==NULL){
		int i;
		fprintf(B, "%c ", root->letter);
		for(i=1;i<=end;i++) fprintf(B, "%d", bin[i]);
		fprintf(B, "\n");
		return;
	}
	print(root->left, bin, end+1, B);
	print(root->right, bin, end+1, B);
}

void bin_code_init(struct Haff* root){
	if(root->left==NULL) return;
	else{
		root->left->bit = 1;
		bin_code_init(root->left);
	}
	
	if(root->right==NULL) return;
	else{
		root->right->bit = 0;
		bin_code_init(root->right);
	}
}


