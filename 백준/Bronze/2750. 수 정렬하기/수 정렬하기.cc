#include <iostream>

using namespace std;

void insertion_sort(int a[], int n);

int main()
{
	int n;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	insertion_sort(arr, n);
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}
}
void insertion_sort(int a[], int n) {
	int i, j, tmp;
	for (i = 1; i < n; i++) { 
		tmp = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > tmp) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = tmp;
	}
}