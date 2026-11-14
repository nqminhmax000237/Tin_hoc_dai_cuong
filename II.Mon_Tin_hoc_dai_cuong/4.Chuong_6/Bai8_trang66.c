#include <stdio.h>
#include <string.h>
typedef struct{
    char name[50];
    char id[15];
    float gpa;
}Student;
int main() {
    int N;
    do{
    printf("Nhap so sinh vien: "); scanf("%d",&N);
    }while(N<=0);
    Student s[N];
    while(getchar()!='\n'); //xóa bộ đệm
    //Nhap thong tin cho cac sinh vien
    int i;
    for(i=0;i<N;i++){
        printf("Nhap ten sinh vien thu %d: ",i+1);
        fgets(s[i].name,sizeof(s[i].name),stdin);
        // Xóa ký tự '\n' do fgets tự động nhận vào nếu có 
        s[i].name[strcspn(s[i].name,"\n")]='\0';//Bắt buộc phải để "\n" vì hàm strcspn yêu cầu như vậy, không được để '\n'
        // Tìm vị trí của ký tự \n và cắt chuỗi bằng cách đặt ký tự kết thúc chuỗi \0 vào đó
        //-> đến lúc in ra kết quả thì 2 điểm sẽ ở trên cùng 1 dòng, không bị trường hợp 1 điểm ở dòng trên, 1 điểm ở dòng dưới

        printf("Nhap MSSV: "); scanf("%s",s[i].id); //id không cần dấu & vì nó là mảng--> giống con trỏ rồi
        printf("Nhap gpa: "); scanf("%f",&s[i].gpa);
        while(getchar()!='\n'); //xóa bộ đệm
    }

    //In thông tin ra
    printf("Ho va ten                  MSSV           Gpa\n");
    for(i=0;i<N;i++){
        printf("%-25s %-15s %-5.2f\n",s[i].name,s[i].id,s[i].gpa);
    }
    return 0;
}