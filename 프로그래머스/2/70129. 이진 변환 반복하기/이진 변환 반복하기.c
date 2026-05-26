#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 10진수 → 2진수 문자열 변환
void to_binary(int n, char* buf) {
    char temp[20];
    int i = 0;
    
    while (n > 0) {
        temp[i++] = (n % 2) + '0';
        n /= 2;
    }
    temp[i] = '\0';
    
    // 뒤집기
    int len = strlen(temp);
    for (int j = 0; j < len; j++) {
        buf[j] = temp[len - 1 - j];
    }
    buf[len] = '\0';
}

int* solution(const char* s) {
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = 0; answer[1] = 0;
    
    // s를 복사 (const라서 직접 수정 불가)
    char cur[150001];
    strcpy(cur, s);
    
    while (strcmp(cur, "1") != 0) {
        
        int zero_count = 0;
        int one_count  = 0;
        
        // 0, 1 개수 세기
        for (int i = 0; cur[i] != '\0'; i++) {
            if (cur[i] == '0') zero_count++;
            else               one_count++;
        }
        
        answer[0]++;              // 변환 횟수
        answer[1] += zero_count;  // 제거된 0 누적
        
        // one_count → 2진수로 변환해서 cur 교체
        to_binary(one_count, cur);
    }
    
    return answer;
}
