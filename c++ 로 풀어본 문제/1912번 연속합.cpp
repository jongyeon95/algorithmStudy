#include <iostream>
using namespace std;
int main(){
	int dp[100000];
	int arr[100000];
	int n;
	int result=0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >>arr[i];
	}
	dp[0]=arr[0];
	result=dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i]=max(dp[i-1]+arr[i],arr[i]);
		if(result<dp[i]) result=dp[i];
	}
	cout << result;

}