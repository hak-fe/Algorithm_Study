#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<int,int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 1; len < n; len++) {
        for (int i = 0; i + len < n; i++) {
            int j = i + len;
            dp[i][j] = 1e9;

            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j],
                    dp[i][k] + dp[k+1][j] + a[i].first * a[k].second * a[j].second);
            }
        }
    }

    cout << dp[0][n-1];
}