#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
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
void newmatrix(int N, double * kx, double x){
    int a;
    for(a=0;a<N*N;a++){
        kx[a]=kx[a]*x;
    }
    return;
}
void vecmatrix(int N, double * kx, double * ky){
    int a,i;
    for(a=0;a<N*N;a+=N){
        for(i=0;i<N;i++){
            kx[i+a] = (kx[i+a] + ky[i+a]);
        }
    }
    return;
}
void prn(int N, double * kx){
    int i;
    for(i=0;i<N;i++){
        printf("%lf ", kx[i]);
    }
    return;
}
void prnmatrix(int N, double * kx){
    int a,i;
    for(a=0;a<N*N;a+=N){
        for(i=0;i<N;i++){
            printf("%lf ", kx[i+a]);
        }
    }
    printf("\n");
}
int main(void)
{
    double x,y;
    double * kx;
    double * ky;
    int N;
    scanf("%d", &N);
    scanf("%lf", &x);
    scanf("%lf", &y);
    kx = cre_double_mem(N*N);
    ky = cre_double_mem(N*N);
    vvod(N*N, kx);
    vvod(N*N, ky);
    prnmatrix(N, kx);
    prnmatrix(N, ky);
    printf("\n");
    newmatrix(N,kx,x);
    newmatrix(N,ky,y);
    vecmatrix(N,kx,ky);
    prnmatrix(N, kx);
    return 0;
}