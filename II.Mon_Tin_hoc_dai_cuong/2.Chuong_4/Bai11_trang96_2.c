#include <stdio.h>
int main() {
    int N, lay, may_lay;
    /* Nhap N trong khoang [30, 50) */
    do {
        printf("Nhap so vien soi N [30-50): ");
        scanf("%d", &N);
    } while (N < 30 || N >= 50);
    printf("\nMay tinh di truoc.\n\n");

    while (N > 0) {
        /* Lượt của máy tính:
              Chien thuat cua may: giu so vien con lai la boi so 6 + 1. Vi nguoi lay vien CUOI se THUA
           => May can de nguoi choi roi vao tinh huong chi con 1 vien
           => Moi vong tong 2 nguoi lay 1+5=6, nen may giu N % 6 == 1
           => may_lay = (N - 1) % 6
           => neu = 0 thi lay 1 de khong bi roi vao boi so 6 + 1 */
        may_lay = (N - 1) % 6;
        if (may_lay == 0) may_lay = 1;
        N -= may_lay;
        printf("May lay: %d vien. Con lai: %d vien.\n", may_lay, N);
        if (N == 0) {
            printf("May lay vien cuoi! BAN THANG!\n");
            break;
        }
        //Lượt của người chơi
        do {
            printf("Ban lay may vien (1-5)? ");
            scanf("%d", &lay);
        } while (lay < 1 || lay > 5);
        N -= lay;
        printf("Ban lay: %d vien. Con lai: %d vien.\n\n", lay, N);
        if (N == 0) {
            printf("Ban lay vien cuoi! MAY THANG!\n");
            break;
        }
    }
    return 0;
    //Trường hợp (N-1) % 6 == 0 ngay từ đầu (N=7,13,...) → máy thua nếu người chơi biết chiến thuật!
}