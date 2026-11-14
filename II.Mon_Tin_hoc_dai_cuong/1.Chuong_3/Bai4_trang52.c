#define _USE_MATH_DEFINES //Phải có dòng này thì M_PI mới không bị gạch chân đỏ(dù gạch chân đỏ vẫn chạy được)
#include <stdio.h>
#include <math.h>
int main() {
    double x;
    printf("Nhap x: ");
    scanf("%lf",&x);
    double a=sqrt(pow(2,x)+M_PI);
    double b=log(exp(x+1.23)+1);
    double tu_so=cos(3*a)+pow(2*pow(x,3)+x+1,1.0/5);
    double mau_so=log(pow(3,x*x)+2.14*b)/log(7); //Doi co so: log7(u) = ln(u) / ln(7)
    if(fabs(mau_so) < 1e-9) {
        printf("Mau so bang 0, bieu thuc khong xac dinh!\n");
        return 1;
    }
    double A=tu_so/mau_so;
    printf("Ket qua: %.4f",A);
    

    return 0;
}