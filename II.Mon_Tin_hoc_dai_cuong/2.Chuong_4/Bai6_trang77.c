#include <ctype.h>
int main(){
    char c; int n, d;
    char ch;
    do{
        d=0; n=0; //Cập nhật lại d,n ở mỗi vong lặp mới
        while( (c=getchar()) !='*'){
            n++;
            if (c=='a') d++;
        }
        if(n==0)
            printf("Chuoi ky tu rong\n");
        else
            printf("Tan suat xuat hien ky tu 'a' la %5.2f%%\n",(float)100*d/n);
        printf("Tiep tuc <C/K>?: ");
        scanf("%s",&ch); //Hoặc ch=getchar();
        while ((getchar()) != '\n');
    }while(toupper(ch) != 'K');
    return 0;
}