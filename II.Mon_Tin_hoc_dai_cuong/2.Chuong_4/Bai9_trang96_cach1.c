#include <stdio.h>
int main() {
    int x, max, dem;
    /* Doc so dau tien de khoi tao max */
    printf("Nhap so: "); scanf("%d", &x);
    max = x;
    dem = 1;
    /* Doc tiep tuc cho den khi gap so duong chia het cho 5 */
    while (!(x > 0 && x % 5 == 0)) {
        printf("Nhap so: "); scanf("%d", &x);
        /* Cap nhat max va dem */
        if (x > max) {
            max = x;
            dem = 1;
        } else if (x == max) {
            dem++;
        }
    }
    printf("\nSo lon nhat: %d\n", max);
    printf("So lan xuat hien: %d\n", dem);
    return 0;
}