#include <stdio.h>
#include <math.h>

float f(float x) {
    if (x >= -2 && x <= 2)
        return sqrt(exp(2*x + 1) + 1) + 7;
    else
        return x*x*x*x*x + 5*x*x*x + x + 1;
}

int main() {
    // Phần 2: Nhập x, y và tính (f(x)+f(y))^2
    float x, y;
    printf("Nhap x: "); scanf("%f", &x);
    printf("Nhap y: "); scanf("%f", &y);
    float tong = f(x) + f(y);
    printf("(f(x)+f(y))^2 = %.2f\n\n", tong * tong);

    // Phần 3: In bảng <x, f(x)> với x từ -5.0 đến 3.0, bước 0.1
    printf("x\t\tf(x)\n");
    for (x = -5.0; x <= 3.01; x += 0.1)
        printf("%.2f\t\t%.2f\n", x, f(x));

    return 0;
}