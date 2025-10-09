#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <cstring>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

int main() {
	FASTIO;
	int n;
	string str, res;
	cin >> n >>  str;
	
    for (int i = 0; i < n; ) { 
        if (i + 1 < n && str[i] == 'P' && str[i + 1] == 'S') {
            res += "PS";
            i += 2;

            while (i < n && (str[i] == '4' || str[i] == '5')) {
                i++;
            }
        }
        else {
            res += str[i];
            i++;
        }
    }
	cout << res;
	return 0;
}
