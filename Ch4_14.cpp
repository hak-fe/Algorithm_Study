#include <iostream>
#include <cstdlib>
#include < ctime>
#include <string>
using namespace std;
/*
이 문제를 해결하기 위해 필요한 것들
1. 첫 번쨰, 두 번째 선수의 이름을 받을 것. -> 이름 받는 setName 함수 생성. 객체 배열 생성으로 각각 setName할것
2. 각 선수 차례가 오면 enter키를 입력받을 것. -> 2, 3, 4 번은 GmablingGame 생성자에서 동시에 해결할 것
3. 엔터 키를 입력 받으면 랜덤으로 0~2 숫자를 출력할것.
4. 랜덤으로 출력된 숫자를 판단하여 같으면 (이름)님 승리!!를, 아니면 아쉽군요!를 출력.
*/
class Player {
	string name;
public:
	Player();
	void setName(string name) { this->name = name; }; // 이름을 입력 받음
	string getName() { return name; };
};

Player::Player() {

}



class GamblingGame {
	Player* p;
public:
	GamblingGame();
	void playingGame();
};

GamblingGame::GamblingGame() { // 이름 입력하는 부분
	string playerName;
	cout << "***** 겜블링 게임을 시작합니다. *****" << endl;
	p = new Player[2];
	for (int i = 0; i < 2; i++)
	{
		if (i == 0) {
			cout << "첫번째 선수 이름>>";
			cin >> playerName;
			p[i].setName(playerName);
		}
		else {
			cout << "두번째 선수 이름>>";
			cin >> playerName;
			p[i].setName(playerName);
		}
	}
}

void GamblingGame::playingGame() { // 2, 3, 4 부분
	char ch;
	int ranArr[3];
	int isfinish = 0;
	int cnt = 0;
	while (true) {
		for (int i = 0; i < 2; i++)
		{
			srand(time(NULL));
			for (int j = 0; j < 3; j++) // 3번돌아가는데, ranArr 배열에 랜덤한 숫자를 넣어줌.
			{
				ranArr[j] = rand() % 3;
			}
			if (cnt == 0){
				cout << p[i].getName() << ":<Enter>\n";
			cnt++;
			}
			else
				cout << p[i].getName() << ":<Enter>\t";
			cin.get(ch);
			if (ch == '\n') {
				cout << "\t\t";
				for (int k = 0; k < 3; k++)
				{
					cout << ranArr[k] << "\t";
				}
				if (ranArr[0] == ranArr[1] && ranArr[1] == ranArr[2]) {
					cout << p[i].getName() << "님 승리!!";
					isfinish = 1;
					break;
				}
				else
					cout << "아쉽군요!" << endl;
			}
		}
		if (isfinish)
			break;
	}
}

int main(void) {
	GamblingGame play;
	play.playingGame();
}