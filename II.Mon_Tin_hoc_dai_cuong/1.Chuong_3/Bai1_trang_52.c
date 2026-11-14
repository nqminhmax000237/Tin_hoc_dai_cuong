#include <stdio.h>
#include <math.h>
int main(){
    double a,b,c,p,dientich,ha,hb,hc; //Nên dùng double
    printf("Nhap chieu dai ba canh tam giac: ");
    scanf("%lf %lf %lf",&a,&b,&c);
    p=(a+b+c)/2;
    if( (a>0) && (b>0) && (c>0) && (a+b>c) && (c+b>a) && (a+c>b) ) {
        dientich=sqrt(p*(p-a)*(p-b)*(p-c));
        ha=2*dientich/a;
        hb=2*dientich/b;
        hc=2*dientich/c;
    }
    else {
        printf("\n Do khong phai ba canh cua tam giac!");
        return 1;
    }
    printf("Dien tich: %.2f \n",dientich);
    printf("Cac duong cao: ha=%.2f, hb=%.2f, hc=%.2f", ha,hb,hc);
    return 0;
}
