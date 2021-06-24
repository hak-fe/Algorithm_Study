#include <iostream>
using namespace std;

int main(void) {

	int n;
	char arr[101];
	int sum = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		sum += arr[i] - '0'; 
		// arr[i]에는 아스키코드 형태로 저장되므로 0을 빼주면 10진수로 입력한 값과 똑같이 나온다.
		//Ex) arr[0]에 7을 입력했더라도 7의 아스키코드 값인 55로 저장이 되므로 '0'을 빼줘서
		//10진수 형태의 7로 바꾸어 준다.
	}
	cout << sum;
}
