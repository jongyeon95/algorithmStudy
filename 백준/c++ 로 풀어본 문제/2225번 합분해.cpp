#include <iostream>
using namespace std;
int n, k;
int dp[201][201];



int main(){

cin >> n >> k;
for (int i = 0; i <= n; ++i)
{
	dp[1][i]=1;
}

for (int i = 2; i <=k; ++i)
{
	for (int j = 0; j <=n; ++j)
	{
		if(j==0)
			dp[i][j]=1;
		else{
			dp[i][j]=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=1000000000;
		}
	}
}
cout << dp[k][n];
}