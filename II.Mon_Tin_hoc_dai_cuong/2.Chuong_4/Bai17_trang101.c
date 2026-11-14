#include <stdio.h>
#include <math.h>
int main() {
    int i;
    double x, u, S, eps;
    printf("Nhap x: "); scanf("%lf", &x);
    printf("Nhap eps: "); scanf("%lf", &eps);
    /* S2 = x - x^3/3! + x^5/5! - ...
       So hang dau: u = x (i=1)
       Moi buoc: u *= -x^2 / ((2i+1)*2i)        */
    S = x; u = x; i = 1;
    do {
        u *= (-x*x) / ((2*i+1)*(2*i) );
        S += u;
        i++;
    } while (fabs(u) >= eps);
    printf("S2 = %.8f\n", S);
    printf("Kiem tra sin(x) = %.8f\n", sin(x));
    return 0;
}