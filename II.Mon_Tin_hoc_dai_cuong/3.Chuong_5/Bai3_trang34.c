#include <stdio.h>

int main(){
    int A[100];
    int N, i;

    // Nhập số phần tử
    printf("So phan tu N = "); 
    scanf("%d", &N);

    // Nhập dãy số
    printf("Nhap day so:\n");
    for(i = 0; i < N; i++){
        printf("A[%d] = ", i); 
        scanf("%d", &A[i]);
    }

    // In dãy vừa nhập
    printf("\nDay vua nhap:\n");
    for(i = 0; i < N; i++)
        printf("%4d", A[i]);
    printf("\n");

    // Đếm bộ 3 thỏa mãn x[i] = (x[i-1] + x[i+1]) / 2
    int dem = 0;
    for(i = 1; i <= N - 2; i++){
        if(2 * A[i] == A[i-1] + A[i+1]){
            dem++;
            printf("Bo 3: A[%d]=%d, A[%d]=%d, A[%d]=%d\n",
                    i-1, A[i-1], i, A[i], i+1, A[i+1]);
        }
    }

    printf("\nSo bo 3 thoa man: %d\n", dem);

    return 0;
}