#include <stdio.h>
#include <stdlib.h> // Thư viện để dùng hàm abs() lấy giá trị tuyệt đối

// Hàm tìm UCLN nhanh nhất
long long tim_ucln(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return abs(a);
}

// Hàm tìm BCNN tối ưu, tránh tràn số
long long tim_bcnn(long long a, long long b) {
    if (a == 0 || b == 0) return 0;
    return (abs(a) / tim_ucln(a, b)) * abs(b);
}

int main() {
    long long a = 123456, b = 789012;
    
    printf("UCLN cua %lld va %lld la: %lld\n", a, b, tim_ucln(a, b));
    printf("BCNN cua %lld va %lld la: %lld\n", a, b, tim_bcnn(a, b));
    
    return 0;
}
