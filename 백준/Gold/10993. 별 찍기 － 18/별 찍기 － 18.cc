#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cmath>
#define DEBUG 1
#define STAR '*'
using namespace std;
typedef long long int ll;
char stars[2500][2500];
void recStars(int n, int r, int c) {
    if (n == 1) {
        stars[c][r] = '*';
        return;
    }

    int col = pow(2, n + 1) - 3;
    int row = pow(2, n) - 1;

    if (n % 2 == 0) {
        for (int i = r; i < col + r; i++) {
            stars[c][i] = '*';
        }
        for (int i = 1; i < row; i++) {
            stars[c + i][r + i] = '*';
            stars[c + i][r + col - i - 1] = '*';
        }
        recStars(n - 1, pow(2, n - 1) + r, c + 1);
    }
    else {
        for (int i = r; i < col + r; i++) {
            stars[c + row - 1][i] = '*';
        }
        for (int i = 0; i < row; i++) {
            stars[c + i][r + col / 2 - i] = '*';
            stars[c + i][r + col / 2 + i] = '*';
        }
        recStars(n - 1, pow(2, n - 1) + r, row / 2 + c);
    }
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    if (n == 1) {
        cout << STAR;
        return 0;
    }

    int row = pow(2, n) - 1;
    int col = pow(2, n + 1) - 3;
    
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            stars[i][j] = ' ';

    recStars(n, 0, 0);

    if (n % 2 == 0) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col - i; j++) {
                cout << stars[i][j];
            }
            cout << '\n';
        }
    }
    else {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col - row + i + 1; j++) {
                cout << stars[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}