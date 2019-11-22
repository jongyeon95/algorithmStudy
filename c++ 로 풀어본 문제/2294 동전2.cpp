#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
	int arr[101];
	int dp[10001];
	for (int i = 1; i <= k; ++i)
	{
		dp[i]=10001;
	}
	for (int i = 1; i <= n; ++i)
	{
		cin >>arr[i];
	
	for (int j = arr[i]; j <=k; ++j)
	{
		dp[j]=min(dp[j],dp[j-arr[i]]+1);
		
	}
}
if (dp[k]==10001)
	cout<<-1<<endl;
else
	cout << dp[k] <<endl;

}