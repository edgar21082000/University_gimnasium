#include <stdio.h> 
#include <stdlib.h> 
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
int main(void) 
{ 
double x, y, a, b; 
double * kx; 
double * ky; 
int N; 
scanf("%d", &N); 
scanf("%lf", &a); 
scanf("%lf", &b); 
kx = cre_double_mem(N); 
ky = cre_double_mem(N); 
vvod(N, kx); 
vvod(N, ky); 
new_vec(N, kx, a); 
new_vec(N, ky, b); 
total_vec(N, ky, kx); 
prn(N, kx); 
return 0; 
}