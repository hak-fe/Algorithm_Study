#include <bits/stdc++.h>
using namespace std;

char arr[3072][6144];

void draw(int x, int y, int n) {
    if (n == 3) {
        arr[x][y] = '*';
        arr[x+1][y-1] = arr[x+1][y+1] = '*';
        for (int i = -2; i <= 2; i++) arr[x+2][y+i] = '*';
        return;
    }

    int m = n / 2;
    draw(x, y, m);
    draw(x + m, y - m, m);
    draw(x + m, y + m, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    memset(arr, ' ', sizeof(arr));

    draw(0, N - 1, N);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < 2*N; j++) {
            cout << arr[i][j];
        }
        cout << '\n';
    }
}