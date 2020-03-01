#include <iostream>
#include <cmath>
using namespace std;
int dp[1500001]={0};
int t[1500001]={0};
int p[1500001]={0};
int n;
int solve(int day){
	if (day==n+1)
		return 0;
	if(day>n+1)
		return -1500000000;
	if (dp[day] > 0)
		return dp[day];

	 return dp[day]=max(solve(day+1),p[day]+solve(day+t[day]));

}


int main(){

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> t[i] >> p[i];
	}

	cout << solve(1);



}