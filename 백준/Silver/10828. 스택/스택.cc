#include <stack>
#include <iostream>
#include <string>

using namespace std ;

int n ;

int main(void) {
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    cin >> n ;
    stack<int> S ;

    while (n--) {
        string op ;
        cin >> op ;

        if (op == "push") {
            int num ;
            cin >> num ;

            S.push(num) ;
        } else if (op == "pop") {
            if (S.empty()) cout << -1 << '\n' ;
            else {
                cout << S.top() << '\n' ;
                S.pop() ;
            }
        } else if (op == "size") {
            cout << S.size() << '\n' ;
        } else if (op == "empty") {
            cout << S.empty() << '\n' ;
        } else if (op == "top") {
            if (S.empty()) cout << -1 << '\n' ;
            else cout << S.top() << '\n' ;
        }

    }
    return 0 ;
}