#include<stdio.h>

int kiemTraToanPhan(int n){
    static int count=0;
    count++;
    printf("Hàm kiểm tra đã chạy %d lần\n", count);
    int a;
    while(n>0){
        a=n%10;
        if(a%2==1){
            n=n/10;
        }
        else return 0;
    }
    return 1;
    
}
int main(){
    int a[1000];
    int i=0;
    scanf("%d",&a[0]);
    while(a[i]>0){
        i++;
        scanf("%d",&a[i]);
    }
    int j=0; int dem=0,tong=0;
    while(a[j]>0){
        if(kiemTraToanPhan(a[j])) {
            dem++;
            tong+=a[j];
        }
        j++;
        
    }

    printf("Dãy đã nhập có %d số có toàn chữ số lẻ\n",dem);
    printf("Tổng của chúng là: %d",tong);
    return 0;
}