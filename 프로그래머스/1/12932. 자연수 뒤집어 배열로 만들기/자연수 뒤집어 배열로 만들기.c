#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    int len=0;
    for (long long i=n; i!=0; i/=10) {
        len++;
    }
    int* answer = (int*)malloc(sizeof(int) * len);
    for (int i=0; i<len; i++) {
        answer[i] = n%10;
        n/=10;
    }
    
    return answer;
}