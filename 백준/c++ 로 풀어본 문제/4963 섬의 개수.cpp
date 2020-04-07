#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
int w,h;
int map[50][50];
int answer;
int dx[]={0,0,1,-1,1,-1,1,-1};
int dy[]={1,-1,0,0,1,-1,-1,1};
bool visited[50][50];

void bfs(int y, int x){
	queue<pair<int,int>> q;
	q.push({y,x});
	while(!q.empty()){
		pair<int,int> temp=q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int ty=temp.first+dy[i];
			int tx=temp.second+dx[i];
			if(tx<0||ty<0||tx>=w||ty>=h)
				continue;
			if(!visited[ty][tx]&&map[ty][tx]==1){
				visited[ty][tx]=true;
				q.push({ty,tx});
			}
		}

	}
}

int main(){
	cin.tie(0);
	cout.sync_with_stdio(false);
	while(1){
		cin >> w >> h;
		answer=0;
		if(w==0&&h==0)
			break;
		memset(visited,false,sizeof(visited));
		memset(map,0,sizeof(map));
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				cin >> map[i][j];
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if(map[i][j]==1&&!visited[i][j]){
					visited[i][j]=true;
					bfs(i,j);
					answer++;
				}	
		cout<<answer<<endl;
	}
}