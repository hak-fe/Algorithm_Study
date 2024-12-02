#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long int ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	stack<int>st;
	int n, order, num;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> order;
		switch (order) {
			case 1:
				cin >> num;
				st.push(num);
				break;
			case 2:
				if (st.empty())
					cout << -1 << '\n';
				else {
					cout << st.top() << '\n';
					st.pop();
				}
				break;
			case 3:
				cout << st.size() << '\n';
				break;
			case 4:
				if (st.empty())
					cout << 1 << '\n';
				else
					cout << 0 << '\n';
				break;
			default:
				if (st.empty())
					cout << -1 << '\n';
				else 
					cout << st.top() << '\n';
		}
	}
	return 0;
}
