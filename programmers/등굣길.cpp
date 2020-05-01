#include <string>
#include <vector>
using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	int check[101][101];
	for (int j = 1; j <= n; j++)
		for (int i = 1; i <= m; i++)
			check[j][i] = 1;
		
	for (int i = 0; i < puddles.size(); i++) {
		check[puddles[i][1]][puddles[i][0]] = 0;
		if (puddles[i][0] == 1) {
			for (int j = puddles[i][1]; j <= n; j++) 
				check[j][1] = 0;
		}
		if (puddles[i][1] == 1) {
			for (int j = puddles[i][0]; j <= m; j++)
				check[1][j] = 0;
		}
	}
		
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			if (check[j][i] != 0)
				check[j][i] = (check[j - 1][i] + check[j][i - 1]) % 1000000007;
		}
	}
	return check[n][m];
}