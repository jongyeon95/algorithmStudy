#include <iostream>

using namespace std;

int main(void) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int Y = 0;
	int M = 0;
	int curY = 0;
	int curM = 0;
	int n; cin >> n;
	int temp;

	for (int i = 0; i < n; i++) {
		cin >> curY;
		curM = curY;
		Y += ( (curY / 30) + 1) * 10;
		M += ((curM / 60) + 1) * 15;
	}
	
	if (Y < M) {
		cout << "Y " << Y << "\n";
	}

	else if (Y > M) {
		cout << "M " << M << "\n";
	}

	else {
		cout << "Y M " << Y << "\n";
	}
}
