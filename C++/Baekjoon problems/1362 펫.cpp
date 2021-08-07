#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
	/*
	�꿡�Դ� ���� ü���� �ֽ��ϴ�.
	���� ���� ü���� ���� ü���� 1/2�踦 �ʰ��ϸ鼭
	���� ü���� 2�� �̸��̶�� ���� �ູ�մϴ�.
	���� ���� ü���� 0 ������ ��� ���� ����ϰ� �Ǹ�
	�� ���� ��� ���� ���Ŵϴ�.

	�ູ�� ���, ":-)"�� ����մϴ�.
	���� ��� ":-("�� ����մϴ�.
	����� ��� "RIP"�� ����մϴ�.

	���� ü��(o), ���� ü��(w)
	*/
	int i = 1;
	while (true) {
		int o, w, petState = 0; //1�� �ູ, 2�� ����, 3�� ���
		string behavior;
		cin >> o >> w; //���� ü��, ���� ü�� �Է�
		if (o == 0 && w == 0)
			break;
		while (true) { // �ó����� ����
			getline(cin, behavior); // �ൿ �Է�
			if (behavior == "# 0") { //�ó����� ����
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