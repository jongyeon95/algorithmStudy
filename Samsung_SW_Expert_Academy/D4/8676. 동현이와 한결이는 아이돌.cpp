#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 1000000007;
int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; ++t)
	{
		int dp[7];
		memset(dp,0,sizeof(dp));
		string s;
		cin >> s;
		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i]=='S'){
				dp[0]=(dp[0]+1)%MAX;
				dp[3]=(dp[2]+dp[3])%MAX;
			}
			else if(s[i]=='A'){
				dp[1]=(dp[0]+dp[1])%MAX;
			}
			else if(s[i]=='M'){
				dp[2]=(dp[2]+dp[1])%MAX;
				
			}
			else if(s[i]=='U'){
				dp[4]=(dp[4]+dp[3])%MAX;
			}
			else if(s[i]=='N'){
				dp[5]=(dp[5]+dp[4])%MAX;
			}
			else if(s[i]=='G'){
				dp[6]=(dp[6]+dp[5])%MAX;
			}
		}
		cout << "#" << t << " " << dp[6] << "\n";

	}
}