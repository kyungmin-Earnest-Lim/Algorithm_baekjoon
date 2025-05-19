#include <queue>
#include <iostream>
#include <utility>

#define X first
#define Y second

using namespace std ;

int board[505][505] ;
bool visited[505][505] ;

int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, 1, 0, -1} ;

int n, m ;

int main(void) {
    ios::sync_with_stdio(0) ;
    cin.tie(0) ;

    cin >> n >> m ;

    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            cin >> board[i][j] ;
        }
    }

    

    int num = 0, mx = 0 ;
    for (int i=0 ; i<n ; i++) {
        for (int j=0 ; j<m ; j++) {
            
            if (visited[i][j] || board[i][j] != 1) continue ;
            
            num++ ;
            queue<pair<int, int>> Q ;
            Q.push({i, j}) ;
            visited[i][j] = 1 ;

            int area = 1 ;
            while (!Q.empty()) {
                // pair<int, int> cur = Q.front() ;
                auto cur = Q.front() ; Q.pop() ;
        
                for (int dir=0 ; dir<4 ; dir++) {
                    int nx = cur.X + dx[dir] ;
                    int ny = cur.Y + dy[dir] ;
                    
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if (visited[nx][ny] || board[nx][ny] != 1) continue;
                    
                    Q.push({nx, ny}) ;
                    visited[nx][ny] = 1 ;
                    area++ ;
                }
            }
            mx = max(mx, area) ;

        }
    }

    cout << num << '\n' << mx ;
    

}