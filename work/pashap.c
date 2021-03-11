#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>
int main(void){
    double h, a, x0, v0, t0, t1, dt, s, x, y, i;
    int k, g=10;
    k = scanf("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf", &a, &x0, &v0, &t0, &t1, &dt, &s, &h);
    i = t0;
    if(k!=1){exit(1);}
    while(i<t1){
        y = h + v0*i*cos(a) - g*i*i/2;
        x = x0 + v0*i;
        printf("%lf ---> %lf ; %lf \n", i, x, y);
        i += dt;
    }
    return 0;
}