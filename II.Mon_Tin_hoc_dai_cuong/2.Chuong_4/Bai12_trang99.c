#include <stdio.h>
#include <math.h>
int main() {
    double x,S;
    int n,i;
    do{
        printf("Nhap x:(x >= 0): ");
        scanf("%lf",&x);
    }while(x<0);
    do{
        printf("Nhap so nguyen:(n >= 1): ");
        scanf("%d",&n);
    }while(n<1);
    if (x==0) { /* Hoặc if( fabs(x)< 1e-9)
                   Ở đây dùng x == 0 thay vì fabs(x) < 1e-9 
                   Vì x được nhập trực tiếp từ bàn phím, không qua tính toán nên so sánh == với 0 vẫn an toàn. 
                */
        printf("\nS=0.0000\n");
        return 0;
    }
    /* Tinh S tu trong ra ngoai
       Buoc 1: S = sqrt(x)
       Buoc i: S = sqrt(x + S)
       Lap lai n lan   */
       S=0;
       for(i=0;i<n;i++){
        S=sqrt(x+S);
       }
       printf("\nGia tri cua S: %.4f\n",S);
    
    return 0;
}