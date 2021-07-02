#include <iostream>
#include <cmath>
using namespace std;
int sosu[1000001] = {0,};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;
	int temp1 = M;
	int temp2 = N;
	int size = N - M + 1;

	for (int i = M; i <= N; i++)
	{
		sosu[i] = i;
	}

	if (M == 1)
		sosu[1] = 0;

	for (int i = 2; i <= (int)sqrt(N); i++)
	{
		for (int j = i*i; j <= N; j+=i)
		{
			if (sosu[j] == 0)
				continue;
			sosu[j] = 0;
		}
	}

	for (int i = M; i <=N; i++)
	{
		if (sosu[i] != 0)
			cout << sosu[i] << '\n';
	}
}
