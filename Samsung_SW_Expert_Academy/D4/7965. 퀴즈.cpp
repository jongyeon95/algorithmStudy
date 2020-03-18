#include <iostream>
using namespace std;


int dp[1000001];
long long powpow(long long n){
	long long a=n;
	long long b=1;
	long long temp=n;
	while(temp!=0){
		if(temp&1==1){
			b=(b*a)%1000000007;
		}
		a=(a*a)%1000000007;
		temp>>=1;
	}
	return b;
}


int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	for (int i = 1; i < 1000001; ++i)
	{
		dp[i]=powpow(i);
	}
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		long long result=0;
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			result+=dp[i];
			result%=1000000007;
		}
		cout << "#" << t<<" "<<result<<"\n";
	}
}