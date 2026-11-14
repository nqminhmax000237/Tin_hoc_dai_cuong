#include <stdio.h>
#include <math.h>
int main() {
    float x, fx;
    for(x=-10.0; x<=5.0+1e-9;x+=0.1){
         /* Vong lap x tu -10.0 den 5.0, buoc nhay 0.1
            Dung x <= 5.0 + 1e-9 de tranh sai so cong don cua so thuc:
            x += 0.1 nhieu lan co the khien x = 4.9999... thay vi 5.0
            => neu chi viet x <= 5.0 co the bo mat gia tri x = 5.0       */

        if(fabs(x) <=1e-6) fx=0.0;
            /* Xu ly rieng x = 0 de tranh chia cho 0 trong cong thuc: fabs(x) = 0 => chia cho 0
               Dung fabs(x) < 1e-6 thay vi x == 0 vi x la float cong don
               0.1 nhieu lan, khi den 0 co the la 0.0000001 thay vi 0
               chinh xac => x == 0 bi bo qua */

        else fx=pow(x,5) + x/(fabs(x))*pow(fabs(x),1.0/5);
        printf("<%4.1f,%7.2f>\n",x,fx);
    }
    
    return 0;
}