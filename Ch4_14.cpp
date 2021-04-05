#include <iostream>
#include <cstdlib>
#include < ctime>
#include <string>
using namespace std;
/*
�� ������ �ذ��ϱ� ���� �ʿ��� �͵�
1. ù ����, �� ��° ������ �̸��� ���� ��. -> �̸� �޴� setName �Լ� ����. ��ü �迭 �������� ���� setName�Ұ�
2. �� ���� ���ʰ� ���� enterŰ�� �Է¹��� ��. -> 2, 3, 4 ���� GmablingGame �����ڿ��� ���ÿ� �ذ��� ��
3. ���� Ű�� �Է� ������ �������� 0~2 ���ڸ� ����Ұ�.
4. �������� ��µ� ���ڸ� �Ǵ��Ͽ� ������ (�̸�)�� �¸�!!��, �ƴϸ� �ƽ�����!�� ���.
*/
class Player {
	string name;
public:
	Player();
	void setName(string name) { this->name = name; }; // �̸��� �Է� ����
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

GamblingGame::GamblingGame() { // �̸� �Է��ϴ� �κ�
	string playerName;
	cout << "***** �׺� ������ �����մϴ�. *****" << endl;
	p = new Player[2];
	for (int i = 0; i < 2; i++)
	{
		if (i == 0) {
			cout << "ù��° ���� �̸�>>";
			cin >> playerName;
			p[i].setName(playerName);
		}
		else {
			cout << "�ι�° ���� �̸�>>";
			cin >> playerName;
			p[i].setName(playerName);
		}
	}
}

void GamblingGame::playingGame() { // 2, 3, 4 �κ�
	char ch;
	int ranArr[3];
	int isfinish = 0;
	int cnt = 0;
	while (true) {
		for (int i = 0; i < 2; i++)
		{
			srand(time(NULL));
			for (int j = 0; j < 3; j++) // 3�����ư��µ�, ranArr �迭�� ������ ���ڸ� �־���.
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
					cout << p[i].getName() << "�� �¸�!!";
					isfinish = 1;
					break;
				}
				else
					cout << "�ƽ�����!" << endl;
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