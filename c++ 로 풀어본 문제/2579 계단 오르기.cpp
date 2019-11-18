#include <iostream>
#include <algorithm>
using namespace std;
int main(){
	
	int num;
	cin >> num;
	int stair[num+1];
	int dp[num+1];
	for (int i = 1; i <= num; ++i)
		cin >> stair[i];
	if(num==1)
		cout<< stair[1];
	else if(num==2)
		cout << max(stair[1],stair[2]);
	else{
		dp[0]=0;
		dp[1]=stair[1];
		dp[2]=stair[1]+stair[2];
		for (int j = 3; j <= num; j++)
		{
			dp[j]=max(dp[j-3]+stair[j-1]+stair[j],dp[j-2]+stair[j]);
		}
		cout << dp[num];
	}


}