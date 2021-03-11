#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double* gauss(double *x, double *a, double *b, int N);
void t_print(double *a, double *b, int N);
void max_replace(double *a, double *b, int N, int i);
double mod(double x);

int main(){
	FILE *A; A=fopen("in_a.txt", "r");
	FILE *B; B=fopen("in_b.txt", "r");
	
	srand(time(NULL));
	
	int i, j, N;
	fscanf(A, "%d", &N); 
	
	double *a; a=(double *)malloc(N*N*sizeof(double));
	double *b; b=(double *)malloc(N*sizeof(double));
	
	for(i=0;i<N;i++) for(j=0;j<N;j++) fscanf(A, "%lf", &a[i*N+j]);
	for(i=0;i<N;i++) fscanf(B, "%lf", &b[i]);
	
	double *x; x=(double *)malloc(N*sizeof(double));		
	
	t_print(a, b, N);
	
	x = gauss(x, a, b, N);
	
	printf("\n\n");
	for(i=0;i<N;i++) printf("%lf ", x[i]);
		
	
	return 0;
}

double* gauss(double *x, double *a, double *b, int N){
	int i, j , k, m;
	double first;
	
	for(i=0;i<N;i++){ // Прямой проход
		
		max_replace(a, b, N, i); 
		t_print(a, b,  N);
		system("pause");
		
		for(j=i;j<N;j++){
			
			if(a[j*N+i]==0) first=1;
			else first=a[j*N+i];
			
			
			for(k=0;k<N-i;k++){ // Одновременная нормировка всего столбца
				a[j*N+i+k] /= first;
			}
			b[j]/= first;
			t_print(a, b,  N);
			system("pause");
		}
		
		//printf("\nstart\n");
		
		for(m=i+1;m<N;m++){// Вычитание
		
			if(a[m*N+i]==0) continue;
			
			for(k=0;k<N-i;k++){
				a[m*N+i+k]-=a[i*N+i+k];
				t_print(a, b,  N);
				system("pause");
			}
			b[m]-=b[i];
		}
		
		printf("yes\n");
		system("pause");
	}
	
	//printf("yes\n");
	//system("pause");
	
	
	
	for(i=N-1;i>=0;i--){// Обратный ход
		x[i]=b[i];
		if(i==0) break;
		for(j=N-1;j>=i;j--){
			b[i-1]=b[i-1]-a[(i-1)*N+j]*x[j];
		}
	}
	
	//t_print(a, b,  N);
	//system("pause");
	
	
	
	return x;
}

void t_print(double *a,  double *b,  int N){
	int i, j;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			printf("%lf ", a[i*N+j]);
		}
		printf("= %lf\n", b[i]);
	}
}

void max_replace(double *a, double *b, int N, int i){
	int k, j;
	double max = mod(a[i*N+i]);
	int tmp = 0;
	//printf("\n i = %d \n", i);
	
	for(k=i+1;k<N;k++){ //поиск максимальной строчки
		if(mod(a[k*N+i]) > max){
			max=mod(a[k*N+i]);
			tmp=k; //printf("\n tmp = %d\n\n", tmp);
		}
	}
	
	if(tmp==0) return;
	
	double t;
	for(j=i;j<N;j++){//перестановка
		t=a[i*N+j];
		a[i*N+j]=a[tmp*N+j];
		a[tmp*N+j]=t;
	}
	
	t=b[i];
	b[i]=b[tmp];
	b[tmp]=t;
	
	//printf("\n\nreplace yes\n\n");
	
	return;
}

double mod(double x){
	if(x>=0) return x;
	else return -1*x;
}
