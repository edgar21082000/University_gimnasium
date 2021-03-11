#include <stdio.h>
#include <stdio.h>
#include <math.h>

double* gauss(double *x, double *a, double *b, int N);
void t_print(double *a, double *b, int N);
void max_replace(double *a, double *b, int N, int i);
double mod(double x);

double f(double);
double U(double);
void prn(double *, int, FILE *);

void create_matr(double *a, double *b, int N);

double pi = 4*atan(1.);

int main(){
	FILE *A; A=fopen("teplo.txt", "w");
	FILE *B; B=fopen("ans.txt", "w");
	
	int i;
	int N=1000;
	double h = pi/(N-1);
	
	double *V; V=(double *)malloc(N*sizeof(double));
	double *a; a=(double *)malloc(N*N*sizeof(double));
	double *b; b=(double *)malloc(N*sizeof(double));
	
	create_matr(a, b, N);
	//t_print(a, b, N);
	system("pause");
	gauss(V, a, b, N);
	
	double x=0.;
	for(i=0;i<N;i++){
		fprintf(B, "%lf %lf %lf %lf\n", x, U(x), V[i], U(x)-V[i]);
		x+=h;
	}
	
	for(i=0;i<N;i++) printf("%lf ", V[i]);
	
	//prn(V, N, A);
	fclose(A); 
	fclose(B);
	
	return 1;
	
}

double* gauss(double *x, double *a, double *b, int N){
	int i, j , k, m;
	double first;
	
	for(i=0;i<N;i++){ // Прямой проход
		
		max_replace(a, b, N, i); 
		//t_print(a, b,  N);
		//system("pause");
		
		for(j=i;j<N;j++){
			
			if(a[j*N+i]==0) first=1;
			else first=a[j*N+i];
			
			
			for(k=0;k<N-i;k++){ // Одновременная нормировка всего столбца
				a[j*N+i+k] /= first;
			}
			b[j]/= first;
			//t_print(a, b,  N);
			//system("pause");
		}
		
		//printf("\nstart\n");
		
		for(m=i+1;m<N;m++){// Вычитание
		
			if(a[m*N+i]==0) continue;
			
			for(k=0;k<N-i;k++){
				a[m*N+i+k]-=a[i*N+i+k];
				//t_print(a, b,  N);
				//system("pause");
			}
			b[m]-=b[i];
		}
		
		//printf("yes\n");
		//system("pause");
	}
	
	//printf("dszdzdzzdzsz\n");
	//system("pause");
	
	
	
	for(i=N-1;i>=0;i--){
		x[i]=b[i];
		if(i==0) break;
		for(j=N-1;j>=i;j--){
			b[i-1]=b[i-1]-a[(i-1)*N+j]*x[j];
		}
	}
	
	//printf("dszVXFDGHDGHJHSDGRZSDGHFGHGZdzsz\n");	
	
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


void prn(double *V, int N, FILE *A){
	int i;
	double x=0.;
	double h=pi/N;
	for(i=0;i<=N;i++){
		fprintf(A, "%lf %lf %lf %e\n", x, V[i], U(x), U(x)-V[i]);
		x+=h;
	}
	return;
}

double f(double x){
	return sin(x);
}

double U(double x){
	return (-1)*sin(x)+(x/pi);
}

void create_matr(double *a, double *b, int N){
	int i;
	double x=0.;
	double h=pi/(N-1);
	
	a[0]=1; for(i=1;i<N;i++) a[i]=0;
	a[N*N-1]=1; for(i=0;i<N-1;i++) a[N*(N-1)+i]=0;
	b[0]=0;
	b[N-1]=1;
	
	for(i=1;i<N-1;i++){
		a[i*N+i-1]=1/(h*h);
		a[i*N+i]=-2/(h*h);
		a[i*N+i+1]=1/(h*h);
		b[i]=f(x+h);
		x+=h;
	}
	return;
}



