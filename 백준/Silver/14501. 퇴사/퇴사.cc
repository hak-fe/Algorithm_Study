#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007

using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dp[22];
vector<int>tv;
vector<int>pv;
int main() {
    FASTIO;
    int n, t, p, maxP = 0;
    cin >> n;

    tv.push_back(0);
    pv.push_back(0);

    for (int i = 1; i <= n; i++)
    {
        cin >> t >> p;
        tv.push_back(t);
        pv.push_back(p);
    }

    for (int i = 1; i <= n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i]);
        dp[i + tv[i]] = max(dp[i] + pv[i], dp[i + tv[i]]);
        if (dp[i] > maxP)
            maxP = dp[i];
    }
    maxP = max(dp[n + 1], maxP);
    cout << maxP;
    return 0;
}