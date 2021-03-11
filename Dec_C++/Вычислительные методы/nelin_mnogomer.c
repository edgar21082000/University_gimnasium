#include <stdio.h>
#include <stdlib.h>
#include <math.h>


double f1(double x1, double x2);
double f2(double x1, double x2);
double df1x1(double x1, double x2);
double df1x2(double x1, double x2);
double df2x1(double x1, double x2);
double df2x2(double x1, double x2);

void create_all_matrix(double *a, double *b, double *x, double *v);

void F(double *b, double *v);
void create_matrix_2(double *a, double *b, double *v, int N);

void gauss(double *x, double *a, double *b, int N);
void max_replace(double *a, double *b, int N, int i);
void t_print(double *a,  double *b,  int N);
double mod(double x);


int main(){
	int N=3;
	double eps=1e-6;
	double *a; a=(double *)malloc(N*N*sizeof(double));
	double *b; b=(double *)malloc(N*sizeof(double));
	double *x; x=(double *)malloc(N*sizeof(double));
	
	double v[3];
	v[0]=0.1;
	v[1]=1.1;
	v[2]=2.1;
	
	/*printf("%lf _ %lf\n", fabs(f1(v[0], v[1])), fabs(f2(v[0], v[1])));
	
	while(fabs(f1(v[0], v[1]))>eps && fabs(f2(v[0], v[1]))>eps){
		create_all_matrix(a, b, x, v);
   		t_print(a, b, N);
		gauss(x, a, b, N);
		
		v[0]+=x[0];
		v[1]+=x[1];
		//printf("%lf _ %lf\n", fabs(f1(v[0], v[1])), fabs(f2(v[0], v[1])));
		//system("pause");
	}
	
	printf("x1 = %lf\nx2 = %lf\n", v[0], v[1]); */
	
	
	//--------------------------------------------------------------------------------------------------------------
	
	double *tmp; tmp=(double *)malloc(N*sizeof(double));   
	F(tmp, v);
	//printf("---------%lf\n", fabs(tmp[0])+fabs(tmp[1])+fabs(tmp[2]));
	
	while(fabs(tmp[0])+fabs(tmp[1])+fabs(tmp[2]) > eps){
		
		create_matrix_2(a, b, v, N);
		t_print(a, b, N);
		gauss(x, a, b, N);
		//printf("%lf %lf %lf\n", x[0], x[1], x[2]);
		
		v[0]-=x[0];
		v[1]-=x[1];
		v[2]-=x[2]; 
		//printf("%lf  %lf  %lf\n", v[0], v[1], v[2]);
		
		F(tmp, v); 
		//printf("---------%lf\n", fabs(tmp[0])+fabs(tmp[1])+fabs(tmp[2]));
		
		
		//system("pause");
	}
	
	printf("x1 = %lf\nx2 = %lf\nx3 = %lf\n", v[0], v[1], v[2]);
	
	return 0;
}

double f1(double x1, double x2){
	return x1*x1+x2*x2-1;
}

double f2(double x1, double x2){
	return x2-x1*x1*x1;
}

double df1x1(double x1, double x2){
	return 2*x1;
}

double df1x2(double x1, double x2){
	return 2*x2;
}

double df2x1(double x1, double x2){
	return -3*x1*x1;
}

double df2x2(double x1, double x2){
	return 1;
}


void create_all_matrix(double *a, double *b, double *x, double *v){
	
	a[0] = df1x1(v[0], v[1]);
	a[1] = df1x2(v[0], v[1]);
	a[2] = df2x1(v[0], v[1]);
	a[3] = df2x2(v[0], v[1]);
	
	b[0] = (-1)*f1(v[0], v[1]);
	b[1] = (-1)*f2(v[0], v[1]);
	return;
}


void gauss(double *x, double *a, double *b, int N){
	int i, j , k, m;
	double first;
	
	for(i=0;i<N;i++){
		
		max_replace(a, b, N, i); 
		
		for(j=i;j<N;j++){
			
			if(a[j*N+i]==0) first=1;
			else first=a[j*N+i];
			
			for(k=0;k<N-i;k++){
				a[j*N+i+k] /= first;
			}
			b[j]/= first;
		}
		
		for(m=i+1;m<N;m++){		
		
			if(a[m*N+i]==0) continue;
				
			for(k=0;k<N-i;k++){
				a[m*N+i+k]-=a[i*N+i+k];
			}
			b[m]-=b[i];
		}
	}

	for(i=N-1;i>=0;i--){
		x[i]=b[i];
		if(i==0) break;
		for(j=N-1;j>=i;j--){
			b[i-1]=b[i-1]-a[(i-1)*N+j]*x[j];
		}
	}
	
	return ;
}

void max_replace(double *a, double *b, int N, int i){
	int k, j;
	double max = mod(a[i*N+i]);
	int tmp = 0;
	
	for(k=i+1;k<N;k++){
		if(mod(a[k*N+i]) > max){
			max=mod(a[k*N+i]);
			tmp=k; 
		}
	}
	
	if(tmp==0) return;
	
	double t;
	for(j=i;j<N;j++){
		t=a[i*N+j];
		a[i*N+j]=a[tmp*N+j];
		a[tmp*N+j]=t;
	}
	
	t=b[i];
	b[i]=b[tmp];
	b[tmp]=t;
	
	return ;
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

double mod(double x){
	if(x>=0) return x;
	else return -1*x;
}


void F(double *b, double *v){
	/*b[0]=v[0]+v[1]+v[2]-6;
	b[1]=2*v[0]-v[1]+3*v[2]-9;
	b[2]=2*v[0]+5*v[1]-v[2]-9;*/
	
	b[0]=v[0]*v[0]*v[0]+sin(v[1])+v[2]*v[2]*v[2]*v[2]-sin(1)-16;
	b[1]=v[1]*v[1]*v[1]*v[1]+v[2]*v[2]*v[2]*v[2]-1-16;
	b[2]=sin(v[0])+cos(v[1])+cos(v[2])-cos(1)-cos(2);
	return;
}

void create_matrix_2(double *a, double *b, double *v, int N){
	int i, j;
	double h=1e-6;
	
	double *x_n; x_n=(double *)malloc(N*sizeof(double));
	F(b, v); 
	b[0]*=(-1); b[1]*=(-1); b[2]*=(-1);
	
	for(i=0;i<N;i++){
		v[i]+=h;
		F(x_n, v); 
		x_n[0]*=(-1); x_n[1]*=(-1); x_n[2]*=(-1);
		
		for(j=0;j<N;j++) a[j*N+i]=(x_n[j]-b[j])/h;
		v[i]-=h;
	}
	
	free(x_n);
	return;
}

