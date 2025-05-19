#include <iostream>
#include <list>
#include <string>

using namespace std ;

int main(void) {
    ios::sync_with_stdio(0) ; cin.tie(0) ;

    list<char> L ;
    list<char>::iterator it ;

    string s ;
    cin >> s ;
    int n ;
    for (int i=0 ; i<s.size() ; i++) {
        L.push_back(s[i]) ;
    }

    it = L.end() ;

    int m ;
    cin >> m ;
    char op ;
    while(m--) {
        cin >> op ;
        if (op == 'P') {
            char a ;
            cin >> a ;
            L.insert(it, a) ;
        }
        else if (op == 'L') {
            if (it == L.begin()) continue ;
            else it-- ;
        }
        else if (op == 'D') {
            if (it == L.end()) continue ;
            else it++ ;
        }
        else {
            if (it == L.begin()) continue ;
            it-- ;
            it = L.erase(it) ;
        }
    }

    for (const auto& x : L) {
        cout << x ;
    }

    return 0 ;
}