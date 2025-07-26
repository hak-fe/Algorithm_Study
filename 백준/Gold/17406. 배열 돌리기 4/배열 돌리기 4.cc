#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10007
#define MAX 10000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

vector<char>temp;
vector<string>seq; // 만들 수 있는 모든 순서를 seq에 저장
int visited[7];
int arr[51][51], realarr[51][51], r[7], c[7], s[7], res = MAX;

string getStr(vector<char>v);
void getSeq(int size);
void spinArr(int x, int y, int maxlen);
void copyArr(int n, int m);
int getMinRowSum(int n, int m);

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			cin >> realarr[i][j];
		}
	}
	for (int i = 1; i <= k; i++)
	{
		cin >> r[i] >> c[i] >> s[i];
	}

	getSeq(k);

	for (int i = 0; i < seq.size(); i++)
	{
		copyArr(n, m);
		string str = seq[i];
		for (int j = 0; j < str.length(); j++)
		{
			int num = str[j] - '0',
				x = r[num] - s[num],
				y = c[num] - s[num],
				maxlen = (c[num] + s[num]) - (c[num] - s[num]) + 1;
			spinArr(x, y, maxlen);
		}
		int min = getMinRowSum(n, m);
		if (DEBUG) {
			cout << "seq " << i << "일때의 최솟값 : " << min << endl;
			cout << "돌린 후 배열\n\n";

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++) {
					cout << arr[i][j];
				}
				cout << endl;
			}

		}
		if (min < res)
			res = min;
	}
	cout << res;
	return 0;
}

string getStr(vector<char>v) {
	string str = "";
	for (int i = 0; i < v.size(); i++)
	{
		str.push_back(v[i]);
	}
	return str;
}
void getSeq(int size) {

	for (int i = 1; i <= size; i++)
	{
		if (temp.size() == size) {
			seq.push_back(getStr(temp));
			return;
		}
		if (!visited[i]) {
			visited[i] = 1;
			temp.push_back(i + '0');
			getSeq(size);
			visited[i] = 0;
			temp.pop_back();
		}
	}
	return;
}
void spinArr(int x, int y, int maxlen) {

	if (maxlen <= 1)
		return;

	int cordX = x + maxlen - 1, cordY = y + maxlen - 1;
	int corner[5]; // 각 모서리 값 저장, 2, 3, 4 모서리만 저장한다.
	corner[2] = arr[x][cordY];
	corner[3] = arr[cordX][cordY];
	corner[4] = arr[cordX][y];


	//1
	for (int i = cordY; i >= y + 1; i--)
	{
		arr[x][i] = arr[x][i - 1];
	}
	//2
	for (int i = cordX; i >= x + 2; i--)
	{
		arr[i][cordY] = arr[i - 1][cordY];
	}
	//3
	for (int i = y; i < cordY - 1; i++)
	{
		arr[cordX][i] = arr[cordX][i + 1];
	}
	//4
	for (int i = x; i < cordX - 1; i++)
	{
		arr[i][y] = arr[i + 1][y];
	}

	arr[x + 1][cordY] = corner[2];
	arr[cordX][cordY - 1] = corner[3];
	arr[cordX - 1][y] = corner[4];

	return spinArr(x + 1, y + 1, maxlen - 2);

}
void copyArr(int n, int m) {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			arr[i][j] = realarr[i][j];
}
int getMinRowSum(int n, int m) {
	int sum = 0, min = MAX;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++) {
			sum += arr[i][j];
		}
		if (sum < min)
			min = sum;
		sum = 0;
	}
	return min;
}