#include <stdio.h>
//Giả thiết: Lấy được viên cuối cùng thì thắng
int main() {
    int N, may_lay,lay;
    /* Nhap N trong khoang [30, 50) */
    do {
        printf("Nhap so vien soi N [30-50): ");
        scanf("%d", &N);
    } while (N < 30 || N >= 50);
    printf("\nMay tinh di truoc.\n\n");

    while (N > 0) {
        /* Lượt của máy tính:
           Chiến thuật: lấy số viên sỏi sao cho sau lượt của máy, số viên còn lại là bội của 6
           Máy lấy: N % 6, nếu N%6 == 0 thì lấy 1 để không bị thua */
        may_lay = N % 6;
        if (may_lay == 0) may_lay = 1;
        N -= may_lay;
        printf("May lay: %d vien. Con lai: %d vien.\n", may_lay, N);
        if (N == 0) {
            printf("May lay vien cuoi! MAY THANG!\n");
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
            printf("Ban lay vien cuoi! BAN THANG!\n");
            break;
        }
    }
    return 0;
    //Trường hợp N % 6 == 0 ngay từ đầu (N=6,12,...) → máy thua nếu người chơi biết chiến thuật
}