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
    // Tìm số bé nhất
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }

    // In kết quả
    printf("\nSo be nhat: %d\n", min);
    printf("Vi tri cac phan tu bang so be nhat:\n");
    for (int i = 0; i < n; i++) {
        if (a[i] == min)
            printf("  Vi tri %d (chi so %d)\n", i + 1, i);
    }

    return 0;
}