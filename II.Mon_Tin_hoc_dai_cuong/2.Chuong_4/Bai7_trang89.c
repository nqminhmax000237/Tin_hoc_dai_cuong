#include <stdio.h>
#include <math.h>
int main() {
    int a, i=1, S7=0, d7=0, S=0, d=0; //;Lưu ý: i phải bắt đầu từ 1 mới đúng -> các lưu đồ khả năng là bị sai ở chỗ này
    do{
        printf("Nhap so nguyen: ");
        scanf("%d",&a);
        i++;
        S=S+a;
        if(a%7==0){
            d7++;
            S7 += a;
        }
        if( (a>35) && (a<70)) d++; 
    }while( (i<=100) && (S<=1550) ); 
    printf("So phan tu trong khoang (35,70) la: %d\n",d);
    if(d7==0) printf("Khong co phan tu nao chia het cho 7\n");
    else printf("Trung binh cong cac so chia het cho 7 la: %.4f", (float)S7/d7);
    
    return 0;
}