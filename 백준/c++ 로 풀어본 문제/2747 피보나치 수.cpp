#include <iostream>
using namespace std;
int dp[46];
int main(){
	dp[0]=0;
	dp[1]=1;
	for (int i = 2; i <= 45; ++i)
	{
		dp[i]=dp[i-1]+dp[i-2];
	}
	int n;
	cin >> n;
	cout<<dp[n];

}