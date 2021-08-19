#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	int temp[3];
	vector<string>name;
	vector<int>year;
	vector<int>month;
	vector<int>day;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string n;
		int y, m, d;
		cin >> n >> d >> m >> y;
		name.push_back(n);
		day.push_back(d);
		month.push_back(m);
		year.push_back(y);
	}
	temp[0] = day[0];
	temp[1] = month[0];
	temp[2] = year[0];
	int low = 0, high = 0;
	for (int i = 1; i < n; i++)
	{
		//나이 적은사람
		if (year[i] > temp[2]) {
			temp[2] = year[i];
			temp[1] = month[i];
			temp[0] = day[i];
			low = i;
		}
		else if (year[i] == temp[2]) {
			if (month[i] > temp[1]) {
				temp[2] = year[i];
				temp[1] = month[i];
				temp[0] = day[i];
				low = i;
			}
			else if (month[i] == temp[1]) {
				if (day[i] > temp[0]) {
					temp[2] = year[i];
					temp[1] = month[i];
					temp[0] = day[i];
					low = i;
				}
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		//나이 많은사람
		if (year[i] < temp[2]) {
			temp[2] = year[i];
			temp[1] = month[i];
			temp[0] = day[i];
			high = i;
		}
		else if (year[i] == temp[2]) {
			if (month[i] < temp[1]) {
				temp[2] = year[i];
				temp[1] = month[i];
				temp[0] = day[i];
				high = i;
			}
			else if (month[i] == temp[1]) {
				if (day[i] < temp[0]) {
					temp[2] = year[i];
					temp[1] = month[i];
					temp[0] = day[i];
					high = i;
				}
			}
		}
	}
	cout << name[low] << '\n' << name[high];
}