#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	/*
	펫에게는 적정 체중이 있습니다.
	펫의 실제 체중이 적정 체중의 1/2배를 초과하면서
	적정 체중의 2배 미만이라면 펫은 행복합니다.
	펫의 실제 체중이 0 이하일 경우 펫은 사망하게 되며
	그 외의 경우 펫은 슬픕니다.

	행복한 경우, ":-)"을 출력합니다.
	슬픈 경우 ":-("을 출력합니다.
	사망한 경우 "RIP"를 출력합니다.

	적정 체중(o), 실제 체중(w)
	*/
	int i = 1;
	while (true) {
		int o, w, petState = 0; //1은 행복, 2는 슬픔, 3은 사망
		string behavior;
		cin >> o >> w; //적정 체중, 실제 체중 입력
		if (o == 0 && w == 0)
			break;
		while (true) { // 시나리오 시작
			getline(cin, behavior); // 행동 입력
			if (behavior == "# 0") { //시나리오 종료
				break;
			}
			if (behavior[0] == 'E') {
				w -= stoi(behavior.substr(2));
				if (w <= 0) {
					petState = 3;
				}
				else if (w > o * 0.5 && w < o * 2) {
					if (petState != 3)
						petState = 1;
				}
				else {
					if (petState != 3)
						petState = 2;
				}
			}
			else if (behavior[0] == 'F') {
				w += stoi(behavior.substr(2));
				if (w <= 0) {
					petState = 3;
				}
				else if (w > o * 0.5 && w < o * 2) {
					if (petState != 3)
						petState = 1;
				}
				else {
					if (petState != 3)
						petState = 2;
				}
			}
		}
		if (petState == 1)
		{
			cout << i << " :-)" << '\n';
		}
		else if (petState == 2) {
			cout << i << " :-(" << '\n';
		}
		else {
			cout << i << " RIP" << '\n';
		}
		i++;
	}
}