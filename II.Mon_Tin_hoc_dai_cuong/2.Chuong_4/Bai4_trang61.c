#include <stdio.h>
#include <ctype.h>

int main(){
    int pa, na, kt;
    pa=na=kt=0;
    char c;
    printf(">");
    while( (c=getchar()) !='\n'){
        c=toupper(c);
        if( c=='U'||c=='E'||c=='O'||c=='A'||c=='I') na++;
        else if (c>='A' && c<='Z') pa++;
        else if (c==' ') kt++;
        
    }
    printf("Chuoi co: %d nguyen am, %d phu am, %d khoang trang \n ", na, pa, kt);

return 0;
}