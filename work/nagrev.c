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