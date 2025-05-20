#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include<algorithm>

#define DEBUG 1
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)

using namespace std;
typedef long long int ll;

int dice[10001][7];
int getMaxSumOfDice(int start, int height);

int main() {
	FASTIO;
	int n, res = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 6; j++)
			cin >> dice[i][j];
	
	res = getMaxSumOfDice(1, n);
	for (int i = 2; i <= 6; i++)
		res = max(res, getMaxSumOfDice(i, n));

	cout << res;

	return 0;
}

int getMaxSumOfDice(int start, int height) {
	// start == 1번 주사위의 윗면, height == 주사위 기둥의 높이
	int sum = 0, numOfFirstTopSide, numOfFirstBottomSide, previousTopSide;
	
	// 첫 주사위의 윗면, 아랫면 구하기
	for (int i = 1; i <= 6; i++)
	{
		if (dice[1][i] == start) {
			if (i == 1) {
				numOfFirstTopSide = dice[1][i]; 
				numOfFirstBottomSide = dice[1][6];
			}
			else if (i == 2) {
				numOfFirstTopSide = dice[1][i];
				numOfFirstBottomSide = dice[1][4];
			}
			else if (i == 3) {
				numOfFirstTopSide = dice[1][i];
				numOfFirstBottomSide = dice[1][5];
			}
			else if (i == 4) {
				numOfFirstTopSide = dice[1][i];
				numOfFirstBottomSide = dice[1][2];
			}
			else if (i == 5) {
				numOfFirstTopSide = dice[1][i];
				numOfFirstBottomSide = dice[1][3];
			}
			else {
				numOfFirstTopSide = dice[1][i];
				numOfFirstBottomSide = dice[1][1];
			}
		}
	} 

	//첫 주사위의 옆면 중 가장 큰 수 구하기
	for (int i = 1; i <= 6; i++)
	{
		if (dice[1][i] != numOfFirstTopSide && dice[1][i] != numOfFirstBottomSide)
			sum = max(sum, dice[1][i]);
	}

	previousTopSide = numOfFirstTopSide;
	// 2번 주사위 부터 차례대로 누적 합하기
	for (int i = 2; i <= height; i++)
	{
		int numOfTopSide, numOfBottomSide = previousTopSide;
		for (int j = 1; j <= 6; j++)
		{
			//아랫면이 나왔으니 윗면도 나온다.
			if (dice[i][j] == numOfBottomSide) {
				if (j == 1)
					numOfTopSide = dice[i][6];
				else if(j == 2)
					numOfTopSide = dice[i][4];
				else if (j == 3)
					numOfTopSide = dice[i][5];
				else if (j == 4)
					numOfTopSide = dice[i][2];
				else if (j == 5)
					numOfTopSide = dice[i][3];
				else
					numOfTopSide = dice[i][1];
			}
		}
		int tempMax = 0;
		//윗면과 아랫면을 구했으므로 나머지 4개의 수 중 최댓값 구해서 sum에 누적 합
		for (int j = 1; j <= 6; j++)
		{
			if (dice[i][j] != numOfTopSide && dice[i][j] != numOfBottomSide)
				tempMax = max(tempMax, dice[i][j]);
		}
		//현 주사위의 윗면 숫자를 저장. 다음 주사위의 아랫면이 될 숫자임.
		previousTopSide = numOfTopSide;
		sum += tempMax; // 누적 합
	}
	return sum;
}