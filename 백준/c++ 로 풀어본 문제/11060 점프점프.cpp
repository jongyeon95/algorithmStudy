#include <iostream>
using namespace std;
int arr[1000];
int dp[1000];
int n;
int main(){
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin>>arr[i];
		dp[i]=987654321;
	}
	dp[0]=0;
	for (int i = 0; i < n; ++i)
	{	
		for (int j = 1; j <=arr[i]; ++j)
		{
			if(j+i>=n)
				break;
			if(dp[i+j]>dp[i]+1){
				dp[i+j]=dp[i]+1;
			}
		}
	}
	if(dp[n-1]==987654321)
		dp[n-1]=-1;
	
	cout<<dp[n-1];
}