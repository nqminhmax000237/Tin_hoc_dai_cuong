#include <stdio.h>
#include <math.h>
//Đề bài: Nhập tọa độ A,B,C và in ra diện tích tam giác ABC
int main() {
    double ax, ay, bx, by, cx, cy;

    /* Nhap toa do 3 diem */
    printf("Nhap toa do diem A (x y): ");
    scanf("%lf %lf", &ax, &ay);
    printf("Nhap toa do diem B (x y): ");
    scanf("%lf %lf", &bx, &by);
    printf("Nhap toa do diem C (x y): ");
    scanf("%lf %lf", &cx, &cy);

    /* Tinh dien tich tam giac theo cong thuc:
       S = (1/2) * |AB x AC|
       Trong do tich cheo 2D: AB x AC = (xB-xA)*(yC-yA) - (xC-xA)*(yB-yA)
       Dung fabs() ngay khi tinh de S luon >= 0                            */
    double S = fabs((bx-ax)*(cy-ay) - (cx-ax)*(by-ay)) / 2.0;

    /* Kiem tra 3 diem thang hang: neu S = 0 thi khong tao thanh tam giac
       Dung S < 1e-9 thay vi S == 0 vi may tinh luu so thuc khong chinh xac tuyet doi, co the xuat hien sai so nho khi tinh toan     
       Vi du: 3 diem thang hang A(0,0), B(1, 0.1), C(2, 0.2)
       Toan hoc: S = 0 chinh xac
       May tinh co the tinh: S = 0.000000000000000001 (khong phai 0)
       => Neu dung S == 0 se sai, cho rang 3 diem khong thang hang

       fabs(S) < 1e-9 co nghia la: S "gan bang 0" (sai so < 0.000000001)
       Du S khong bang 0 tuyet doi nhung rat nho thi van coi la thang hang

       Quy tac chung: Khong bao gio dung == de so sanh so thuc
                  Luon dung nguong sai so epsilon nhu 1e-9           */
    if (S < 1e-9) {
        printf("Ba diem thang hang, khong tao thanh tam giac!\n");
        return 1;
    }

    printf("Dien tich tam giac ABC: %.2f\n", S);

    return 0;
}