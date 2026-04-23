#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define MAX 201

using namespace std;

vector<vector<int>> city;
vector<int> plan;
vector<int>parent;
int find(int a) {
    if (parent[a] == a)
        return a;
    else
        return parent[a] = find(parent[a]);
}

void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a != b) parent[a] = b;
}

int main() {
    
    int n, m;
    cin >> n >> m;
    
    city.assign(n + 1, vector<int>(n + 1));
    parent.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        for (int j = 1; j <= n; j++)
        {
            cin >> city[i][j];
        }
    }
   
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (city[i][j]) 
                merge(i, j);
    
    for (int i = 1; i <= m; i++)
    {
        int temp;
        cin >> temp;
        plan.push_back(temp);
    }

    int temp = find(plan[0]);
    for (int i = 1; i < m; i++)
    {
        if (find(plan[i]) != temp) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}