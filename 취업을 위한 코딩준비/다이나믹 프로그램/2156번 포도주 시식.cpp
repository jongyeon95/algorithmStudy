#include <iostream>
using namespace std;

int main(){
	int grape[10001];
	int dp[10001];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> grape[i];
	}
	dp[1]=grape[1];
	dp[2]=grape[2]+grape[1];
	
	for (int i = 3; i <= n; i++)
	{
		dp[i]=max(dp[i-2]+grape[i],max(dp[i-1],dp[i-3]+grape[i-1]+grape[i]));

	}
	cout << dp[n];

}
