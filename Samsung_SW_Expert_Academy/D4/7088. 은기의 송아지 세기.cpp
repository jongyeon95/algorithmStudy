#include <iostream>
#include <cstring>
using namespace std;
int arr[100001];
int dp[100001][3];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	int testcase;
	cin >> testcase;
	int N,Q,L,R;
	for (int t = 1; t <= testcase; ++t)
	{
		cin >> N >> Q;
		memset(arr,0,sizeof(arr));
		memset(dp,0,sizeof(dp));
		for (int i = 1; i <=N; ++i){
			cin >> arr[i];
			if(i!=0){
				dp[i][0]+=dp[i-1][0];
				dp[i][1]+=dp[i-1][1];
				dp[i][2]+=dp[i-1][2];
			}
			if(arr[i]==1){
				dp[i][0]++;
			}
			else if(arr[i]==2){
				dp[i][1]++;
			}
			else if(arr[i]==3){
				dp[i][2]++;
			}
		}
		cout<<"#"<<t<<"\n";
		for (int i = 0; i < Q; ++i)
		{
			cin >> L >> R;
			cout <<dp[R][0]-dp[L-1][0]<<" ";
			cout <<dp[R][1]-dp[L-1][1]<<" ";
			cout <<dp[R][2]-dp[L-1][2]<<"\n";

		}
	
		
	}
}
