#include <stdio.h>
#include <math.h>
int main() {
    double a,b,x;
    printf("Nhap hai gia tri a,b: ");
    scanf("%lf %lf",&a,&b);
    if(a<b){
        x=(a+b)/3;
    }
    else if(a==b){
        x=1.5172;
    }
    else x=(a-b)/(a*a+b*b);
    double y=15*x*x+x+7.2;
    printf("Gia tri cua y là: %.4f",y);
    return 0;
}