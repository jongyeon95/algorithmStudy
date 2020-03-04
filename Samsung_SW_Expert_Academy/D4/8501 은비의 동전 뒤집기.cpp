#include <iostream>
#include <cstring>
using namespace std;
long long dp[1001];
long long fact[1001];
int factNum=2;

long long factorial(int n){
	long long result=1;
	if(factNum<=n)
		for (int i = factNum; i <=n; ++i)
		{
			fact[i]=(fact[i-1]*i)%1000000007;
		}
	result=fact[n];
	return result;
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	memset(dp,0,sizeof(dp));
	dp[0]=0;
	dp[1]=0;
	int flag=2;
	fact[1]=1;
	for (int t = 1; t <= testcase; ++t)
	{
		int n;
		cin >> n;
		if(n>=flag){
			for (int i = flag; i <= n; ++i)
			{
				dp[i]=(i*dp[i-1]+i/2*factorial(i-1))%1000000007;
			}
		}
		flag=n;
		cout << "#" << t <<" "<< dp[n] << "\n";

	}

}