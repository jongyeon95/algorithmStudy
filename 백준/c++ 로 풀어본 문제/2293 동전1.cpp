#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
int dp[10001];
int main(){
	memset(dp,0,sizeof(dp));
	int n,k;
	vector<int> v;
	cin >> n >> k;
	int temp;
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		v.push_back(temp);
	}
	dp[0]=1;

	for (int i = 0; i <n; ++i)
	{
		for (int j = 1; j <=k; ++j)
		{	if(j-v[i]>=0)
				dp[j]+=dp[j-v[i]];
		}
		
	}
	cout << dp[k];




}
