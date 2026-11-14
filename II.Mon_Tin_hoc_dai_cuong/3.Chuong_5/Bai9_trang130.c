#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 60
#define MAXCOLS  80

int main(){
    char vb[MAXLINES][MAXCOLS+1];
    int n = 0;
    char line[MAXCOLS+1];

    // Nhập văn bản
    printf("Nhap van ban (Enter 2 lan de ket thuc):\n");
    while(n < MAXLINES){
        fgets(line, MAXCOLS+1, stdin);
        line[strcspn(line, "\n")] = '\0';
        if(strlen(line) == 0) break;
        strcpy(vb[n++], line);
    }

    // -------- 2.1: Tìm vị trí xuất hiện của xâu s --------
    char s[50];
    printf("\n[2.1] Nhap xau can tim: ");
    fflush(stdin);
    fgets(s, 50, stdin);
    s[strcspn(s, "\n")] = '\0';

    printf("Vi tri xuat hien cua \"%s\":\n", s);
    int found = 0;
    for(int i = 0; i < n; i++){
        char *pos = vb[i];
        int col = 0;
        while((pos = strstr(pos, s)) != NULL){
            printf("  Dong %d, cot %d\n", i+1, (int)(pos - vb[i]) + 1);
            pos++;
            found = 1;
        }
    }
    if(!found) printf("  Khong tim thay!\n");

    // -------- 2.2: Thay "hanoi" -> "HANOI" --------
    printf("\n[2.2] Thay 'hanoi' bang 'HANOI':\n");
    for(int i = 0; i < n; i++){
        char temp[200] = "";
        char *cur = vb[i];
        char *pos;
        while((pos = strstr(cur, "hanoi")) != NULL){
            strncat(temp, cur, pos - cur);
            strcat(temp, "HANOI");
            cur = pos + 5; // 5 = strlen("hanoi")
        }
        strcat(temp, cur);
        strcpy(vb[i], temp);
    }
    printf("Van ban sau khi thay:\n");
    for(int i = 0; i < n; i++)
        printf("%s\n", vb[i]);

    // -------- 2.3: Đếm số từ --------
    printf("\n[2.3] So tu trong van ban:\n");
    int totalWords = 0;
    for(int i = 0; i < n; i++){
        int words = 0;
        int inWord = 0;
        for(int j = 0; vb[i][j] != '\0'; j++){
            if(vb[i][j] != ' '){
                if(!inWord){ words++; inWord = 1; }
            } else {
                inWord = 0;
            }
        }
        totalWords += words;
        printf("  Dong %d: %d tu\n", i+1, words);
    }
    printf("Tong so tu: %d\n", totalWords);

    // -------- 2.4: Tần xuất xuất hiện của các từ --------
    printf("\n[2.4] Tan xuat cac tu:\n");
    char words[500][50];
    int freq[500] = {0};
    int wCount = 0;

    for(int i = 0; i < n; i++){
        char temp[200];
        strcpy(temp, vb[i]);
        char *token = strtok(temp, " ");
        while(token != NULL){
            // Tìm từ đã có chưa
            int found2 = 0;
            for(int k = 0; k < wCount; k++){
                if(strcmp(words[k], token) == 0){
                    freq[k]++;
                    found2 = 1;
                    break;
                }
            }
            if(!found2){
                strcpy(words[wCount], token);
                freq[wCount++] = 1;
            }
            token = strtok(NULL, " ");
        }
    }

    for(int i = 0; i < wCount; i++)
        printf("  \"%s\": %d lan\n", words[i], freq[i]);

    return 0;
}