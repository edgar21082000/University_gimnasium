#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
double * cre_double_mem(int N){ 
double * tmp; 
tmp = (double *)malloc(N * sizeof(double)); 
if(tmp==NULL){ 
printf("cr_%d-memory error\n", N); 
exit(1); 
} 
return tmp; 
} 
void vvod(int N, double * tmp){ 
int i; 
for(i=0;i<N;i++){ 
scanf("%lf", &tmp[i]); 
} 
return; 
} 
double scalar(int N, double * kx, double * ky){ 
int i, scal; 
scal = 0; 
for(i=0;i<N;i++){ 
scal+=(kx[i]*ky[i]); 
} 
return scal; 
} 
void new_vec(int N, double * tmp, double a){ 
int i; 
for(i=0;i<N;i++){ 
tmp[i] = tmp[i] * a; 
} 
return; 
} 
void total_vec(int N, double * ky, double * kx){ 
int i; 
for(i=0;i<N;i++){ 
kx[i]+=ky[i]; 
} 
return; 
} 

void prn(int N, double * kx){ 
int i; 
for(i=0;i<N;i++){ 
printf("%lf\n", kx[i]); 
} 
return; 
} 
double dlin(int N, double * kx){ 
int i; 
double dl; 
dl = 0; 
for(i=0;i<N;i++){ 
dl+=kx[i]*kx[i]; 
} 
dl = sqrt(dl); 
return dl; 
} 
int main(void) 
{ 
double dl; 
double * kx; 
int N; 
scanf("%d",&N); 
kx = cre_double_mem(N); 
vvod(N, kx); 
dl = dlin(N, kx); 
printf("%lf",dl); 
return 0; 
}