#include <stdio.h>
#include <string.h>
typedef struct {
    char Ten[30];
    int NS;
} SinhVien;

int main() {
    SinhVien DS[100], SV;
    int N, i, j, d=0;
    char ten[30];

    printf("Nhap so sinh vien : "); scanf("%d", &N);
    for (i=0; i < N; i++) {
        printf("Nhap du lieu cho sinh vien %d: \n", i+1);
        printf("Ho ten : ");
        while(getchar() != '\n'); // ✅ thay fflush(stdin)
        fgets(DS[i].Ten, sizeof(DS[i].Ten), stdin);
        DS[i].Ten[strlen(DS[i].Ten) - 1] = '\0';
        printf("Nam sinh : "); scanf("%d", &DS[i].NS);
    }

    printf("\n\nSINH VIEN SINH NAM 1990\n\n");
    for (i = 0; i < N; i++)
        if (DS[i].NS == 1990)
            printf("%s\n", DS[i].Ten);

    printf("\n\nTim SV : ");
    while(getchar() != '\n'); // ✅ thay fflush(stdin)
    fgets(ten, sizeof(ten), stdin);
    ten[strlen(ten) - 1] = '\0';

    d = 0;
    for (i = 0; i < N; i++)
        if (strcmpi(ten, DS[i].Ten) == 0) { // ✅ sửa Ten thành ten. strcmpi — không phân biệt hoa/thường; strcmp — phân biệt hoa/thường; 
            printf("Sinh vien: %s\nSinh nam %d\n", DS[i].Ten, DS[i].NS);
            d = d + 1;
        }
    if (d == 0)
        printf("Khong co sinh vien: %s trong danh sach\n", ten);

    for (i = 0; i < N-1; i++) //sắp xếp theo pp lựa chọn
        for (j = i+1; j < N; j++)
            if (strcmp(DS[i].Ten, DS[j].Ten) > 0) {
                SV = DS[i];
                DS[i] = DS[j];
                DS[j] = SV;
            }
    printf("\n\n DANH SACH SAP XEP\n\n");
    for(i = 0; i < N; i++)
        printf("%d %-20s %d \n", i+1, DS[i].Ten, DS[i].NS);
    return 0;
} //main