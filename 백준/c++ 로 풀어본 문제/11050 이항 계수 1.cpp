#include <iostream>
using namespace std;
int main(){
	int dp[11];
	int n,k;
	int result;
	dp[1]=1;
	dp[0]=1;
	for (int i = 2; i <=11; ++i)
	{
		dp[i]=i*dp[i-1];
	}
	cin >> n >> k;
	result=dp[n]/dp[n-k]/dp[k];
	if(result==0)
		result=1;
	cout << result;
}