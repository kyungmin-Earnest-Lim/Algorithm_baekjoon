#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int compare(const void* a, const void* b) {
    char ab[10], ba[10];
    sprintf(ab, "%d%d", *(int*)a, *(int*)b);
    sprintf(ba, "%d%d", *(int*)b, *(int*)a);
    return strcmp(ba, ab);
}

char* solution(int numbers[], size_t numbers_len) {
    qsort(numbers, numbers_len, sizeof(int), compare);
    char* answer = (char*)malloc(4 * numbers_len + 1);
    answer[0] = '\0';
    
    char temp[10];
    for (int i=0; i<numbers_len; i++) {
        sprintf(temp, "%d", numbers[i]);
        strcat(answer, temp);
    }
    
    if (answer[0] == '0') {
        answer[0] = '0';
        answer[1] = '\0';
    }
    
    return answer;
}