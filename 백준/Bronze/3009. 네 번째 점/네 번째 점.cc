#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int ansX, ansY, temp, smallCnt = 0, largeCnt = 0;
	vector<int> vofx;
	vector<int> vofy;
	for (int i = 0; i < 3; i++)
	{
		cin >> temp;
		vofx.push_back(temp);
		cin >> temp;
		vofy.push_back(temp);
	}
	//x좌표 구하기
	if (vofx[0] == vofx[1])
		ansX = vofx[2];
	else if (vofx[1] == vofx[2])
		ansX = vofx[0];
	else 
		ansX = vofx[1];
	//y좌표 구하기
	if (vofy[0] == vofy[1])
		ansY = vofy[2];
	else if (vofy[1] == vofy[2])
		ansY = vofy[0];
	else
		ansY = vofy[1];

	cout << ansX << ' ' << ansY;
	return 0;
}