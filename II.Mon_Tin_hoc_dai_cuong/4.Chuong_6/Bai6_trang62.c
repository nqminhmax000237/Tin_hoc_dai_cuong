#include <stdio.h>
#include <string.h>

typedef struct {
    char Ten[30];
    int SoBanThang;
    int SoBanThua;
    int SoTheVang;
    int SoTheDo;
} DoiBong;

int main() {
    DoiBong DS[32], Tmp;
    int N, i, j;

    // Nhập danh sách đội bóng
    N = 0;
    do {
        printf("\nNhap DL cho doi bong thu %d\n", N+1);
        printf("Ten doi bong : ");
        // while(getchar() != '\n'); --> không để ở đây được
        fgets(DS[N].Ten, sizeof(DS[N].Ten), stdin);
        int len = strlen(DS[N].Ten);
        if (len > 0 && DS[N].Ten[len-1] == '\n')
            DS[N].Ten[len-1] = '\0';
        if(strlen(DS[N].Ten) == 0)
            break;
        printf("So ban thang : "); scanf("%d", &DS[N].SoBanThang);
        printf("So ban thua  : "); scanf("%d", &DS[N].SoBanThua);
        printf("So the vang  : "); scanf("%d", &DS[N].SoTheVang);
        printf("So the do    : "); scanf("%d", &DS[N].SoTheDo);
        N++;
        while(getchar() != '\n'); // dọn buffer sau scanf
    } while(N < 32);

    // Đưa danh sách ra màn hình
    printf("\n\n DANH SACH DOI BONG \n\n");
    printf("%-20s %-10s %-10s %-10s %-10s\n",
        "Ten doi", "Ban thang", "Ban thua", "The vang", "The do");
    for(i = 0; i < N; i++)
        printf("%-20s %-10d %-10d %-10d %-10d\n",
            DS[i].Ten, DS[i].SoBanThang, DS[i].SoBanThua,
            DS[i].SoTheVang, DS[i].SoTheDo);

    // Tìm kiếm đội bóng theo tên
    char TenTim[30];
    printf("\n\nNhap ten doi bong can tim : ");
    fgets(TenTim, sizeof(TenTim), stdin);
    int lenTim = strlen(TenTim);
    if (lenTim > 0 && TenTim[lenTim-1] == '\n')
        TenTim[lenTim-1] = '\0';

    int timThay = 0;
    for(i = 0; i < N; i++)
        if(strcmp(DS[i].Ten, TenTim) == 0) {
            printf("\n Thanh tich cua doi %s:\n", DS[i].Ten);
            printf("  So ban thang : %d\n", DS[i].SoBanThang);
            printf("  So ban thua  : %d\n", DS[i].SoBanThua);
            printf("  So the vang  : %d\n", DS[i].SoTheVang);
            printf("  So the do    : %d\n", DS[i].SoTheDo);
            timThay = 1;
            break;
        }
    if(timThay==0)
        printf("\n Khong tim thay doi bong \"%s\"\n", TenTim);

    // Tính và đưa ra điểm của các đội
    // Công thức: thắng +10, thua -5, thẻ vàng -2, thẻ đỏ -5
    printf("\n\n BANG DIEM CAC DOI BONG \n\n");
    printf("%-20s %-10s\n", "Ten doi", "Diem");
    for(i = 0; i < N; i++) {
        int Diem = DS[i].SoBanThang * 10
                 - DS[i].SoBanThua  * 5
                 - DS[i].SoTheVang  * 2
                 - DS[i].SoTheDo    * 5;
        printf("%-20s %-10d\n", DS[i].Ten, Diem);
    }

    return 0;
} //main