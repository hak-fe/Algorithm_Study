#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string str;
	int cnt = 0;
	int HaveSpaceAtFIrst = false;
	getline(cin, str); // �̿� ���� �������� ������ string�� ������ ������.
	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			if (str[0] == 32) {
				HaveSpaceAtFIrst = true;
				if (str[1] == '\0') // ���� ������ �ι��� ���ٴ� ����� ���� ������..
					break;
				else
					cnt++;
			}
		}
		else {
			if (str[i] == 32 && str[i + 1] != '\0') {
				cnt++;
			}
		}
	}
	if (!HaveSpaceAtFIrst)
		cout << cnt + 1;
	else
		cout << cnt;
}