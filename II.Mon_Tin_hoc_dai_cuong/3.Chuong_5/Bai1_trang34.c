#include <stdio.h>
#include <math.h>
int main() {
    int a[100],n;
    //Nhập số phần tử:
    do{
        printf("Nhap so phan tu cua mang(<100): ");
        scanf("%d",&n);
    }while(n<0 || n>=100);
    if(n==0){
        printf("Day co 0 phan tu, tong=0,tich=0");
        return 0;
    }
    //Nhập dãy số
    int i;
    for(i=0;i<n;i++){
        printf("Nhap vao phan tu a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    //Tính tổng, tích:
    long long tong,tich;
    for(i=0;i<n;i++){
        tong += a[i];
        tich *= a[i];
    }
    printf("Tổng: %lld, tích: %lld\n",tong,tich);
    //Các số chia hết cho 3 và lớn hơn 100
    int dem=0;
    for(i=0;i<n;i++){
        if( (a[i]%3==0) && (a[i]>100)){
            printf("%d",a[i]);
            dem++;
        }
    }
    if(dem==0) printf("Day khong co so nao chia het cho 3 va lon hon 100\n");
    else printf("Day co %d so chia het cho 3 va lon hon 100", dem);
    // Dem so cac so nam trong doan [100,1000)
    int d=0;
    for(i=0;i<n;i++){
        if( (a[i]>=100) && (a[i]<1000)){
            d++;
        }
    }
     if(d==0) printf("Day khong co so nao nam trong doan [100,1000)");
    else printf("Day co %d so nam trong doan [100,1000)", d);
    return 0;
}