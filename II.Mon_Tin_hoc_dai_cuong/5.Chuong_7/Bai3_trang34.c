#include <stdio.h>
#include <math.h>

double f(double x) {
    double ax = fabs(x);
    if (ax < 2)
        return cbrt(4 - x*x) + 1;      // căn bậc 3
    else if (ax == 2)
        return 7;
    else
        return exp(x*x*x + 1) + log(x*x - 1) / log(5);  // log5(x²-1)
}

int main() {
    // Phần 2: Nhập N số, tìm max f(x)
    int N;
    printf("Nhap N: ");
    scanf("%d", &N);

    double max_f, x;
    for (int i = 0; i < N; i++) {
        printf("Nhap x[%d]: ", i + 1);
        scanf("%lf", &x);
        double fx = f(x);
        if (i == 0 || fx > max_f)
            max_f = fx;
    }
    printf("Gia tri lon nhat cua f(x): %.6f\n\n", max_f);

    // Phần 3: Nhập dãy đến khi đủ 100 số HOẶC gặp x có f(x) > max_f
    printf("Nhap day so (toi da 100, dung neu f(x) > %.6f):\n", max_f);
    int count = 0;
    while (count < 100) {
        printf("Nhap x: ");
        scanf("%lf", &x);
        double fx = f(x);
        count++;
        if (fx > max_f) {
            printf("=> f(%.6f) = %.6f > %.6f. Dung lai!\n", x, fx, max_f);
            break;
        }
    }
    printf("Da nhap %d so.\n", count);

    return 0;
}