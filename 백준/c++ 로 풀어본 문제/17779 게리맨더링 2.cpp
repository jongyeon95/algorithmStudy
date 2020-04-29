#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAX	21
int a[MAX][MAX];
int b[MAX][MAX];
int n;
int total;

int solve(int x, int y, int d1, int d2) {
	memset(b, 0, sizeof(b));
	b[x][y] = 5;
	for (int i = 1; i <= d1; ++i) {
		b[x + i][y - i] = 5;
	}
	for (int i = 1; i <= d2; ++i) {
		b[x + i][y + i] = 5;
	}
	for (int i = 1; i <= d2; ++i) {
		b[x + d1 + i][y - d1 + i] = 5;
	}
	for (int i = 1; i <= d1; ++i) {
		b[x + d2 + i][y + d2 - i] = 5;
	}


	int Rmin = total, Rmax = 0;
	int sum = 0;
	int t = total;

	for (int i = 1; i < x + d1; ++i) {
		for (int j = 1; j <= y; ++j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	Rmin = min(Rmin, sum);
	Rmax = max(Rmax, sum);
	sum = 0;
	
	for (int i = 1; i <= x + d2; ++i) {
		for (int j = n; j > y; --j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	Rmin = min(Rmin, sum);
	Rmax = max(Rmax, sum);
	sum = 0;
	
	for (int i = x + d1; i <= n; ++i) {
		for (int j = 1; j < y - d1 + d2; ++j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}
	Rmin = min(Rmin, sum);
	Rmax = max(Rmax, sum);
	sum = 0;
	
	for (int i = x + d2+1; i <= n; ++i) {
		for (int j = n; j >= y - d1 + d2; --j) {
			if (b[i][j] == 5) break;
			sum += a[i][j];
			t -= a[i][j];
		}
	}

	Rmin = min({ Rmin, sum,t });
	Rmax = max({ Rmax, sum,t });

	return Rmax - Rmin;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> a[i][j];
			total += a[i][j];
		}
	}

	//solution
	int result = total;
	for (int x = 1; x <= n; ++x) {
		for (int y = 1; y <= n; ++y) {
			for (int d1 = 1; d1 < n; ++d1) {
				for (int d2 = 1; d2 < n; ++d2) {
					if (x + d1 + d2 <= n && 1 <= y - d1 && y + d2 <= n) {
						result = min(result, solve(x, y, d1, d2));
					}
				}
			}
		}
	}
	cout << result;

	return 0;
}
