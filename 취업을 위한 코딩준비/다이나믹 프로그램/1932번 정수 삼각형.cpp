#include <iostream>
using namespace std;

int main(){
	int arr[501][501];
	int dp[501][501];
	int n;
	int result=0;
	int temp=0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
		}
	}
	dp[1][1]=arr[1][1];
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if(j==1) {dp[i][j]=dp[i-1][1]+arr[i][1];}
			else if(j==i){dp[i][j]=dp[i-1][j-1]+arr[i][j];}
			else{

				dp[i][j]=max(dp[i-1][j-1]+arr[i][j],dp[i-1][j]+arr[i][j]);			
			}
		}
	}
for (int i = 1; i <= n; i++)
{
	if (dp[n][i]>temp)
	{
		temp=dp[n][i];
	}
}

cout << temp;

}