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
			else if(map[ty][tx]!=0&&!visited[ty][tx]){
				visited[ty][tx]=true;
				map[ty][tx]=0;
			}
		}
	}

	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==1){
				cnt++;
			}
		}
	}
	return cnt;
}

int main(){
	cin >> n >> m;
	int answer=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			if(map[i][j]==1)
				answer++;
		}
	}
	int time=0;
	while(1){
		time++;
		int temp=bfs();
		if(temp==0){
			cout<<time<<endl;
			cout<<answer;

			break;
		}
		else{
			answer=temp;
		}
	}


}