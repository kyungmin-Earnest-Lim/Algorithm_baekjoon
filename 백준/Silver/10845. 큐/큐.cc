// fisrt in first out

#include <queue>
#include <iostream>
#include <string>
using namespace std ;

int main() {
    ios::sync_with_stdio(0) ; cin.tie(0) ;
    
    int n ;
    cin >> n ;

    queue<int> Q ;

    while (n--) {
        string op ;
        cin >> op ;

        if (op == "push") {
            int num ;
            cin >> num ;

            Q.push(num) ;
        } else if (op == "pop") {
            if (Q.empty()) cout << -1 << '\n' ;
            else {
                cout << Q.front() << '\n' ;
                Q.pop() ;
            }
        } else if (op == "size") {
            cout << Q.size() << '\n' ;
        } else if (op == "empty") {
            cout << Q.empty() << '\n' ;
        } else if (op == "front") {
            if (Q.empty()) cout << -1 << '\n' ;
            else cout << Q.front() << '\n' ;
        } else if (op == "back") {
            if (Q.empty()) cout << -1 << '\n' ;
            else cout << Q.back() << '\n' ;
        }
    }
}