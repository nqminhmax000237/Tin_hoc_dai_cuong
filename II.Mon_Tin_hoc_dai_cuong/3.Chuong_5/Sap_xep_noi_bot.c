#include <stdio.h>
int main(){
    int A[100] ;
    int N, i, j , t;
    printf("So phan tu [< 100]: "); scanf("%d",&N);
    printf("Hay nhap day so...\n");
    for(i=0; i < N; i++){
        printf("A[%d] = ",i); scanf("%d",&A[i]);
    }
    printf("\nDay vua nhap...\n");
    for(i=0; i < N; i++)
        printf("%4d", A[i]);
    printf("\n\n");
    printf("Sap xep day theo thuat toan noi bot");
    for(i=0;i<N-1;i++){
        for(j=0;j<N-i-1;j++){
            if(A[j]>A[j+1]){
                t=A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
        printf("\nLuot %d : ",i+1);
        for(j=0; j < N; j++)
            printf("%4d", A[j]);

    }
    return 0;
}
