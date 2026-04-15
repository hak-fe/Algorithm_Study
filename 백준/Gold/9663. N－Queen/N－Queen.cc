#include <bits/stdc++.h>
using namespace std;

int n, ans;
bool col[15], diag1[30], diag2[30];

void dfs(int row) {
    if (row == n) {
        ans++;
        return;
    }

    for (int c = 0; c < n; c++) {
        if (col[c] || diag1[row + c] || diag2[row - c + n]) continue;

        col[c] = diag1[row + c] = diag2[row - c + n] = true;
        dfs(row + 1);
        col[c] = diag1[row + c] = diag2[row - c + n] = false;
    }
}

int main() {
    cin >> n;
    dfs(0);
    cout << ans;
}