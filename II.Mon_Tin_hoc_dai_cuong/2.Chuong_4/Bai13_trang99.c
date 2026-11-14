#include <stdio.h>
int main() {
    int n,i;
    double x,u=1.0,S=1.0;
    printf("Nhap so thuc x: "); scanf("%lf", &x);
    do {
        printf("Nhap nguyen n (n>=0): ");
        scanf("%d", &n);
    } while (n < 0);
    for(i=1;i<=n;i++){
        u *= x;
        S += u/i;
    }
    printf("Ket qua: %.8f",S);
    
    return 0;
}