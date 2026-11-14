#include <stdio.h>
int T(int *x){
    ++*x;
    return *x;
}
int main() {
    int a=4;
    printf("%d %d",T(&a),T(&a));
    return 0;
}