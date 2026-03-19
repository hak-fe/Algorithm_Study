#include<iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include<tuple>
using namespace std;

#define MAX 1000000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

ll max(ll a, ll b) { return (a > b ? a : b); }
vector<int>seq;
int main() {
	FASTIO;
	int n, s, sum = 0, length, start = 0;
	cin >> n >> s;
	length = MAX;
	seq.assign(n, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> seq[i];
	}

	// n2 x , n logn 으로, n부터 m까지 일정 구간의 누적합을 이용?
	// n부터 m까지 누적합을 구해서 S 이상이 되는 경우, 길이 경신, 
	// 그리고 n부터 하나씩 빼보는거임. m까지 빼보면서 s 이상이면 또 거리 경신
	// 계속 반복.. 이 아이디어로 하면 되지 않을까?

	for (int end = 0; end < n;)
	{
		if (sum + seq[end] < s) {
			sum += seq[end];
			end++;
		}
		else {
			length = min(length, end - start + 1);
			sum -= seq[start];
			start++;
		}
	}
	if (length == MAX) cout << 0;
	else cout << length;
	return 0;
}