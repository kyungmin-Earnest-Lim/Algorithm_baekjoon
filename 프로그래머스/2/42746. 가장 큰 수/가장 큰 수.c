#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[20];
    char ba[20];
    
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    
    return strcmp(ba, ab);
}

char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    qsort(numbers, numbers_len, sizeof(int), compare);

    char* answer = (char*)malloc(4 * numbers_len + 1);
    answer[0] = '\0';
    
    for (int i=0; i<numbers_len; i++) {
        char temp[10];
        sprintf(temp, "%d", numbers[i]);
        strcat(answer, temp);
    }

    if (answer[0] == '0') {
        answer[0] = '0';
        answer[1] = '\0';
    }
    
    return answer;
}