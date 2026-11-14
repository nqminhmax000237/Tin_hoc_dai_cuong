#include <stdio.h>
#include <math.h>
int main(){
    double ax,ay,bx,by,cx,cy;
    printf("Nhap toa do diem A (x,y): ");
    scanf("%lf %lf", &ax,&ay);
    printf("Nhap toa do diem B (x,y): ");
    scanf("%lf %lf", &bx,&by);
    printf("Nhap toa do diem C (x,y): ");
    scanf("%lf %lf", &cx,&cy);
    
/* Kiểm tra 3 điểm A.B,C có thẳng hàng không (diện tích = 0)
Su dung cong thuc dien tich tam giac qua toa do:
Dien tich = (1/2) * |AB x AC| <-- Tích có hướng
Voi 2 vector:
AB = (xB-xA, yB-yA)
AC = (xC-xA, yC-yA)
Tich cheo 2D:
AB x AC = (xB-xA)*(yC-yA) - (yB-yA)*(xC-xA)
Khai trien va rut gon:
AB x AC = xA*(yB-yC) + xB*(yC-yA) + xC*(yA-yB)
=> S = 0.5 * |xA*(yB-yC) + xB*(yC-yA) + xC*(yA-yB)|  

Với tọa độ Oxyz: |...| là phép lấy độ dài(lấy căn x^2+y^2+z^2) 
Với tọa độ Oxy:  |...| là phép lấy giá trị tuyệt đối
*/

double S= ax*(by-cy)+bx*(cy-ay)+cx*(ay-by); //Hoặc để là S=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay); <-- công thức gốc, chưa rút gọn
if(S==0){
    printf("\n Ba diem A,B,C thang hang, khong tao thanh tam giac! \n");
    return 1;
}
// Tính độ dài 3 cạnh
double AB=sqrt((bx-ax)*(bx-ax)+(by-ay)*(by-ay));
double AC=sqrt((cx-ax)*(cx-ax)+(cy-ay)*(cy-ay));
double BC=sqrt((cx-bx)*(cx-bx)+(cy-by)*(cy-by));
//Trung điểm M của BC và trung tuyến AM
double mx=(bx+cx)/2;
double my=(by+cy)/2;
double AM=sqrt((mx-ax)*(mx-ax)+(my-ay)*(my-ay));

printf("\n KET QUA \n");
printf("Do dai ba canh AB,BC,AC lan luot la: %.2f, %.2f, %.2f \n",AB,BC,AC );
printf("Do dai trung tuyen AM: %.2f \n",AM);


    return 0;
}
