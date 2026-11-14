#include <stdio.h>
#include <string.h>

typedef struct {
    char Ten[30];
    struct {
        int T, L, H, S; // S = T + L + H
    } DT;
} SinhVien;

int main() {
    SinhVien DS[100], TK, SV;
    int N, i, j, K;
    float C;

    N = 0; // N chứa số sinh viên đã nhập
    do {
        printf("\nNhap DL cho sv thu %d\n", N+1);
        printf("Ten SV : ");
        //while(getchar() != '\n'); // thay fflush(stdin)--> không để ở đây được vì lần thứ nhất nhập chưa cần xóa đệm, kể từ lần thứ 2 mới cần
        //Bai3_trang51.c trước đó là nó có scanf ở bên trên lên để while(...) ở đó cũng được, nhưng bài này ko có scanf ở bên trên nên sẽ khác
        //=> Cứ chỗ nào có scanf mà phía sau cần dùng fgets thì xóa bộ đệm sau scanf
        fgets(DS[N].Ten, sizeof(DS[N].Ten), stdin);
        DS[N].Ten[strlen(DS[N].Ten) - 1] = '\0';
        if(strlen(DS[N].Ten) == 0) //Độ dài bằng 0 ⇒ xâu rỗng
            break;
        else {
            printf("Nhap diem thi T L H cua SV %s : ", DS[N].Ten);
            scanf(" %d%d%d", &DS[N].DT.T, &DS[N].DT.L, &DS[N].DT.H);
            DS[N].DT.S = DS[N].DT.T + DS[N].DT.L + DS[N].DT.H;
            N++;
            while(getchar() != '\n');  // SỬA: dọn buffer SAU khi scanf xong
        }
    } while(1);

    // In ra danh sách vừa nhập
    printf("\n\n DANH SACH SINH VIEN\n\n");
    printf("      Ten SV           Toan  Ly  Hoa Tong \n");
    for(i = 0; i < N; i++)
        printf("%-20s%5d%5d%5d%6d\n", DS[i].Ten, DS[i].DT.T,
            DS[i].DT.L, DS[i].DT.H, DS[i].DT.S);

    // In danh sách trúng tuyển theo điểm chuẩn
    printf("\n\nDiem Chuan : "); scanf("%f", &C);
    printf("\n\n DANH SACH SINH VIEN TRUNG TUYEN \n\n");
    for(i = 0; i < N; i++)
        if((DS[i].DT.S >= C) && (DS[i].DT.T * DS[i].DT.L *
                DS[i].DT.H > 0))
            printf("%s\n", DS[i].Ten);

    // Tìm điểm của thủ khoa, bỏ qua trường hợp điểm liệt
    TK = DS[0];
    for (i = 1; i < N; i++)
        if (DS[i].DT.S > TK.DT.S && DS[i].DT.T * DS[i].DT.L * DS[i].DT.H > 0) // SỬA 1
            TK = DS[i];

    // Đưa ra danh sách thí sinh có điểm bằng điểm cao nhất
    for(i = 0; i < N; i++)
        if(DS[i].DT.S == TK.DT.S)
            printf("\n\n THU KHOA: %s \n\n", DS[i].Ten); // SỬA 2

    printf("\nSo nguoi trung tuyen:"); scanf("%d", &K);
    for (i = 0; i < N - 1; i++) //Sắp xếp theo tổng điểm thi
        for (j = i+1; j < N; j++)
            if (DS[i].DT.S < DS[j].DT.S) {
                SV = DS[i];
                DS[i] = DS[j];
                DS[j] = SV;
            }
    while ((K>0) && (K < N) && (DS[K-1].DT.S == DS[K].DT.S)) K--; // SỬA 3
    if (K>0) {
        printf("Diem Chuan La : %4d", DS[K-1].DT.S);
        printf("\n\n Danh Sach sinh vien trung tuyen \n");
        for (i=0; i < K; i++)
            printf("%s\n", DS[i].Ten);
    }
    return 0;
} //main