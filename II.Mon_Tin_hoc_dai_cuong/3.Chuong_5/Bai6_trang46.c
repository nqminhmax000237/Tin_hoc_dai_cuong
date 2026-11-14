#include <stdio.h>
int main() {
     int a[101],n;
    //Nhập số phần tử:
    do{
        printf("Nhap so phan tu cua mang(<100): ");
        scanf("%d",&n);
    }while(n<=0 || n>=100);
        //Nhập dãy số
    int i;
    printf("Nhap day so: ");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int x,k;
    printf("Nhap x: "); scanf("%d",&x);
    printf("Nhap k: "); scanf("%d",&k);
    if (k>n) {
        a[n]=x;
        n++;
    }
    else{
        for(i=n;i>=k;i--){
            a[i]=a[i-1];
        }
        a[k-1]=x;
        n++;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}