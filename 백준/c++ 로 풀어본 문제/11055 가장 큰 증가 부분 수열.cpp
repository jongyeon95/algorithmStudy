#include <iostream>
#include <cstring>
using namespace std;

int n;
int result;
int arr[1000];
int dp[1000];

int main(){
	cin.tie(0);
	cin >> n;
	result=0;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		dp[i]=arr[i];
		
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if(arr[j]<arr[i]&&dp[i]<dp[j]+arr[i])
				dp[i]=dp[j]+arr[i];
		}
		if(dp[i]>result)
			result=dp[i];
	}
	
	cout << result;


}