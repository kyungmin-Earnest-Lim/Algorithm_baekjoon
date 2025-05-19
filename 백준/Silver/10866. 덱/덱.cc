/*
    Deque 이고 양쪽 끝에서 삽입과 삭제가 가능하다.

    원소 추가 삭제가 O(1) 
    제일 앞/뒤 원소 확인 O(1) 
    제일 앞/뒤가 아닌 원소의 확인/변경이 원칙적으로 불가능하다
    그러나 stl deque에서는 인덱스로 접근이 가능하다

    const int MX = 1000005 ;
    int dat[2*MX + 1] ;
    int head = MX, tail = MX ;

    head와 tail을 MX로 둔 이유는 양방향에서 삽입 삭제가 가능하기 때문에
    한쪽 끝에서만 예를 들어 0으로 두면 한쪽으로의 전진밖에 안되기 때문에 큰일난다.


    stl deque를 보면 인덱스로 접근도 가능하고
    vector에서 가능했던 insert erase 도 O(N) 으로 가능하다. deque 와 마찬가지로

    그래서 deque가 vector보다 상위호환이 아닌가? 라고 생각할 수 있는데
    vector와 달리 deque는 메모리상에 모든 원소가 연속적으로 존재하지 않는다.

    앞 뒤에서 모두 추가 제거가 필요하다면 deque를 쓰면되고
    굳이 앞에서의 추가 삭제가 필요없다면 vector를 쓰면된다.

    vector는 메모리상 연속적이라서 cache hit rate가 높다.
*/

#include <iostream>
#include <deque>
#include <string>

using namespace std ;

int main(void) {
    int n ;
    cin >> n ;

    deque<int> dq ;

    while (n--) {
        string op ;
        cin >> op ;

        if (op == "push_front") {
            int x ;
            cin >> x ;

            dq.push_front(x) ;
        } else if (op == "push_back") {
            int x ;
            cin >> x ;

            dq.push_back(x) ;
        } else if (op == "pop_front") {
            if (dq.empty()) cout << -1 << '\n' ;
            else {
                cout << dq.front() << '\n' ;
                dq.pop_front() ;
            }
        } else if (op == "pop_back") {
            if (dq.empty()) cout << -1 << '\n' ;
            else {
                cout << dq.back() << '\n' ;
                dq.pop_back() ;
            }
        } else if (op == "size") cout << dq.size() << '\n' ;
        else if (op == "empty") cout << dq.empty() << '\n' ;
        else if (op == "front") {
            if (dq.empty()) cout << -1 << '\n' ;
            else cout << dq.front() << '\n' ;
        }
        else if (op == "back") {
            if (dq.empty()) cout << -1 << '\n' ;
            else cout << dq.back() << '\n' ;
        }
    }

    return 0 ;
}