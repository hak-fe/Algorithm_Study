#include <iostream>
#include <string>
using namespace std;

string a4 = "AAAA";
string b2 = "BB";

int main() {

	string board;
	cin >> board;
	int len = board.size();
	string result ;

	int cnt = 0;
	if (board == "X") 
	{
		cout << -1 << endl; 
		return 0;
	}
	if (board.find(".") == string::npos) // 점 없는 경우는 완성
	{
		if (len % 2 != 0) {
			cout << -1 << endl;
			return 0;
		}
		if (len == 2) {
			result += b2;
		}
		else if (len % 4 == 0) {
			for (int i = 0; i < len / 4; i++)
			{
				result += a4;
			}
		}
		else if (len % 4 == 2) {
			for (int i = 0; i < len / 4; i++)
			{
				result += a4;
			}
			result += b2;
		}
	}
	else {
		for (int i = 0; i < len; i++)
		{
			if (board[i] == 'X')
			{
				cnt++;
				if (board[i + 1] == '.') {
					if (cnt % 2 != 0) {
						cout << -1 << endl;
						return 0;
					}
					else {
						if (cnt == 2) {
							result += b2;
						}
						else if (cnt % 4 == 0) {
							for (int i = 0; i < cnt / 4; i++)
							{
								result += a4;
							}
						}
						else if (cnt % 4 == 2) {
							for (int i = 0; i < cnt / 4; i++)
							{
								result += a4;
							}
							result += b2;
						}
					}
					cnt = 0;
				}
				if (i == len - 1) {
					if (cnt % 2 != 0) {
						cout << -1 << endl;
						return 0;
					}
					else {
						if (cnt == 2) {
							result += b2;
						}
						else if (cnt % 4 == 0) {
							for (int i = 0; i < cnt / 4; i++)
							{
								result += a4;
							}
						}
						else if (cnt % 4 == 2) {
							for (int i = 0; i < cnt / 4; i++)
							{
								result += a4;
							}
							result += b2;
						}
					}
				}
			}
			else
				result += '.';
		}
	}
	cout << result << endl;
}