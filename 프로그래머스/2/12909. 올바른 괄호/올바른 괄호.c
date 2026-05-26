#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100000
char stack[MAX+1];
int top = -1;

void push(const char c) {
    stack[++top] = c;
}

char pop(void) {
    return stack[top--];
}

void print_stack(void) {
    for (int i=top; i>=0; i--) {
        printf("[%c] ", stack[i]);
    }
}

int is_empty(void) {
    return top == -1;
}
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
bool solution(const char* s) {
    top = -1;
    int len = strlen(s);
    
    for (int i=0; i<len; i++) {
        if (s[i] == '(') push(s[i]);
        else {
            if (is_empty()) return false;
            pop();
        }
    }
    
    return is_empty();
}