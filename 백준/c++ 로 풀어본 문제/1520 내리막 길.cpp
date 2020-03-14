#include <iostream>
using namespace std;
int m,n;
int arr[500][500];
int dp[500][500];
int result=0;
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};


int dfs(int x , int y){
	if(dp[x][y]!= -1) return dp[x][y];
	if(x==m-1&&y==n-1) return 1;
	dp[x][y]=0;
	for (int i = 0; i < 4; ++i)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx>=0&&ty>=0&&tx<m&&ty<n){		
			if(arr[x][y]>arr[tx][ty]){
				dp[x][y]+=dfs(tx,ty);
			}
		}
	}

	return dp[x][y];

}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	cin >> m >>n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j <n; ++j)
		{
			cin >> arr[i][j];
			dp[i][j]=-1;
		}
	}

	
	cout << dfs(0,0);

}