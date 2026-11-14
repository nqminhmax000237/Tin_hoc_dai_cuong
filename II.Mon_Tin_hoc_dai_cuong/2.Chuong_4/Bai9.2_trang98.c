#include <stdio.h>
#include <limits.h>
int main(){
    int a, dem=0, max = INT_MIN;
    //INT_MIN là số nguyên nhỏ nhất (~-2 tỷ) từ limits.h → đảm bảo số đầu tiên nhập vào luôn lớn hơn max
    do {
        printf("Nhap mot so : "); scanf("%d",&a);
        if( a > max){
            max = a;
            dem = 1;
        }else
            if (a == max) dem++;
    }while ( a < 0 || a%5 !=0);
    printf("Max: %d; Co %d gia tri",max,dem);
}