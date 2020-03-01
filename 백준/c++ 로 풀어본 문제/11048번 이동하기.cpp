#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n,m;
	cin>>n>>m;
	int arr[n][m];
	int dp[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin >> arr[i][j];
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i==0){
				if(j==0)
					dp[i][j]=arr[i][j];
				else
					dp[i][j]=dp[i][j-1]+arr[i][j];
			}
			else if(j==0){
				dp[i][j]=dp[i-1][j]+arr[i][j];
			}
			else{
				dp[i][j]=max(dp[i-1][j],max(dp[i][j-1],dp[i-1][j-1]))+arr[i][j];
			}
		}
	}
	
	cout << dp[n-1][m-1];
	
	
	
	return 0;
}