/**
 * 알고리즘 문제 풀이할 때
 * 1. 조건을 잘 정리하고
 * 2. 중간의 error 여부는 isvalid로 추척하고
 * 3. 출력을 여러번하면 복잡해지니까 isvalid를 통해서 예외의 경우 false로 입력 후,
 * 4. 마지막에 출력을 한번만 하는 방식을 쓰자.
 */

#include <stack>
#include <iostream>
#include <string>

using namespace std ;

int main(void) {
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;
    
    string st ;

    while (1) {
        getline(cin, st) ;
        if (st == ".") break ;

        stack<char> S ;
        bool isvalid = true ;

        for (const auto& s : st) {
            if (s == '(' || s == '[') {
                S.push(s) ;
            } else if (s == ')') {
                if (S.empty() || S.top() != '(') {
                    isvalid = false ;
                    break ;
                }
                S.pop() ;
            } else if (s == ']') {
                if (S.empty() || S.top() != '[') {
                    isvalid = false ;
                    break ;
                }
                S.pop() ;
            }
        }

        // 최종 판단은 여기서 한번만 출력

        if (isvalid && S.empty()) {
            cout << "yes" << '\n' ;
        } else {
            cout << "no" << '\n' ;
        }
    }

    return 0 ;
}