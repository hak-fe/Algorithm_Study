#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 2001
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

int tomato[100][100][100];
int visited[100][100][100];

queue<tuple<int, int, int>>q;

int bfs(int h, int r, int c);

int main() {
    FASTIO;
    int m, n, h, res;
    cin >> m >> n >> h;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++) {
                cin >> tomato[i][j][k];
                if (tomato[i][j][k] == 1) {
                    q.push(make_tuple(i, j, k));
                    visited[i][j][k] = 1;
                }
            }
        }
    }

    res = bfs(h, n, m);
    cout << res;

    return 0;
}

int bfs(int h, int r, int c) {
    int days = 0;
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int z = get<0>(q.front()), x = get<1>(q.front()), y = get<2>(q.front());
            if (DEBUG) cout << z << ' ' << x << ' ' << y << " 큐에서 꺼내어 저장" << endl;
            q.pop();
            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k], ny = y + dy[k];

                if (nx < 0 || nx > r - 1 || ny < 0 || ny > c - 1) continue;

                if (tomato[z][nx][ny] != -1 && !visited[z][nx][ny]) {
                    q.push(make_tuple(z, nx, ny));
                    if (DEBUG) cout << z << ' ' << nx << ' ' << ny << " 큐에 저장(dx, dy)" << endl;
                    visited[z][nx][ny] = 1;
                    tomato[z][nx][ny] = 1;
                }
            }
            for (int k = 0; k < 2; k++) {
                int nz = z + dz[k];

                if (nz < 0 || nz > h - 1) continue;

                if (tomato[nz][x][y] != -1 && !visited[nz][x][y]) {
                    q.push(make_tuple(nz, x, y));
                    if (DEBUG) cout << nz << ' ' << x << ' ' << y << " 큐에 저장(dz)" << endl;
                    visited[nz][x][y] = 1;
                    tomato[nz][x][y] = 1;
                }
            }
        }
        if(!q.empty())
            days++;
    }

    //전부 익었는지 체크
    for (int i = 0; i < h; i++)
        for (int j = 0; j < r; j++)
            for (int k = 0; k < c; k++)
                if (tomato[i][j][k] == 0)
                    return -1;

    return days;
}