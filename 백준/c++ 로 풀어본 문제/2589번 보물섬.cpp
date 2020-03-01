#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char map[50][50];
int X,Y;
bool visited[50][50];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};



int bfs(int x, int y){
	memset(visited,false,sizeof(visited));
	int length=0;
	queue<pair<pair<int,int>,int>> q;
	q.push({{x,y},0});
	visited[x][y]=true;
	while(!q.empty()){
		pair<pair<int,int>,int> p=q.front();
		if(p.second>length)
				length=p.second;
		q.pop();
		for(int i=0; i<4; i++){
			int tx=dx[i]+p.first.first;
			int ty=dy[i]+p.first.second;
			if(tx<0||tx>=X||ty<0||ty>=Y)
				continue;
			if(visited[tx][ty])
				continue;
			if(map[tx][ty]=='W')
				continue;
			q.push({{tx,ty},p.second+1});
			visited[tx][ty]=true;
		}
	}

	return length;

}

int main(){
	cin >> X  >> Y;
	int result=0;
	getchar();
	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			map[i][j]=getchar();
		}
		getchar();
	}

	for (int i = 0; i < X; ++i)
	{
		for (int j = 0; j < Y; ++j)
		{
			if(map[i][j]=='L')
				result=max(result,bfs(i,j));
		}
		
	}


	cout << result;

}