#include <iostream>
using namespace std;

long long dp[101]={0,};
int main(){
	int testcase;
	int flag=3;
	dp[1]=1;
	dp[2]=1;
	dp[3]=1;
	cin >> testcase;
	while(testcase--){
		int N;
		cin >> N;
		if(dp[N]==0){
			for (int i = flag+1; i <= N; i++)
			{
				dp[i]=dp[i-2]+dp[i-3];
			}
			flag=N;
		}
		cout << dp[N] << endl;
	}
}
