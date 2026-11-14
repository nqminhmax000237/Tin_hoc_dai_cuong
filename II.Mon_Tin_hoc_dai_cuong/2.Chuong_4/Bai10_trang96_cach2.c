#include <stdio.h>
#include <math.h>
int main() {
    int x,tong,dem;
    tong=0;
    dem=0;
    do{
        printf("Nhap so: "); scanf("%d",&x);
        if( (x!=0) && (x%2==0) ){
        tong +=x;
        dem++;
        }
    }while(x!=0);

    if(dem==0) printf("Khong co so chan khac 0 nao trong day vua nhap\n");
    else printf("Trung binh cong cac so chan khac 0: %.4f\n",(float)tong/dem);
    return 0;
}