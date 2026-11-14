#include <stdio.h>
#include <string.h>

typedef struct {
    char Ten[20];
    int NamHetHan;
    int SoLuong;
    float DonGia;
} Thuoc;

int main() {
    Thuoc DS[100], SV;
    int N, i, j;
    float TongGiaTri = 0;

    // Nhập danh sách thuốc
    N = 0;
    do {
        printf("\nNhap DL cho thuoc thu %d\n", N+1);
        printf("Ten thuoc : ");
        // while(getchar() != '\n'); --> không để ở đây được
        fgets(DS[N].Ten, sizeof(DS[N].Ten), stdin);
        DS[N].Ten[strlen(DS[N].Ten) - 1] = '\0';
        if(strcmp(DS[N].Ten, "***") == 0)
            break;
        printf("Nam het han : "); scanf("%d", &DS[N].NamHetHan);
        printf("So luong   : "); scanf("%d", &DS[N].SoLuong);
        printf("Don gia    : "); scanf("%f", &DS[N].DonGia);
        N++;
        while(getchar() != '\n');  // SỬA: dọn buffer SAU khi scanf xong
    } while(1);

    // Đưa danh sách thuốc ra màn hình
    printf("\n\n DANH SACH THUOC \n\n");
    printf("%-20s %-10s %-10s %-10s\n", "Ten thuoc", "Nam het han", "So luong", "Don gia");
    for(i = 0; i < N; i++)
        printf("%-20s %-11d %-10d %-10.2f\n", DS[i].Ten, DS[i].NamHetHan,
            DS[i].SoLuong, DS[i].DonGia);

    // Đưa ra danh sách thuốc đã hết hạn (trước năm 2025)
    printf("\n\n DANH SACH THUOC HET HAN \n\n");
    for(i = 0; i < N; i++)
        if(DS[i].NamHetHan < 2025)
            printf("%-20s %d\n", DS[i].Ten, DS[i].NamHetHan);

    // Tính tổng giá trị thuốc đã hết hạn
    TongGiaTri = 0;
    for(i = 0; i < N; i++)
        if(DS[i].NamHetHan < 2025)
            TongGiaTri += DS[i].SoLuong * DS[i].DonGia;
    printf("\nTong gia tri thuoc het han : %.2f\n", TongGiaTri);

    // Xóa thuốc hết hạn khỏi danh sách
    i = 0;
    while(i < N) {
        if(DS[i].NamHetHan < 2025) {
            for(j = i; j < N-1; j++)
                DS[j] = DS[j+1];
            N--;
        } else
            i++;
    }

    // Đưa danh sách mới ra màn hình
    printf("\n\n DANH SACH THUOC SAU KHI XOA \n\n");
    printf("%-20s %-10s %-10s %-10s\n", "Ten thuoc", "Nam het han", "So luong", "Don gia");
    for(i = 0; i < N; i++)
        printf("%-20s %-11d %-10d %-10.2f\n", DS[i].Ten, DS[i].NamHetHan,
            DS[i].SoLuong, DS[i].DonGia);

    // Sắp xếp theo năm hết hạn tăng dần
    for(i = 0; i < N-1; i++)
        for(j = i+1; j < N; j++)
            if(DS[i].NamHetHan > DS[j].NamHetHan) {
                SV = DS[i];
                DS[i] = DS[j];
                DS[j] = SV;
            }

    // Đưa danh sách đã sắp xếp ra màn hình
    printf("\n\n DANH SACH THUOC SAP XEP THEO NAM HET HAN \n\n");
    printf("%-20s %-10s %-10s %-10s\n", "Ten thuoc", "Nam het han", "So luong", "Don gia");
    for(i = 0; i < N; i++)
        printf("%-20s %-11d %-10d %-10.2f\n", DS[i].Ten, DS[i].NamHetHan,
            DS[i].SoLuong, DS[i].DonGia);

    return 0;
} //main