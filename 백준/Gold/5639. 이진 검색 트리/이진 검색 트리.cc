#include <bits/stdc++.h>
using namespace std;

vector<int> pre;

void solve(int l, int r) {
    if (l >= r) return;

    int root = pre[l];
    int idx = l + 1;

    while (idx < r && pre[idx] < root) idx++;

    solve(l + 1, idx);
    solve(idx, r);

    cout << root << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int x;
    while (cin >> x) pre.push_back(x);

    solve(0, pre.size());
}