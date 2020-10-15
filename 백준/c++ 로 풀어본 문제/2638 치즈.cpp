#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int map[100][100];
bool visited[100][100];
int m,n;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};

int bfs(){
	int cnt=0;
	memset(visited,false,sizeof(visited));
	visited[0][0]=true;
	queue<pair<int, int>> q;
	q.push({0,0});
	while(!q.empty()){
		pair<int,int> p=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ty=p.first+dy[i];
			int tx=p.second+dx[i];
			if(ty<0||tx<0||ty>=n||tx>=m){
				continue;
			}
			if(map[ty][tx]==0&&!visited[ty][tx]){
				visited[ty][tx]=true;
				q.push({ty,tx});
			}
			else if(map[ty][tx]!=0){
				map[ty][tx]++;
			}
		}
	}





	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(map[i][j]>2){
				map[i][j]=0;
				cnt++;
			}
			else if(map[i][j]==2){
				map[i][j]=1;
			}
		}
	}

	
	return cnt;
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
		}
	}
	int time=0;
	while(1){
		
		if(bfs()==0){
			cout<<time;
			return 0;
		}
		time++;
		
	}


}