#include <stdio.h>
#include <math.h>

int main() {
    double a,b,c;
    printf("Nhap ba so thuc a,b,c: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    double fa= pow(a,7)+5*cbrt(pow(a,5)+3*pow(a,3)+2)+12;
    double fb= pow(b,7)+5*cbrt(pow(b,5)+3*pow(b,3)+2)+12;
    double fc= pow(c,7)+5*cbrt(pow(c,5)+3*pow(c,3)+2)+12;
    double trungbinh=(fa+fb+fc)/3;
    printf("\nGia tri trung binh cua fa,fb,fc: %.4f",trungbinh);
    
    return 0;
}