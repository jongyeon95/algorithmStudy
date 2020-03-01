#include <iostream>
#include <cstring>
using namespace std;
int main(){
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		int n, m;
		cin >> n >> m;
		int dp[n+m+1];
		memset(dp,0,sizeof(dp));
		int max=0;
		for (int i = 1; i <=n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				dp[i+j]+=1;
				if(dp[i+j]>max)
					max=dp[i+j];
			}
		}
		printf("#%d",t);
		for (int i = 1; i <= n+m ; ++i)
		{
			if(dp[i]==max)
				printf(" %d",i);
		
		}
		printf("\n");
	}
}