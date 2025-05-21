#include <iostream>
#include <queue>
#include <utility>
#include <string>

#define X first
#define Y second

using namespace std ;

string board[110] ;
int dist[110][110] ;

int n, m ;
int dx[4] = {1, 0, -1, 0} ;
int dy[4] = {0, 1, 0 ,-1} ;

int main() {
    cin >> n >> m ;

    for (int i=0 ; i<n ; i++) {
        cin >> board[i] ;

        for (int j=0 ; j<m ; j++) {
            if (board[i][j] != '1')  dist[i][j] = -1 ;
        }
    }

    queue<pair<char, char>> Q ;
    Q.push({0, 0}) ;
    dist[0][0] = 1 ;
    
    while (!Q.empty()) {
        auto cur = Q.front() ; Q.pop() ;

        for (int dir=0 ; dir<4 ; dir++) {
            int nx = cur.X + dx[dir] ;
            int ny = cur.Y + dy[dir] ;

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny] != '1' || dist[nx][ny] > 0) continue;

            Q.push({nx, ny}) ;
            dist[nx][ny] += dist[cur.X][cur.Y] + 1;
        }
    }

    cout << dist[n-1][m-1] ;

}
