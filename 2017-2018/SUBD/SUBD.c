#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct book{
	char name[20];
	char surname[20];
	char tel_num[12];
	char email[64];
};

void print(struct book *, int);
void add_new(struct book *, int);
int search(struct book *, int);
int delete(struct book *, int);
void sort(struct book *, int);

int main(){
	
	int i, k;
	
	struct book *N1; N1=(struct book *)malloc(128*sizeof(struct book));
	FILE *R; FILE *W; FILE *SO; FILE *SC;
	R=fopen("out.txt","rb"); SO=fopen("size.txt","r");
	fscanf(SO, "%d", &k);
	fread(N1, sizeof(struct book), k, R);
	for(i=0;i<k;i++) printf("%3d:%13s %10s %12s %30s\n",i+1, (N1[i].name), (N1[i].surname), (N1[i].tel_num), (N1[i].email));
	fclose(R); fclose(SO);

	int key;
	while(1){
		printf("--------------MENU--------------\n");
		printf("-1 -- Завершение программы\n");
		printf(" 0 -- Распечатать БД\n");
		printf(" 1 -- Добавить номер\n");
		printf(" 2 -- Удалить номер\n");
		printf(" 3 -- Отсортировать по имени/телефону/email\n");
		printf(" 4 -- Найти по имени/телефону/email\n");
		
		scanf("%d", &key);
		
		if(key==-1){
			W=fopen("out.txt","wb");
			fwrite(N1, sizeof(struct book), k, W);
			fclose(W);
			SC=fopen("size.txt", "w");
			fprintf(SC, "%d", k);
			fclose(SC);
			printf("До свидания!");
			exit(1);
		}
		
		if(key==0) print(N1, k); 
		
		if(key==1){ 
			add_new(N1, k);
			printf("%s %s %s %s-\n", (N1[k].name), (N1[k].surname), (N1[k].tel_num), (N1[k].email));
			k++;
		}
		
		if(key==2) k=delete(N1, k);
		if(key==3) sort(N1, k);
		
		if(key==4){
			key=search(N1, k);
			printf("Запрос: ");
			printf("%s %s %s %s\n",(N1[key].name), (N1[key].surname), (N1[key].tel_num), (N1[key].email));
		}
		
		
	}
	return 0;
}

void print(struct book *K, int d){
	int i;
	for(i=0;i<d;i++) printf("%3d:%13s %10s %12s %30s\n",i+1, (K[i].name), (K[i].surname), (K[i].tel_num), (K[i].email));
}

void add_new(struct book *K, int d){
	printf("Введите: имя фамилию номер email\n");
	scanf("%s %s %s %s", &(K[d].name), &(K[d].surname), &(K[d].tel_num), &(K[d].email));
	return ;
}

int search(struct book *K, int d){
	int key, i; char tmp1[64]; char tmp2[64];
	printf("Выберите тип поиска\n1-по имени фамилии\n2-по телефону\n3-по email\n");
	scanf("%d", &key);
	if(key==1){
		printf("Введите имя фамилию:");
		scanf("%s %s", &tmp1, &tmp2);
		for(i=0;i<d;i++){ if( (strcmp(tmp1, K[i].name)==0) && (strcmp(tmp2, K[i].surname)==0)) return i;}
		printf("Таких данных нет!!!\n");
		return -1;
	}
	
	if(key==2){
		printf("Введите телефон:");
		scanf("%s", &tmp1);
		for(i=0;i<d;i++){if(strcmp(tmp1, K[i].tel_num)==0) return i;}
		printf("Таких данных нет!!!\n");
		return -1;
	}
	
	if(key==3){
		printf("Введите email:");
		scanf("%s", &tmp1);
		for(i=0;i<d;i++){if(strcmp(tmp1, K[i].email)==0) return i;}
		printf("Таких данных нет!!!\n");
		return -1;
	}
}

int delete(struct book *K, int d){
	int i, key;
	key=search(K, d);
	for(i=key;i<d;i++){
		strcpy(K[i].name, K[i+1].name);
		strcpy(K[i].surname, K[i+1].surname);
		strcpy(K[i].tel_num, K[i+1].tel_num);
		strcpy(K[i].email, K[i+1].email);
	}
	d--;
	return d;
}

void sort(struct book *K, int d){
	int i, j; char tmp1[64]; char tmp2[64]; int key;
	printf("Выберите тип сортировки:\n1-по имени фамилии\n2-по телефону\n3-по email\n");
	scanf("%d", &key);
	
	if(key==1){
		for(i=0;i<d-1;i++){
			for(j=0;j<d-1-i;j++){
				if(strcmp(K[j].name, K[j+1].name)>0){
					strcpy(tmp1, K[j+1].name);
					strcpy(K[j+1].name, K[j].name);
					strcpy(K[j].name, tmp1);
					
					strcpy(tmp1, K[j+1].surname);
					strcpy(K[j+1].surname, K[j].surname);
					strcpy(K[j].surname, tmp1);
					
					strcpy(tmp1, K[j+1].tel_num);
					strcpy(K[j+1].tel_num, K[j].tel_num);
					strcpy(K[j].tel_num, tmp1);
					
					strcpy(tmp1, K[j+1].email);
					strcpy(K[j+1].email, K[j].email);
					strcpy(K[j].email, tmp1);
				}
			}
		}
	}
	
	if(key==2){
		for(i=0;i<d-1;i++){
			for(j=0;j<d-1-i;j++){
				if(strcmp(K[j].tel_num, K[j+1].tel_num)>0){
					strcpy(tmp1, K[j+1].name);
					strcpy(K[j+1].name, K[j].name);
					strcpy(K[j].name, tmp1);
					
					strcpy(tmp1, K[j+1].surname);
					strcpy(K[j+1].surname, K[j].surname);
					strcpy(K[j].surname, tmp1);
					
					strcpy(tmp1, K[j+1].tel_num);
					strcpy(K[j+1].tel_num, K[j].tel_num);
					strcpy(K[j].tel_num, tmp1);
					
					strcpy(tmp1, K[j+1].email);
					strcpy(K[j+1].email, K[j].email);
					strcpy(K[j].email, tmp1);
				}
			}
		}
	}
	
	if(key==3){
		for(i=0;i<d-1;i++){
			for(j=0;j<d-1-i;j++){
				if(strcmp(K[j].email, K[j+1].email)>0){
					strcpy(tmp1, K[j+1].name);
					strcpy(K[j+1].name, K[j].name);
					strcpy(K[j].name, tmp1);
					
					strcpy(tmp1, K[j+1].surname);
					strcpy(K[j+1].surname, K[j].surname);
					strcpy(K[j].surname, tmp1);
					
					strcpy(tmp1, K[j+1].tel_num);
					strcpy(K[j+1].tel_num, K[j].tel_num);
					strcpy(K[j].tel_num, tmp1);
					
					strcpy(tmp1, K[j+1].email);
					strcpy(K[j+1].email, K[j].email);
					strcpy(K[j].email, tmp1);
				}
			}
		}
	}
	
	return ;
}
