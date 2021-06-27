#include <iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int min = 1000001;
	bool itHasMin = false;
	for (int i = 1; i <= n; i++) //i가 곧 생성자다.
	{
		bool istrue = false;
		int result = 0; // 생성자를 저장할 변수
		int digit = 0; // 자릿수 저장할 변수
		for (int j = i; j != 0; j/=10) // 자릿수 구하기
		{
			digit++;
		}
		result += i; // 분해합은 자기자신을 먼저 더해야 하므로 i를 더함.
		int temp = i; // 자릿수 갯수만큼 잘라서 더하기 위해 i값 넣은 temp생성
		for (int k = 0; k < digit; k++) // 자릿수만큼 나눠서 더하는 반복문
		{
			result += temp % 10; // i를 10으로 나눈 나머지를 더함
			temp /= 10; // 더한 후, 10으로 나눈 몫을 다시저장
		}
		if (result == n) { // 입력받은 분해합이, 내가 만든 분해합과 같으면
			result = i; // result에 i값을 넣어줌
			istrue = true;
		}
		if (result < min && istrue) {//가장 작은 생성자를 구해야 하므로
			min = result;
			itHasMin = true;
		}
	}
	if (itHasMin)
		cout << min <<endl;
	else
		cout << 0 << endl;
}