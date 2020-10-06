#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int main(){
	int n;
	vector<pair<int,int>> v;
	int dp[101];
	int max=0;
	memset(dp,0,sizeof(dp));
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		v.push_back({a,b});
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < n; ++i)
	{
		dp[i]=1;
		for (int j = 0; j < i; ++j)
		{
			if(v[i].second>v[j].second&&dp[i]<=dp[j]){
				dp[i]=dp[j]+1;
				if(max<dp[i])
					max=dp[i];
			}
		}
	}
	
	cout<<n-max;
}