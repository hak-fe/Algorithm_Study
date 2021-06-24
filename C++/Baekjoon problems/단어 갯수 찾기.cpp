#include <iostream>
#include <string>
using namespace std;

int main(void) {

	string str;
	int cnt = 0;
	int HaveSpaceAtFIrst = false;
	getline(cin, str); // 이와 같은 형식으로 넣으면 string이 공백을 포함함.
	for (int i = 0; i < str.size(); i++) {
		if (i == 0) {
			if (str[0] == 32) {
				HaveSpaceAtFIrst = true;
				if (str[1] == '\0') // 엔터 누르면 널문자 들어간다는 사실을 잊지 말자하..
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
