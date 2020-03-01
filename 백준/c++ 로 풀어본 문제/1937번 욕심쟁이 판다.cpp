#include <iostream>
#include <cmath>
using namespace std;
int n;
int k=0;
int arr[500][500]={0};
int dp[500][500]={0};
int dx[]={1,0,-1,0};//동 남 서 북 
int dy[]={0,1,0,-1};


int dfs(int y, int x){

	if(dp[y][x])
		return dp[y][x];
	dp[y][x]=1;

	for (int i = 0; i < 4; ++i)
	{
		int tx=x+dx[i];
		int ty=y+dy[i];
		if(tx<0||tx>=n||ty<0||ty>=n)
			continue;
		if(arr[ty][tx]<=arr[y][x])
			continue;
		dp[y][x]=max(dp[y][x],dfs(ty,tx)+1);
	}

	return dp[y][x];

}



int main(){
	
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			k=max(k,dfs(i,j));
		}
	}

	cout << k;

}