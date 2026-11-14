#include <stdio.h>
#include <string.h>
typedef struct {
    char Ten[50];
    int NS;
} SinhVien;
int main() {
    SinhVien DS[100];
    SinhVien SV;
    int n = 0;  
    do {
        printf("Ho ten: "); fflush(stdin);
        fgets(SV.Ten, sizeof(SV.Ten), stdin);
        SV.Ten[strlen(SV.Ten) - 1] = '\0';
        if (strlen(SV.Ten) > 0) {
            printf("Nam sinh: "); scanf("%d", &SV.NS);
            while(getchar() != '\n'); // ✅ xóa buffer sau scanf
            DS[n] = SV; n = n + 1;
        }
    } while (strlen(SV.Ten) > 0);

    printf("\n\n");
    printf("          HO & TEN                    NAM SINH\n");
    for (int i = 0; i < n; i++)
        printf("%-3d%-30s %6d\n", i + 1, DS[i].Ten, DS[i].NS);
    printf("\n\n");
    
    SV = DS[0];
    for (int i = 0; i < n; i++)
        if (DS[i].NS < SV.NS)
            SV = DS[i];
    
    printf("Sinh vien: %s sinh nam: %d lon tuoi nhat", SV.Ten, SV.NS);
    
    return 0;
} // main