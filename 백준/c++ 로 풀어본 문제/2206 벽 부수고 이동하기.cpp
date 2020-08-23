#include <iostream>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
int n,m;
int minNum;
string arr[1000];
bool visited[1000][1000][2];
int dy[]={1,-1,0,0};
int dx[]={0,0,1,-1};


struct xy
{
	int y;
	int x;
	int wall;
	int dir;
};

void bfs(){
	queue<xy> q;
	q.push({0,0,0,1});
	visited[0][0][0]=true;
	
	while(!q.empty()){
		xy temp=q.front();
		q.pop();
		if(temp.y==n-1&&temp.x==m-1){
			if(temp.dir+1<minNum){
				minNum=temp.dir;
			}
		}


		for (int i = 0; i < 4; ++i)
		{
			int ty=dy[i]+temp.y;
			int tx=dx[i]+temp.x;
			if(ty<0||tx<0||ty>=n||tx>=m)
				continue;

			
			if(arr[ty][tx]=='1'&&temp.wall==0){
					visited[ty][tx][1]=true;
					q.push({ty,tx,1,temp.dir+1});
			}
			else if(arr[ty][tx]=='0'&& !visited[ty][tx][temp.wall]){
				visited[ty][tx][temp.wall]=true;
				q.push({ty,tx,temp.wall,temp.dir+1});
			}

		}


	}


}

int main(){
	minNum=987654321;
	memset(visited,false,sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
			cin >> arr[i];
		
	bfs();
	if(minNum==987654321)
		minNum=-1;
	cout<<minNum;

}