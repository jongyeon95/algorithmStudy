#include <iostream>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin >> a >> b;
	int arr[a][b];
	int dp[a][b];
	for(int i=0; i<a; i++){
		for(int j=0; j<b; j++){
			cin >> arr[i][j];
		}
	}
	dp[0][0]=arr[0][0];
	for (int i = 1; i < b; ++i)
	{
		dp[0][i]=dp[0][i-1]+arr[0][i];
	}
	for(int i=1; i<a; i++){
		int temp1[b];
		int temp2[b];
		for(int j=0; j<b;j++){
			if(j==0)
				temp1[0]=arr[i][0]+dp[i-1][0];
			else{
				if(temp1[j-1]<dp[i-1][j]){
					temp1[j]=dp[i-1][j]+arr[i][j];
				}
				else{
					temp1[j]=temp1[j-1]+arr[i][j];
				}
			}
		}
		for(int j=b-1; j>=0;j--){
			if(j==b-1)
				temp2[b-1]=arr[i][b-1]+dp[i-1][b-1];
			else{
				if(temp2[j+1]<dp[i-1][j]){
					temp2[j]=dp[i-1][j]+arr[i][j];
				}
				else{
					temp2[j]=temp2[j+1]+arr[i][j];
				}
			}
		}
		for(int j=0; j<b; j++){
			if(temp1[j]>temp2[j]){
				dp[i][j]=temp1[j];
			}
			else
				dp[i][j]=temp2[j];
		}
	}
	cout<<dp[a-1][b-1];
}