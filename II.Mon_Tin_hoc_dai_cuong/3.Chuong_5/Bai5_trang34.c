#include <stdio.h>
#include <math.h>
int main(){
    int n;
    printf("Nhap n: "); scanf("%d",&n);
    double x[n],y[n]; // VLA — chỉ hợp lệ từ C99 trở lên
                      // Nếu muốn an toàn thì dùng kích thước cố định double x[100], y[100];
    int i;
    for(i=0;i<n;i++){
        scanf("%lf",&x[i]);
    }
    for(i=0;i<n;i++){
        scanf("%lf",&y[i]);
    }
    double A=0;
    double B=0;
    double C=0;
    for(i=0;i<n;i++){
        A += cos(x[i])*sin(x[i]);
        B +=(x[i]-y[i])*(x[i]-y[i]);
    }
    for(i=0;i<n-1;i++){
        C +=pow(x[1],i+2)*y[i+1]; //ở đề bàix2 là phần tử thứ 2, tức là x[1]
    }
    printf("A= %lf, B= %lf, C= %lf",A,sqrt(B),C);

    return 0;
}