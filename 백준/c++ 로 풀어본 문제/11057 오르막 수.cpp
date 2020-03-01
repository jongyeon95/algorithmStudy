#include <iostream>
#include <cstring>
using namespace std;
int dp[1001][10];
int main(){
	memset(dp,0,sizeof(dp));
	int n;
	int result=0;
	cin >> n;
	for (int i = 0; i < 10; ++i)
	{
		dp[1][i]=1;
	}
	for (int i = 2; i <= n; ++i)
	{
		for(int j=0; j<10; j++){
			for (int k = 0; k<=j; ++k)
			{
				dp[i][j]+=dp[i-1][k];
			}
			dp[i][j]%=10007;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		result+=dp[n][i];
		result%=10007;
	}

	cout << result;



}