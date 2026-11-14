#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
typedef struct {
    int SBD;
    char Ten[30];
    char Khoa[10];
    float Diem;
} ThiSinh;

int main() {
    ThiSinh DS[100], SV;
    int N, i, j, d=0, SBD; //d là biến chỉ số thứ tự khi in danh sách ra

    printf("Nhap so thi sinh: "); scanf("%d", &N);
    for (i=0; i < N; i++) {
        printf("Nhap du lieu cho thi sinh %d: \n", i+1);
        printf("So bao danh: "); scanf("%d", &DS[i].SBD);
        while(getchar() != '\n'); // xóa buffer sau scanf, nên dùng cách này, dùng fflush(stdin) không an toàn
        printf("Ho ten: ");
        fgets(DS[i].Ten, sizeof(DS[i].Ten), stdin);
        DS[i].Ten[strlen(DS[i].Ten) - 1] = '\0';// Bỏ ký tự xuống dòng
        printf("Khoa dang ky: ");
        fgets(DS[i].Khoa, sizeof(DS[i].Khoa), stdin);
        DS[i].Khoa[strlen(DS[i].Khoa) - 1] = '\0'; // Bỏ ký tự xuống dòng
        printf("Ket qua thi: "); scanf("%f", &DS[i].Diem);
        printf("\n");
    }//for
    printf("\n\nNhan phim bat ky de xem ket qua thi...");
    getche(); //Tra Claude về tác dụng của hàm này: 1. Dừng chương trình chờ người dùng nhấn phím        
    for (i = 0; i < N-1; i++)
        for (j = i+1; j < N; j++)
            if (DS[i].Diem > DS[j].Diem) {
                SV = DS[i];
                DS[i] = DS[j];
                DS[j] = SV;
            }
    printf("\n\n                    KET QUA THI \n\n");
    d = 0; //Đặt lại biến d
    for(i = 0; i < N; i++)
        printf("%-3d BKA- %-6d %-24s %-6s %-6.1f\n", ++d, //d chỉ số thứ tự
            DS[i].SBD, DS[i].Ten, DS[i].Khoa, DS[i].Diem);
    printf("\n\nNhan phim bat ky de xem DSSV khoa CNTT");
    getche();

    d = 0;
    printf("\n\nDanh sach thi sinh trung tuyen khoa CNTT\n\n");
    for (i = 0; i < N; i++)
        if (strcmp(DS[i].Khoa,"CNTT")==0 && DS[i].Diem >= 22.5)
            printf("%-3d BKA-%-6d %-24s %-f\n", ++d, DS[i].SBD,
                DS[i].Ten, DS[i].Diem); 
    //Quy tắc thực sự là: for không có ngoặc nhọn chỉ áp dụng cho 1 câu lệnh (kết thúc bằng ;)
    //if...printf toàn bộ tính là 1 câu lệnh của for, nên không cần ngoặc nhọn cho for. printf mới là phần thân của if.
    printf("\n\nNhan phim bat ky de bat dau tim kiem theo so bao danh");
    getche();

    do {
        printf("\nNhap so bao danh can tim: ");
        scanf("%d", &SBD);
        while(getchar() != '\n'); // xóa buffer trước getche()
        for (i = 0; i < N; i++) //Lí do for không cần ngoặc cũng như ở trên, for ở đây chỉ chứa 1 câu lệnh là if
            if (DS[i].SBD == SBD) {
                printf("So bao danh : %d \n", SBD);
                printf("Ho ten      : %s \n", DS[i].Ten);
                printf("Khoa du thi : %s \n", DS[i].Khoa);
                printf("Diem thi    : %.1f \n", DS[i].Diem);
                break;
            }
        if (i == N)
            printf("So bao danh %d khong ton tai\n", SBD);
        printf("\nCo tiep tuc tim kiem nua khong (C/K): ");
    } while(toupper(getche()) != 'K'); //Tra Claude về tác dụng của hàm này: 2. Đọc ký tự lựa chọn 
                                        // Trong bài này hàm getche() có hai tác dụng 
    return 0;
}//main