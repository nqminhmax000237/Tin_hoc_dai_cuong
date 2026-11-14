#include <stdio.h>
#include <math.h>
int main() {
    double ax,ay,bx,by,cx,cy,mx,my;
    printf("Nhap toa do A (x, y): "); scanf("%lf %lf",&ax,&ay);
    printf("Nhap toa do B (x, y): "); scanf("%lf %lf",&bx,&by);
    printf("Nhap toa do C (x, y): "); scanf("%lf %lf",&cx,&cy);
    printf("Nhap toa do M (x, y): "); scanf("%lf %lf",&mx,&my);
    /* Kiem tra A, B, C co tao thanh tam giac khong
       Dung tich cheo: S = (xB-xA)*(yC-yA) - (xC-xA)*(yB-yA)  */
    double S_abc=(bx-ax)*(cy-ay)-(cx-ax)*(by-ay) ;
    if( fabs(S_abc)<=1e-9){
        printf("A, B, C thang hang, khong tao thanh tam giac!\n");
        return 1;
    }
    /* Tinh tich co huong cua M voi tung canh AB, BC, CA (hay chính là diện tích các tam giác MAB, MBC, MCA)
       S1 = tich co huong canh AM voi canh AB
       S2 = tich co huong canh BM voi canh BC
       S3 = tich co huong canh CM voi canh CA                          */
    double S1= (bx-ax)*(my-ay)-(mx-ax)*(by-ay) ;
    double S2= (cx-bx)*(my-by)-(mx-bx)*(cy-by) ;
    double S3= (ax-cx)*(my-cy)-(mx-cx)*(ay-cy) ;
    /* Kiem tra M tren canh: 1 trong 3 tich bang 0 */
    if(fabs(S1) < 1e-9 || fabs(S2) < 1e-9 || fabs(S3) < 1e-9){
        printf("M nam tren canh cua tam giac ABC\n");
    }
    /* Kiem tra M trong tam giac: ca 3 tich cung dau */
    else if( (S1>0 && S2>0 && S3 >0) || (S1<0 && S2<0 && S3<0)){
        printf("M nam trong tam giac ABC\n");
    }
    /* Con lai: M nam ngoai tam giac */
    else printf("M nam ngoai tam giac ABC\n");

    return 0;
}