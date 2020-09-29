#include <iostream>
using namespace std;
int N, S, cnt;
int arr[20];

void Search(int index,int sum) {
	int temp = sum + arr[index];
	if (index >= N) return;
	if (temp == S) cnt++;
	Search(index + 1, sum);
	Search(index + 1, temp);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> S;
	for (int i = 0; i < N; i++) 
		cin >> arr[i];
	Search(0, 0);
	cout << cnt;
}