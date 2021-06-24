#include <iostream>
using namespace std;

int main(void) {

	int N = 0, isFinish = 0, ispass = 0,min = 5000, ori_num = 0 ;
	int cnt5 = 0, cnt3 = 0; // 5와 3의 갯수를 셀 변수

	cin >> N; //설탕 무게
	int ori_N = N; // 원래의 N값을 보관할 변수
	// 아래의 절차를 밟되, 조건을 만족할 경우는 횟수를 출력하고 끝내면 된다.
	//1. 애초에 5로 나누어 떨어지는 경우 -> 가장 적은 횟수
	//2. 5와 3으로 조합하여 나누어 떨어지는 경우 -> 2번째로 적은 횟수
	//3. 3으로만 나누어 떨어지는 경우 -> 3번째로 적은 횟수
	//4. 위 3가지가 해당되지 않는 경우 -> -1 출력

	//1.  5로 나누어 떨어지는 경우
	if (N % 5 == 0) {
		cout << N / 5<< endl;
		isFinish = 1;
	}

	N = ori_N;
	//2-1 5로 빼보다가 3으로 빼보는 경우
	while (isFinish == 0) {
		N -= 5;
		cnt5++;
		if (cnt5 == 1 && N < 3)
			break;
		if (N % 3 == 0) { // ex) 32는 원래 8개가 출력되어야 하는데 
			if (N < min) { // 32 - 5를 하면 27이 나와서 바로 3으로 나눈 몫인 9와 cnt5 값을 더해버려서
				min = N; // 10이 나오게 된다. 이를 방지하기 위해서 3으로 나누어 떨어지는 가장 작은 수와 그때의 cnt5 값을 저장했다
				ori_num = cnt5;
				ispass = 1;
			}
		}
		if (N <= 0 || N < 3)
			break;
	}
	N = ori_N;
	if (min % 3 == 0 && min % 5 != 0 && isFinish == 0) {
		if (ispass) {
			cnt3 += min / 3;
			isFinish = 1;
			cout << ori_num + cnt3 << endl;
		}
		else {
			cnt3 += N / 3;
			isFinish = 1;
			cout << cnt5 + cnt3 << endl;
		}
	}

	cnt5 = 0;
	cnt3 = 0;
	min = 0;
	ori_num = 0;
	//2-2 3으로 빼보다가 5로 빼보는 경우
	while (isFinish == 0) {
		N -= 3;
		cnt3++;
		if (cnt3 == 1 && N < 5)
			break;
		if (N % 5 == 0) {
			if (N < min) {
				min = N;
				ori_num = cnt3;
				ispass = 1;
			}
		}
		if (N <= 0 || N < 5)
			break;
	}
	N = ori_N;
	if (min % 5 == 0 && min % 3 != 0 && isFinish == 0) {
		if (ispass) {
			cnt5 += min / 5;
			isFinish = 1;
			cout << cnt3 + ori_num << endl;
		}
		else {
			cnt5 += N / 5;
			isFinish = 1;
			cout << cnt5 + cnt3 << endl;
		}
	}

	//3. 3으로만 나누어 떨어지는 경우
	if (isFinish == 0 && N % 3 == 0) {
		cout << N / 3 << endl;
		isFinish = 1;
	}

	N = ori_N;

	//4. 되는 경우가 없을 때 -1 출력
	if (isFinish == 0) {
		cout << "-1" << endl;
	}


}
