#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
vector<string> v;
string temp;
void hanoi(int n, char start, char mid, char end, int* cnt) {
	if (n == 1) // 원판이 하나면 바로 3으로 옮김
	{
		temp += start;
		temp += ' ';
		temp += end;
		v.push_back(temp);
		(*cnt)++;
		temp.clear();
	}
	else
	{
		hanoi(n - 1, start, end, mid, cnt);
		temp += start;
		temp += ' ';
		temp += end;
		v.push_back(temp);
		(*cnt)++;
		temp.clear();
		hanoi(n - 1, mid, start, end, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	hanoi(n, '1', '2', '3', &cnt);
	cout << cnt << '\n';
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << '\n';
	return 0;
}