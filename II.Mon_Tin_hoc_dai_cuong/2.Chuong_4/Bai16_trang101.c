#include <stdio.h>
#include <math.h>
int main() {
    int i;
    double x, u, S, eps;
    printf("Nhap x: "); scanf("%lf", &x);
    printf("Nhap eps: "); scanf("%lf", &eps);
    /* S1 = 1 - x + x^2/2! - x^3/3! + ...
       u *= -x/i doi dau moi vong                */
    S = 1.0; u = 1.0; i = 1;
    do {
        u *= -x / i;
        S += u;
        i++;
    } while (fabs(u) >= eps);
    printf("S1 = %.8f\n", S);
    printf("Kiem tra e^(-x) = %.8f\n", exp(-x));
    return 0;
}