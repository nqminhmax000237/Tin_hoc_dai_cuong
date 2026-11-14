#include <stdio.h>
#include <string.h>

int main(){
    char S1[100], S2[200];
    int k, lenS1, lenS2;

    printf("Nhap S1: "); fgets(S1, 100, stdin);
    S1[strcspn(S1, "\n")] = '\0';

    printf("Nhap S2: "); fgets(S2, 200, stdin);
    S2[strcspn(S2, "\n")] = '\0';

    printf("Nhap k: "); scanf("%d", &k);

    lenS1 = strlen(S1);
    lenS2 = strlen(S2);

    // Giới hạn k
    if(k > lenS2) k = lenS2;
    if(k < 0) k = 0;

    // Dịch phần sau vị trí k sang phải lenS1 ký tự
    for(int i = lenS2; i >= k; i--)
        S2[i + lenS1] = S2[i];

    // Chép S1 vào vị trí k
    for(int i = 0; i < lenS1; i++)
        S2[k + i] = S1[i];

    printf("Ket qua: %s\n", S2);
    return 0;
}