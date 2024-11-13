#include <iostream>
#include <stack>
#include <string>
using namespace std;
/*
add x: S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
remove x: S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
check x: S에 x가 있으면 1을, 없으면 0을 출력한다. (1 ≤ x ≤ 20)
toggle x: S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
all: S를 {1, 2, ..., 20} 으로 바꾼다.
empty: S를 공집합으로 바꾼다.
*/
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int set[21] = {0};
	int m, num;
	string order;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> order;
		if (order != "all" && order != "empty")
			cin >> num;

		if (order == "add") {
			set[num] = 1;
		}
		else if (order == "remove") {
			set[num] = 0;
		}
		else if (order == "check")
		{
			if (set[num] == 1)
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (order == "toggle") {
			if (set[num] == 1)
				set[num] = 0;
			else
				set[num] = 1;
		}
		else if (order == "all") {
			for (int i = 1; i <= 20; i++)
				set[i] = 1;
		}
		else {
			for (int i = 1; i <= 20; i++)
				set[i] = 0;
		}
	}
	return 0;
}