#include <stdio.h>

int main(){
    int M, N;
    // Nhập M, N
    do {
        printf("Nhap M, N (M,N < 30): ");
        scanf("%d %d", &M, &N);
    } while(M <= 0 || M >= 30 || N <= 0 || N >= 30);

    int u[30][30];
    int i, j;

    // Nhập ma trận
    printf("Nhap ma tran %dx%d:\n", M, N);
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++){
            printf("u[%d][%d] = ", i+1, j+1);
            scanf("%d", &u[i][j]);
        }

    // In ma trận
    printf("\nMa tran U:\n");
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++)
            printf("%5d", u[i][j]);
        printf("\n");
    }

    // -------- Tìm hàng có tổng lớn nhất --------
    int maxRowSum = 0, maxRow = 0;
    for(i = 0; i < M; i++){
        int sum = 0;
        for(j = 0; j < N; j++) sum += u[i][j];
        if(i == 0 || sum > maxRowSum){
            maxRowSum = sum;
            maxRow = i;
        }
    }
    printf("\nHang co tong lon nhat: hang %d (tong = %d)\n", maxRow+1, maxRowSum);

    // -------- Tìm cột có tổng lớn nhất --------
    int maxColSum = 0, maxCol = 0;
    for(j = 0; j < N; j++){
        int sum = 0;
        for(i = 0; i < M; i++) sum += u[i][j];
        if(j == 0 || sum > maxColSum){
            maxColSum = sum;
            maxCol = j;
        }
    }
    printf("Cot co tong lon nhat: cot %d (tong = %d)\n", maxCol+1, maxColSum);

    // -------- Tìm số lớn nhất và vị trí --------
    int maxVal = u[0][0], maxI = 0, maxJ = 0;
    int minVal = u[0][0], minI = 0, minJ = 0;
    for(i = 0; i < M; i++)
        for(j = 0; j < N; j++){
            if(u[i][j] > maxVal){ maxVal = u[i][j]; maxI = i; maxJ = j; }
            if(u[i][j] < minVal){ minVal = u[i][j]; minI = i; minJ = j; }
        }
    printf("\nSo lon nhat: %d tai vi tri [%d][%d]\n", maxVal, maxI+1, maxJ+1);
    printf("So nho nhat: %d tai vi tri [%d][%d]\n", minVal, minI+1, minJ+1);

    // -------- Ma trận S --------
    printf("\nMa tran S:\n");
    for(i = 0; i < M; i++){
        for(j = 0; j < N; j++){
            int s;
            if     (u[i][j] > 0) s =  1;
            else if(u[i][j] == 0) s = 0;
            else                  s = -1;
            printf("%3d", s);
        }
        printf("\n");
    }

    return 0;
}