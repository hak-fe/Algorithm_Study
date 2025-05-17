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

/*
	x의 개수 : n - 4
	n이 홀수인 경우와 짝수인 경우로 나눌 수 있다.
	1 1 x x x 3 7 - 홀수
	4 7 x x x x 3 7 -짝수
	나올 수 있는 경우
	1. 1~9 1~9 소수판별
	2. 1~9 0 소수 아님
	3, 0 1~9
	4, 0 0
	11 부터 97 까지의 소수 :
	11 13 17 19
	23 29
	31 37
	41 43 47
	53 59
	61 67
	71 73 79
	83 89
	97

	if(n이 홀수){
		if(A의 일의자리가 1)
			if(b의 십의자리가 1)
			1 3 1 3 1...
			else if(b의 십의자리가 3)
			1 7 3 7 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			1 3 1 3 7
			else // b의 십의자리가 9
			1 7 1 7 9
		else if(A의 일의자리가 3)
			if(b의 십의자리가 1)
			3 1 3 1 1...
			else if(b의 십의자리가 3)
			3 1 3 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			3 1 3 1 7
			else // b의 십의자리가 9
			3 1 3 1 9
		else if(A의 일의자리가 7)
			if(b의 십의자리가 1)
			7 1 3 1 1...
			else if(b의 십의자리가 3)
			7 1 3 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			7 1 3 1 7
			else // b의 십의자리가 9
			7 1 3 1 9
		else //A의 일의자리가 9
			if(b의 십의자리가 1)
			9 7 3 1 1...
			else if(b의 십의자리가 3)
			9 7 3 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			9 7 3 1 7
			else // b의 십의자리가 9
			9 7 3 1 9
	}
	else{
		if(A의 일의자리가 1)
			if(b의 십의자리가 1)
			1 1 1 1 1 1...
			else if(b의 십의자리가 3)
			1 1 1 1 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			1 1 1 1 1 7
			else // b의 십의자리가 9
			1 1 1 1 1 9
		else if(A의 일의자리가 3)
			if(b의 십의자리가 1)
			3 1 1 1 1 1...
			else if(b의 십의자리가 3)
			3 1 1 1 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			3 1 1 1 1 7
			else // b의 십의자리가 9
			3 1 1 1 1 9
		else if(A의 일의자리가 7)
			if(b의 십의자리가 1)
			7 1 1 1 1 1...
			else if(b의 십의자리가 3)
			7 1 1 1 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			7 1 1 1 1 7
			else // b의 십의자리가 9
			7 1 1 1 1 9
		else //A의 일의자리가 9
			if(b의 십의자리가 1)
			9 7 1 1 1 1...
			else if(b의 십의자리가 3)
			9 7 1 1 1 3
			else if(b의 십의자리가 5)
			-1
			else if(b의 십의자리가 7)
			9 7 1 1 1 7
			else // b의 십의자리가 9
			9 7 1 1 1 9
	}
*/

void func(int a, int b, int n);

int main() {
	FASTIO;
	int a, b, n;
	cin >> a >> b >> n;
	if ((b / 10) % 2 == 0 || b / 10 == 5) {
		cout << -1;
	}
	else {
		func(a, b, n);
	}
	return 0;
}

void func(int a, int b, int n) {
	string str;
	if (a % 10 == 1 || a % 10 == 3 || a % 10 == 7) {
		n = n - 4;
		str += to_string(a);
		for (int i = 0; i < n; i++)
		{
			str.push_back('1');
		}
		str += to_string(b);
	}
	else {
		n = n - 5;
		str += to_string(a);
		str.push_back('7');
		for (int i = 0; i < n; i++)
		{
			str.push_back('1');
		}
		str += to_string(b);
	}
	cout << str;
}