/**
 * 알고리즘 문제 풀이할 때
 * 1. 조건을 잘 정리하고
 * 2. 중간의 error 여부는 isvalid로 추척하고
 * 3. 출력을 여러번하면 복잡해지니까 isvalid를 통해서 예외의 경우 false로 입력 후,
 * 4. 마지막에 출력을 한번만 하는 방식을 쓰자.
 */

 #include <iostream>
 #include <queue>
 #include <utility>
 
 #define X first
 #define Y second
 
 using namespace std ;
 
 int m, n ;
 int board[1010][1010] ;
 int dist[1010][1010] ;
 
 int dx[4] = {1, 0, -1, 0} ;
 int dy[4] = {0, 1, 0, -1} ;
 
 int main(void) {
     ios::sync_with_stdio(0) ;
     cin.tie(0) ; cout.tie(0) ;
 
     cin >> m >> n ;
 
     queue<pair<int, int>> Q ;
 
     for (int i=0 ; i<n ; i++) {
         for (int j=0 ; j<m ; j++) {
             cin >> board[i][j] ;
 
             if (board[i][j] == 1) {
                 Q.push({i, j}) ;
             }
 
             if (board[i][j] == 0) {
                 dist[i][j] = -1 ;
             }
         }
     }
 
     while (!Q.empty()) {
         auto cur = Q.front() ; Q.pop() ;
 
         for (int dir=0 ; dir<4 ; dir++) {
             int nx = cur.X + dx[dir] ;
             int ny = cur.Y + dy[dir] ;
 
             if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue ;
             if (dist[nx][ny] >= 0) continue ;
 
             Q.push({nx, ny}) ;
             dist[nx][ny] = dist[cur.X][cur.Y] + 1 ;
         }
     }
 
     int mx = 0 ;
     for (int i=0 ; i<n ; i++) {
         for (int j=0 ; j<m ; j++) {
             //mx = max(mx, dist[i][j]) ;
 
             if (dist[i][j] == -1) {
                 cout << -1 << '\n' ;
                 return 0 ;
             }

             mx = max(mx, dist[i][j]) ;

         }
     }
 
     cout << mx << '\n' ;
 
 
 }