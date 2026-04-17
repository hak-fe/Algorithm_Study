#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N; cin >> N;
    vector<int> lis;
    for(int i=0; i<N; i++) {
        int num; cin >> num;
        if(lis.empty() || lis.back() < num) lis.push_back(num);
        else *lower_bound(lis.begin(), lis.end(), num) = num;
    }
    cout << lis.size();
}