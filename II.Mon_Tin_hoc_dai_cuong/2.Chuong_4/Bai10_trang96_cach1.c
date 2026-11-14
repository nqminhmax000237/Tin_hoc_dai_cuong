#include <stdio.h>
int main() {
    int x,tong,dem;
    tong=0;
    dem=0;
    printf("Nhap so: "); scanf("%d",&x);
    while(x!=0){
        if(x%2==0){
        tong +=x;
        dem++;
        }
        printf("Nhap so: "); scanf("%d",&x);
    }
    if(dem==0) printf("Khong co so chan khac 0 nao trong day vua nhap\n");
    else printf("Trung binh cong cac so chan khac 0: %.4f",(float)tong/dem);
    return 0;
}