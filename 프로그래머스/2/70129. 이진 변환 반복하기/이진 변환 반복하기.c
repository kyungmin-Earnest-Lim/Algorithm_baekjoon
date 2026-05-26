#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void to_binary(int n, char* buf) {
    char temp[20];
    int i=0;
    while (n>0) {
        temp[i++] = n % 2 + '0';
        n /= 2;
    }
    temp[i] = '\0';
    
    int len = strlen(temp);
    
    for (int j=0; j<len; j++) {
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';
    
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0; answer[1] = 0;
    
    char cur[150001];
    strcpy(cur, s);
    
    while (strcmp(cur, "1") != 0) {
        int zero_count = 0;
        int one_count = 0;
        
        for (int i=0; cur[i] != '\0'; i++) {
            if(cur[i] == '1') one_count++;
            else zero_count++;
        }
        
        answer[0]++;
        answer[1] += zero_count;
        to_binary(one_count, cur);
    }
    return answer;
}