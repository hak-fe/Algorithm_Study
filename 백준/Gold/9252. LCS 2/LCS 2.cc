#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string X, Y;
    cin >> X >> Y;

    int m = X.size(), n = Y.size();
    vector<vector<int>> c(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1])
                c[i][j] = c[i-1][j-1] + 1;
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    cout << c[m][n] << "\n";

    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (X[i-1] == Y[j-1]) {
            lcs = X[i-1] + lcs;
            i--; j--;
        } else if (c[i-1][j] >= c[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }

    if (!lcs.empty()) cout << lcs;

    return 0;
}