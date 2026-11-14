#include <stdio.h>
int main(){
    int a[100],n,b[100];
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
    int min=a[0];
    b[0]=0; // b là mảng lưu chỉ số của phần bé nhất, giả sử ban đầu min=a[0] nên b[0] mang chỉ số của a[0] là 0
    int dem=1;
    for(i=1;i<n;i++){
        if(a[i]<min){
            min=a[i];
            dem=1;
            b[dem-1]=i;
        }
        else if(a[i]==min){
            b[dem]=i;
            dem++;
        }
    }
    printf("Phan tu be nhat la: %d\n",min);
    printf("No xuat hien o cac vi tri: ");
    for(i=0;i<dem;i++){
        printf("%d ",b[i]);
    }

    return 0;
}