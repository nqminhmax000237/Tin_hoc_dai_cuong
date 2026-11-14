#include <stdio.h>
#include <math.h>
int main(){
    char x;
    int value;
    printf("Nhap vao mot ki tu hexa: ");
    scanf("%c",&x);
    if(x>='0'&&x<='9') value=x-'0';
    else if(x>='a' && x<='f') value=x-'a'+10;
    else if(x>='A' && x<='F') value=x-'A'+10;
    else {
        printf("\n Ky tu khong hop le!");
        return 1;
    }
    printf("Gia tri trong he 10 tuong ung: %d",value);
  

    return 0;
}
