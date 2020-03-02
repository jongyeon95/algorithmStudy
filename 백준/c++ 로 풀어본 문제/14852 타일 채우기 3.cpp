#include <iostream>
using namespace std;
int main(){
	int n;
	int dp[1000001]={1,2};
	int g[1000001]={0,1};
	cin >> n;
	for (int i = 2; i <=n; ++i){
		g[i]=((dp[i-1]+dp[i-2])%1000000007+g[i-2])%1000000007;
		dp[i]=(dp[i-2]+(2*g[i])%1000000007)%1000000007;
	}
	cout << dp[n];
}