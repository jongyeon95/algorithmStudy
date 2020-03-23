#include <iostream>
#include <cmath>
using namespace std;

int dp[1000];
int arr[1000];

int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i]=1;
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j <i; ++j)
		{
			if(arr[i]<arr[j]){
				dp[i]=max(dp[j]+1,dp[i]);
			}
		}
	}

	int result=0;
	for (int i = 0; i < n; ++i)
	{
		if(dp[i]>result)
			result=dp[i];
	}
	cout << result;

}