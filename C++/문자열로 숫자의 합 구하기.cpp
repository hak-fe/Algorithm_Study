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
		// arr[i]���� �ƽ�Ű�ڵ� ���·� ����ǹǷ� 0�� ���ָ� 10������ �Է��� ���� �Ȱ��� ���´�.
		//Ex) arr[0]�� 7�� �Է��ߴ��� 7�� �ƽ�Ű�ڵ� ���� 55�� ������ �ǹǷ� '0'�� ���༭
		//10���� ������ 7�� �ٲپ� �ش�.
	}
	cout << sum;
}