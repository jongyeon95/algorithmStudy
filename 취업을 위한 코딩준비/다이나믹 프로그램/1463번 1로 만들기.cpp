#include <iostream>
using namespace std;

int con(int a, int b){
	if (a>b) return b;
	else return a;
}

int main(){
	int N;
	int dp[1000001];
	cin >> N;
	dp[0]=0;
	dp[1]=0;
	dp[2]=1;
	dp[3]=1;
	if (N<=3){
		cout << dp[N];
	}
	else{
		for (int i = 4; i <= N; i++)
		{
			if(i%3==0){
				dp[i]=con( dp[i/3]+1,dp[i-1]+1);
			}
			else if(i%2==0){
				dp[i]=con( dp[i/2]+1,dp[i-1]+1);
			}
			else dp[i]=dp[i-1]+1;		
		}
		cout << dp[N];
	}

return 0;
}