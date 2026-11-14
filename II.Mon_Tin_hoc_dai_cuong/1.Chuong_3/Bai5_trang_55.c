#define _USE_MATH_DEFINES
#include <stdio.h>
#include <math.h>
int main() {
    double r;
    printf("Nhap r: ");
    scanf("%lf",&r);
    if(r<=0){
        printf("Ban kinh phai lon hon 0\n");
        return 1;
    }
    double chu_vi=2*M_PI*r;
    double dien_tich=M_PI*r*r;
    printf("Chu vi: %.4f\n",chu_vi);
    printf("Dien tich: %.4f",dien_tich);
    
    return 0;
}