#include <stdio.h>
#include <math.h>
int main() {
    int x,max,dem;
    int first = 1; /* danh dau lan doc dau tien */
   do {
        printf("Nhap so: "); scanf("%d",&x);
        if(first){
            max=x;
            dem=1;
            first=0;
        }
        else if(x>max){
            max=x;
            dem=1;
        }
        else if(x==max) dem++;
   }while(! ((x>0) && (x%5==0)));
    
   printf("\nSo lon nhat: %d\n",max);
   printf("\nSo lan xuat hien: %d\n",dem);

    return 0;
}