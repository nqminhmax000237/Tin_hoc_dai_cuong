#include <stdio.h>
int main() {
     int a[100],n;
    //Nhập số phần tử:
    do{
        printf("Nhap so phan tu cua mang(<100): ");
        scanf("%d",&n);
    }while(n<=0 || n>=100);
        //Nhập dãy số
    int i;
    for(i=0;i<n;i++){
        printf("Nhap vao phan tu a[%d]: ",i);
        scanf("%d",&a[i]);
    }
    //Tìm số chắn nhỏ nhất
    int min=-1;
    for(i=0;i<n;i++){
        if(a[i]%2==0){
            if(min=-1 || a[i]<min){
                min=a[i];
            }
        }
    }
    if(min == -1)
        printf("\nKhong co so chan trong day!\n");
    else
        printf("\nSo chan nho nhat trong day: %d\n", min);
    
    return 0;
}