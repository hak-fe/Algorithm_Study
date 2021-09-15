#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <stack>
#include <queue>
#include <deque>
using namespace std;

char ch[1000][1000]; // 복원할 작품을 담을 공간 생성

int main()
{
	int n, m;
	cin >> n >> m; //n, m 입력 받기

	for (int i = 0; i < 3 * n; i++)
		for (int j = 0; j < 3 * m;j++)
			cin >> ch[i][j]; // 작품 입력 받기

	for (int i = 1; i < 3 * n - 1; i++)
	{
		for (int j = 1; j < 3 * m - 1; j++)
		{
			if (i % 3 == 1 && j % 3 == 1) 
			//현재 인덱스가 각 문양의 중앙에 위치 하는지 확인함.
			{
				ch[i][j] = '#';
				if (ch[i][j] == '#' && ch[i][j + 1] == '#')
					//인덱스가 중앙에 있고, 그 곳의 문자가 # 이며, 오른쪽에 #이 존재한다면
					// 이어줘야 하므로 오른쪽으로 2칸 째에 #을 넣는다.
				{
					ch[i][j + 2] = '#';
				}
				if (ch[i][j] == '#' && ch[i][j - 1] == '#')
					//인덱스가 중앙에 있고, 그 곳의 문자가 # 이며, 왼쪽에 #이 존재한다면
					// 이어줘야 하므로 왼쪽으로 2칸 째에 #을 넣는다.
				{
					ch[i][j - 2] = '#';
				}
				if (ch[i][j] == '#' && ch[i + 1][j] == '#')
					//인덱스가 중앙에 있고, 그 곳의 문자가 # 이며, 위에 #이 존재한다면
					// 이어줘야 하므로 위로 2칸 째에 #을 넣는다.
				{
					ch[i + 2][j] = '#';
				}
				if (ch[i][j] == '#' && ch[i - 1][j] == '#')
					//인덱스가 중앙에 있고, 그 곳의 문자가 # 이며, 아래에 #이 존재한다면
					// 이어줘야 하므로 아래로 2칸 째에 #을 넣는다.
				{
					ch[i - 2][j] = '#';
				}
			}
		}
	}
	for (int i = 0; i < 3 * n; i++) {
		for (int j = 0; j < 3 * m; j++) {
			cout << ch[i][j];
		}
		cout << '\n';
	}
}
