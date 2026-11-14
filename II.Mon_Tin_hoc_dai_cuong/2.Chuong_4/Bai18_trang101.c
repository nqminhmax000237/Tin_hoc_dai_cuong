#include <stdio.h>
#include <math.h>
int main() {
    int i;
    double x, u, S, eps;
    printf("Nhap x: "); scanf("%lf", &x);
    printf("Nhap eps: "); scanf("%lf", &eps);
    /* S3 = 1 - x^2/2! + x^4/4! - ...
       So hang dau: u = 1 (i=1)
       Moi buoc: u *= -x^2 / (2i*(2i-1))        */
    S = 1.0; u = 1.0; i = 1;
    do {
        u *= (-x*x) / ((2*i)*(2*i-1) );
        S += u;
        i++;
    } while (fabs(u) >= eps);
    printf("S3 = %.8f\n", S);
    printf("Kiem tra cos(x) = %.8f\n", cos(x));
    return 0;
}