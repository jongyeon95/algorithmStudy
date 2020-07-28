#include <iostream>
using namespace std;
int arr[200];
int dp[200];

int main(){
	int n;
	int max=0;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
		for (int j = 0; j <= i; ++j)
		{
			if(arr[j]<arr[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			}
		}
		if(max<dp[i])
			max=dp[i];
	}

	cout<<n-max;


}