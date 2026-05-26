#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(long long n) {
    int len = 0;
    for (long long i=n; i > 0; i/=10) {
        len++;
    }
    
    int* answer = (int*)malloc(len * sizeof(int));
    
    for (int i=0; i<len; i++) {
        answer[i] = n % 10;
        n /= 10;
    }
    return answer;
}