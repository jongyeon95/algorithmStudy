#include <iostream>
using namespace std;
int arr[101][101];
long long dp[101][101];

void Solve(int end){
	for (int i = 0; i < end; i++)
	{
		for (int j = 0; j < end; ++j)
		{
			if(dp[i][j]>0){
				if(i+arr[i][j]<end&&i!=end-1){
					dp[i+arr[i][j]][j]+=dp[i][j];
				}
				if(j+arr[i][j]<end&&j!=end-1){
					dp[i][j+arr[i][j]]+=dp[i][j];
				}
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	dp[0][0]=1;
	Solve(n);
	cout<<dp[n-1][n-1];
}
