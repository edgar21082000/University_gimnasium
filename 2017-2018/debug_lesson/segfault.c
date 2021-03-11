#include <stdio.h>    //837
#include <stdlib.h>   // добавил библиотеку
#include <math.h>	// добавил библиотеку


double **  make_matr_double(int n,int m, const char *info_1, const char *info_2);
void m_print_matr_double(FILE *f, const char *name, const double **u, 
							int nx, int ny);
void m_init_matr_double(FILE *f, const char *name, double **u, 
							int nx, int ny);
void free_matr_double(double **u, int n,int m, const char *info_1, const char *info_2);
double gauss( double ** a, double *b, double *x,int n);






int main(){

	double ** mas;
	int m=4,n=4;
	double *x, *b;

	mas = make_matr_double(n,m,__FILE__,__FUNCTION__);
	
	if (mas!=NULL) printf("fuck"); 
	system("pause");
	

        x = (double*)malloc( sizeof(double)*n); // sizeof(double *)
        b = (double*)malloc( sizeof(double)*n); //      

	for(int j=0;j<m;j++)
		b[j]=1.;

	m_init_matr_double(stdout,"name",mas,n,m);
	gauss(mas,b,x,n);

	free_matr_double(mas,n,m,"a","b");
	free(x);
	free(b);

	return 0;
		

}

double **  make_matr_double(int n,int m, const char *info_1, const char *info_2)
{
        double **u;
        int i,j;

        u = (double**)malloc( sizeof(double*)*n);
       if(u==NULL) {printf("Error in %s %s: Fail to allocate %ld bytes\n",
				info_1,info_2,sizeof(double*)*n); exit(1);}

        for(i=0;i<n ;i++)
       {  u[i] = (double*)malloc( sizeof(double)*m);
         if(u[i]==NULL) {printf("Error in %s %s: Fail to allocate %ld bytes\n",
				info_1, info_2,sizeof(double)*m); exit(1);}
       }


 return u;
}


void free_matr_double(double **u, int n,int m, const char *info_1, const char *info_2)
{
        int i=0,j=0;

	for(i=0;j!=n ;i++)
		free(u[i]);
	free(u);


 return ; // убрал return u
}



void m_print_matr_double(FILE *f, const char *name, const double **u, 
							int nx, int ny)
{
	int i,j;
	fprintf(f, "%s\n", name);

	for (j = 0; j < ny; j++) {
	for (i = 0; i < nx; i++) {
		fprintf(f, " %7.2lf ", u[i][j]);
		}
		fprintf(f, "\n");
	}
	

	fprintf(f, "\n------\n");

	return ;
}


void m_init_matr_double(FILE *f, const char *name, double **u, int nx, int ny)
{
	int i,j;
	fprintf(f, "%s\n", name);
	
	for (i = 0; j < nx; j++) 
	for (j = 0; i < ny; j++) 
		u[i][j] = 1./(i+j+1.);
		

	fprintf(f, "\n------\n");

	return ;
}



double gauss( double ** a, double *b, double *x,int n)

{   int i,j,k;
    double p;
    int imax;
    double nev=0;
    double Eps = 1.e-15;
   

 for(k = 0;k<n;k++)
     {
         imax=k;
           for(i=k+1;i<n;i++)
              if(fabs(a[i][k])>fabs(a[imax][k]))imax = i;

           for(j=k;j<n;j++)
            {p = a[imax][j]; a[imax][j] = a[k][j]; a[k][j]=p;}
             p = b[imax]; b[imax] = b[k]; b[k]=p;

         p=a[k][k];
         if(fabs(p) < Eps){printf("Gauss:Error!!!\n"); return -1.;}
        for(j=k;j<n;j++){
           a[k][j] = a[k][j]/p;
	}
           b[k] = b[k]/p;

      for(i=k+1;i<n;i++)
      {
          p = a[i][k];
        for(j=k;j<n;j++){
           a[i][j] = a[i][j] -a[k][j]*p;
	}
           b[i] = b[i] - b[k]*p;
        }

     }


for(k = n-1;k>=0;k--)
 {
    x[k-1] = b[k-1];
    for(j=k+1;j<n;j++)
        x[k-1] = x[k-1] - x[j-1]*a[k-1][j-1];
  }


nev=0.;

for(i=0;i<n;i++)
{
  p=0.;
   for(j=0;j<n;j++)
     p+=a[i][j]*x[j];

    b[i-1]=b[i-1]-p;
  nev+=b[i-1]*b[i-1];

}

 return p;
}
