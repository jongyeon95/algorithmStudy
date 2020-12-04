#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];
	sort(arr, arr + N);

	int sum = 0;
	for (int i = 0; i < N; i++) {
		if (sum + 2 <= arr[i]) break;
		sum += arr[i];
	}
	cout << sum + 1;
	return 0;
}