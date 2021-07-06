#include <iostream>
#include <string>
using namespace std;

string soloSeat = "*S*";
string coupleSeat = "*LL*";

int main() {
	int cntOfSeat;
	cin >> cntOfSeat;

	string seat, result;
	cin >> seat;
	
	for (int i = 0; i < cntOfSeat;)
	{
		if (seat[i] == 'S') {
			result += soloSeat;
			i++;
		}
		else {
			result += coupleSeat;
			i += 2;
		}
	}

	for (int i = 0; i < cntOfSeat; i++)
	{
		if (result.find("**") != string::npos) {
			result.replace(result.find("**"), 2, "*");
		}
	}
	int cntOfCupHolder = 0;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == '*')
			cntOfCupHolder++;
	}
	if (cntOfCupHolder >= cntOfSeat)
		cout << cntOfSeat << endl;
	else if(cntOfSeat >= cntOfCupHolder)
		cout << cntOfCupHolder << endl;
}