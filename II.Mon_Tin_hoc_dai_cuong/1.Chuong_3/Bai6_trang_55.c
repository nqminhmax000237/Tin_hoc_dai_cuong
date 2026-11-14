#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int main() {
    double C;
    printf("Nhap gia tri chu vi: ");
    scanf("%lf",&C);
    if(C<=0){
        printf("Chu vi phai lon hon 0\n");
        return 1;
    }
    //Hình tròn:
    double r=C/(2*M_PI);
    double S_tron=M_PI*r*r;
    //Hình vuông
    double a=C/4;
    double S_vuong=a*a;
    //Hình tam giác đều
    double b=C/3;
    double S_tamgiacdeu=b*b*(sqrt(3)/4);
    printf("\nKET QUA\n");
    printf("Dien tich hinh tron: %.4f\n",S_tron);
    printf("Dien tich hinh vuong: %.4f\n",S_vuong);
    printf("Dien tich hinh tam giac deu: %.4f\n",S_tamgiacdeu);
    
    return 0;
}