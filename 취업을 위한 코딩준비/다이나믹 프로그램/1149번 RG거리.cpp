#include <iostream>
using namespace std;

int main(){
	int n;
	int arr[1001][3];
	int dp[1001][3];
	cin >> n;
	for (int i = 1; i <=n; i++)
	{
		cin >> arr[i][0]>> arr[i][1]>> arr[i][2];
	}
	dp[1][0]=arr[1][0];
	dp[1][1]=arr[1][1];
	dp[1][2]=arr[1][2];
	for (int i = 2; i <= n; i++)
	{
		dp[i][0]=min(dp[i-1][1]+arr[i][0],dp[i-1][2]+arr[i][0]);
		dp[i][1]=min(dp[i-1][2]+arr[i][1],dp[i-1][0]+arr[i][1]);
		dp[i][2]=min(dp[i-1][0]+arr[i][2],dp[i-1][1]+arr[i][2]);
	}
	
	cout << min(dp[n][0],min(dp[n][1],dp[n][2]));

}