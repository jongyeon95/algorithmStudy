#include <iostream>
using namespace std;
int main(){
	int dp[301];
	int arr[301];
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1]=arr[1];
	dp[2]=arr[1]+arr[2];
	dp[3]=max(arr[1]+arr[3],arr[2]+arr[3]);
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
	}
	cout << dp[n];

}
