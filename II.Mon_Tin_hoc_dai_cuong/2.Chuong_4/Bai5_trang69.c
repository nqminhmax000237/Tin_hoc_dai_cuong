#include <stdio.h>
#include <ctype.h>

int main(){
    int N,i;
    do {
        printf("\n Nhap N: ");
        scanf("%d",&N);
        printf("%d = ",N);
        i=2;
        while(i<N){
            if(N%i==0){
                printf("%d x ",i);
                N=N/i;
            }
            else i++;
        }
        printf("%d \n", N);
        while (getchar() != '\n'); // xả bộ đệm <-- Phải có
        printf("Tiep tuc <C/K>?: ");
    } while( toupper(getchar()) != 'K');
return 0;
}