#include <iostream>
#include <queue>
using namespace std;
int arr[1001][1001];
int dirX[]={0,-1,0,1};
int dirY[]={1,0,-1,0};
int m,n;
int mx=-2;
queue<pair<int,int>> q;

void Bfs(){
	while(!q.empty()){
		pair<int,int> temp=q.front();
		q.pop();
		int y=temp.first;
		int x=temp.second;
		for (int i = 0; i < 4; ++i)
		{
			int nx=x+dirX[i];
			int ny=y+dirY[i];
			if (nx<1||ny<1||nx>=m+1||ny>=n+1)
				continue;
			if (arr[ny][nx]==0)
			{
				arr[ny][nx]=arr[y][x]+1;
				q.push({ny,nx});
			}
		}

	}		

}


int main(){
	cin >> m >> n;
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> arr[i][j];
			if(arr[i][j]==1){
				q.push({i,j});
			}
		}
	}
	Bfs();
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= m; ++j){
			if(arr[i][j]==0){
				cout << "-1";
				return 0;
			}
			if(arr[i][j]>mx)
				mx=arr[i][j];
		}
	}
	cout << mx-1;


}