#include <stdio.h>
#include <math.h>
#include <string.h>
typedef struct{
    char ten[10];
    double x,y;
}Diem;

double kc(Diem A, Diem B){
    double kc=sqrt((B.x-A.x)*(B.x-A.x)+(B.y-A.y)*(B.y-A.y));
    return kc;
}
int main() {
    int N; 
    do{
    printf("Nhập số lượng điểm N>=2: "); 
    scanf("%d",&N);
    }while(N<2);
    while(getchar()!='\n'); //xóa bộ đệm
    Diem arr[N];    
    int i;
    for(i=0;i<N;i++){
        printf("Nhập tên điểm thứ %d:",i+1);
        fgets(arr[i].ten,sizeof(arr[i].ten),stdin);
        // Xóa ký tự '\n' do fgets tự động nhận vào nếu có 
        arr[i].ten[strcspn(arr[i].ten, "\n")] = '\0'; //Bắt buộc phải để "\n" vì hàm strcspn yêu cầu như vậy, không được để '\n'
        // Tìm vị trí của ký tự \n và cắt chuỗi bằng cách đặt ký tự kết thúc chuỗi \0 vào đó
        //-> đến lúc in ra kết quả thì 2 điểm sẽ ở trên cùng 1 dòng, không bị trường hợp 1 điểm ở dòng trên, 1 điểm ở dòng dưới
        printf("Nhập tọa độ x,y: "); scanf("%lf %lf",&arr[i].x,&arr[i].y);
        while(getchar()!='\n'); //xóa bộ đệm
    }
    // Tìm 2 điểm có khoảng cách lớn nhất
    double max=-1;
    int h=0,k=0; //lưu trữ chỉ số của 2 điểm có khoảng cách xa nhất
    int j;
    for(i=0;i<N;i++){
        for(j=i+1;j<N;j++){
            double kc1=kc(arr[i],arr[j]);
            if(max<kc1){
                max=kc1;
                h=i,k=j;
            }
        }
    }
    printf("Hai điểm có khoảng cách lớn nhất là: %s(%lf,%lf),%s(%lf,%lf)\n",arr[h].ten,arr[h].x,arr[h].y,arr[k].ten,arr[k].x,arr[k].y);
    printf("Khoảng cách đó là: %lf",max);


    return 0;
}