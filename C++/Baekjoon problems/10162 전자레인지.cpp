#include <iostream>
using namespace std;

int main() {

	int time;
	cin >> time;
	int ary[3] = { 0, };
	// A는 5분, B는 1분, C는 10초
	// 초단위로 모두 바꾸면
	//300초, 60초 10초
	// 전부 10의 배수이므로, time이 10으로 나누어 떨어지지 않으면
	// -1을 출력한다. -> 시간을 정확히 맞출 수 없기 때문
	// 그 이외는 차례대로 진행
	if (time % 10 == 0) {
		if (time / 300 > 0) {
			ary[0] += time / 300;
			time -= 300 * ary[0];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}	
		}
		if (time / 60 > 0) {
			ary[1] += time / 60;
			time -= 60 * ary[1];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}
		}
		if (time / 10 > 0 ){
			ary[2] += time / 10;
			time -= 10 * ary[2];
			if (time <= 0) {
				for (int i = 0; i < 3; i++)
				{
					cout << ary[i] << " ";
				}
			}
		}
	}
	else
		cout << -1 << endl;
}