#include <iostream>
#include <map>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <set>
#include <math.h>
#include <stdlib.h>
#include <cstring>

#define DEBUG 0
#define endl '\n'
#define FASTIO cin.tie(NULL), ios_base::sync_with_stdio(false)
#define DIV 10000
#define MAX 100001
#define INF 2100000000
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int dx[4] = { -1, 0, 1, 0 };
int dy[4] = { 0, 1, 0, -1 };
int dz[2] = { 1, -1 };

int arr1[1002];
int arr2[1002];
int arr3[1002];

int main() {
	FASTIO;
	int n, p1, p2, p3, plus = 0;
	cin >> n;
    if (n == 1 || n == 2) {
		cout << 1;
        return 0;
    }
	p1 = 1;
	arr1[1] = 1;
	p2 = 1;
	arr2[1] = 1;
	p3 = 1;
	arr3[1] = 1;
    for (int i = 3; i <= n; i++) {
        // --- arr3 = arr1 + arr2 계산 ---
        memset(arr3, 0, sizeof(arr3)); // arr3 초기화
        int max_len = max(p1, p2);
        int carry = 0;

        for (int j = 1; j <= max_len; j++) {
            int sum = arr1[j] + arr2[j] + carry;
            arr3[j] = sum % 10;
            carry = sum / 10;
        }

        // 마지막 올림수 처리
        if (carry > 0) {
            arr3[max_len + 1] = carry;
            p3 = max_len + 1;
        }
        else {
            p3 = max_len;
        }

        // --- 다음 계산을 위해 배열 업데이트 (arr1=arr2, arr2=arr3) ---
        memset(arr1, 0, sizeof(arr1));
        for (int j = 1; j <= p2; j++) 
            arr1[j] = arr2[j];
        p1 = p2;

        memset(arr2, 0, sizeof(arr2));
        for (int j = 1; j <= p3; j++) 
            arr2[j] = arr3[j];
        p2 = p3;
    }
	for (int i = p3; i >= 1; i--)
	{
		cout << arr3[i];
	}
	return 0;
}