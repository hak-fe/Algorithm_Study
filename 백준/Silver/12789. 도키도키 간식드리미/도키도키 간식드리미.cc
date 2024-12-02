#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, tmp, order = 1;
	cin >> n;
	queue<int>q;
	stack<int>st;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		q.push(tmp);
	}
	while (!q.empty() || !st.empty())
	{
		if (!q.empty() && !st.empty()) {
			if (st.top() == order) {
				order++;
				st.pop();
			}
			else if (q.front() == order) {
				order++;
				q.pop();
			}
			else {
				st.push(q.front());
				q.pop();
			}
		}
		else if (!q.empty()) {
			if (order == q.front()) {
				q.pop();
				order++;
			}
			else{
				st.push(q.front());
				q.pop();
			}
		}
		else {
			if (order == st.top()) {
				st.pop();
				order++;
			}
			else {
				cout << "Sad";
				return 0;
			}
		}
	}
	cout << "Nice";
	return 0;
}