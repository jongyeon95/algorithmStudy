#include <iostream>
#include <cstring>
using namespace std;
int dp[301][301];
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	memset(dp,0,sizeof(dp));
	int n,m,k;
	int sum=0;
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			cin >> dp[i][j];
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+dp[i][j];
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int x1,x2,y1,y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout<<dp[x2][y2]-dp[x2][y1-1]-dp[x1-1][y2]+dp[x1-1][y1-1]<<"\n";

	}


}