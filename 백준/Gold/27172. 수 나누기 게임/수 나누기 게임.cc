#include<bits/stdc++.h>
using namespace std;

#define MAX 2100000000
#define DIV 1000000007
#define FASTIO ios::sync_with_stdio(false), cin.tie(NULL)
#define endl '\n'

typedef unsigned long long ull;
typedef long long ll;

vector<int>numbers(1000001);
vector<int>input(100000);
int main() {
	FASTIO;
	int n, temp;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		input[i] = temp;

		// temp의 배수
		for (int j = temp + temp; j <= 1000000; j += temp)
			numbers[j] += -1;
		// temp의 약수
		for (int j = 1; j * j <= temp; j++) {
			if (temp != 1 && !(temp % j)) {
				numbers[j]++;
				//cout << temp << "의 약수 : " << j;
				if (j != 1 && j * j != temp) {
					numbers[temp / j]++;
					//cout << ", " << temp / j;
				}
				//cout << endl;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << numbers[input[i]] << ' ';
	}
	return 0;
}