#include <iostream>
#include <algorithm>

using namespace std;

int getMax(int a, int b, int c) {
	int max = a;
	if (b > max)
		max = b;
	if (c > max)
		max = c;
	return max;
}
int getMin(int a, int b, int c) {
	int min = a;
	if (b < min)
		min = b;
	if (c < min)
		min = c;
	return min;
}

int main() {
	int numOfHamburger, numOfSidemenu, numOfDrink;
	int noSetSum = 0, setSum = 0;

	cin >> numOfHamburger >> numOfSidemenu >> numOfDrink;

	int maxNum = getMax(numOfHamburger, numOfSidemenu, numOfDrink);

	int* hamburger = new int[maxNum];
	int* sidemenu = new int[maxNum];
	int* drink = new int[maxNum];

	for (int i = 0; i < numOfHamburger; i++)
	{
		cin >> hamburger[i];
		noSetSum += hamburger[i];
	}
	for (int i = numOfHamburger; i < maxNum; i++)
	{
		hamburger[i] = 0;
	}

	for (int i = 0; i < numOfSidemenu; i++)
	{
		cin >> sidemenu[i];
		noSetSum += sidemenu[i];
	}
	for (int i = numOfSidemenu; i < maxNum; i++)
	{
		sidemenu[i] = 0;
	}

	for (int i = 0; i < numOfDrink; i++)
	{
		cin >> drink[i];
		noSetSum += drink[i];
	}
	for (int i = numOfDrink; i < maxNum; i++)
	{
		drink[i] = 0;
	}

	cout << noSetSum << endl;

	sort(hamburger, hamburger + numOfHamburger, greater<>());
	sort(sidemenu, sidemenu + numOfSidemenu, greater<>());
	sort(drink, drink + numOfDrink,greater<>());

	int i = 0;
	for (; i < getMin(numOfHamburger, numOfSidemenu, numOfDrink); i++)
	{
		setSum += ((hamburger[i] + sidemenu[i] + drink[i]) * 0.9);
	}

	for (; i < maxNum; i++)
	{
		setSum += (hamburger[i] + sidemenu[i] + drink[i]);
	}

	cout << setSum << endl;

	delete hamburger;
	delete sidemenu;
	delete drink;
}