#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int arr[n];
	int dp[n];
	int max=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i]=1;
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; j++)
		{
			if(arr[j]<arr[i]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;

		}
		if (max < dp[i])
			max = dp[i];
	}

	cout << max;



}