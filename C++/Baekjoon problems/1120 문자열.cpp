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

typedef unsigned long long int ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string x, y;
	int sizex, sizey, cnt = 0;

	cin >> x >> y;

	sizex = x.size();
	sizey = y.size();

	if (sizex == sizey) {
		for (int i = 0; i < sizex; i++)
		{
			if (x[i] != y[i])
				cnt++;
		}
		cout << cnt;
	}
	else {
		if (y.find(x) != -1) 
			cout << 0;
		else {
			int min = 999;
			for (int i = 0; i < sizey - sizex + 1; i++)
			{
				int temp = 0;
				for (int j = 0; j < sizex; j++)
				{
					if (x[j] != y[j + i])
						temp++;
				}
				if (temp < min) 
					min = temp;
			}
			cout << min;
		}
	}
}