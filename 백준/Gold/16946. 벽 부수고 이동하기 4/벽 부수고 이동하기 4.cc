#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int N, M;
string board[1000];
int group[1000][1000];
vector<int> groupSize;
int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

void bfs(int sx, int sy, int gId) {
    queue<pair<int, int>> q;
    q.push({sx, sy}); group[sx][sy] = gId;
    int cnt = 1;
    while(!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for(int i=0; i<4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx>=0 && nx<N && ny>=0 && ny<M && board[nx][ny]=='0' && group[nx][ny]==0) {
                group[nx][ny] = gId;
                q.push({nx, ny});
                cnt++;
            }
        }
    }
    groupSize.push_back(cnt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N >> M;
    for(int i=0; i<N; i++) cin >> board[i];
    
    groupSize.push_back(0); // 1-based index 
    int gId = 1;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == '0' && group[i][j] == 0) bfs(i, j, gId++);
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            if(board[i][j] == '1') {
                set<int> adjGroups;
                for(int d=0; d<4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx>=0 && nx<N && ny>=0 && ny<M && board[nx][ny]=='0')
                        adjGroups.insert(group[nx][ny]);
                }
                int sum = 1;
                for(int id : adjGroups) sum += groupSize[id];
                cout << sum % 10;
            } else {
                cout << 0;
            }
        }
        cout << "\n";
    }
}