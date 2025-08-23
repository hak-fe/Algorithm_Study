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

void func(int n, int m, int depth);
int check();
void printSeq();
vector<int>v;
vector<int>temp;

int main() {
    int n, m;
    cin >> n >> m;

    v.assign(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    func(n, m, 1);

    return 0;
}

void func(int n, int m, int depth) {
    for (int i = 0; i < v.size(); i++)
    {
        temp.push_back(v[i]);
        if (m == depth) {
            if (check())
                printSeq();
        }
        else
            func(n, m, depth + 1);
        if(!temp.empty())
            temp.pop_back();
    }
}
int check() {
    for (int i = 0; i < temp.size() - 1; i++)
        if (temp[i] > temp[i + 1])
            return 0;
    return 1;
}

void printSeq() {
    for (int i = 0; i < temp.size(); i++) 
        cout << temp[i] << ' ';
    cout << endl;
}