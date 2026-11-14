#include <stdio.h>
#include <string.h>

// Hàm tính tiền điện
long long TienDien(int so_dien) {
    if (so_dien < 250)
        return (long long)so_dien * 2000;
    else if (so_dien <= 400)
        return (long long)so_dien * 3000;
    else if (so_dien <= 500)
        return (long long)so_dien * 4000;
    else
        return (long long)so_dien * 5000;
}

int main() {
    char ten[100][50];
    int so_dien[100];
    long long tien[100];
    int n = 0;

    // Nhập danh sách hộ gia đình
    while (n < 100) {
        printf("Nhap ten chu ho %d (hoac **** de ket thuc): ", n + 1);
        scanf("%s", ten[n]);
        if (strcmp(ten[n], "****") == 0) break;
        printf("Nhap so dien tieu thu: ");
        scanf("%d", &so_dien[n]);
        tien[n] = TienDien(so_dien[n]);
        n++;
    }

    // Tìm hộ trả tiền điện ít nhất
    int min_i = 0;
    for (int i = 1; i < n; i++)
        if (tien[i] < tien[min_i])
            min_i = i;
    printf("\nHo tra tien dien it nhat: %s - %d so - %lld dong\n",
           ten[min_i], so_dien[min_i], tien[min_i]);

    // Sắp xếp nổi bọt theo tiền tăng dần
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tien[j] > tien[j + 1]) {
                // Đổi tien
                long long tmp_t = tien[j]; tien[j] = tien[j+1]; tien[j+1] = tmp_t;
                // Đổi so_dien
                int tmp_s = so_dien[j]; so_dien[j] = so_dien[j+1]; so_dien[j+1] = tmp_s;
                // Đổi ten
                char tmp_n[50];
                strcpy(tmp_n, ten[j]); strcpy(ten[j], ten[j+1]); strcpy(ten[j+1], tmp_n);
            }
        }
    }

    // In danh sách sau sắp xếp
    printf("\nDanh sach sau sap xep:\n");
    printf("%-20s %10s %15s\n", "Ten chu ho", "So dien", "Tien phai tra");
    for (int i = 0; i < n; i++)
        printf("%-20s %10d %15lld\n", ten[i], so_dien[i], tien[i]);

    return 0;
}