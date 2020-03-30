#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={1,-1,2,-2,2,-2,1,-1};
bool visited[300][300];
int mapsize;
int goalX,goalY;
int result;
struct chess
{
	int y;
	int x;
	int count;
};


void bfs(int y, int x){
	queue<chess> q;
	q.push({y,x,0});
	bool check=false;
	while(!q.empty()&&!check){
		chess temp=q.front();
		q.pop();
		for (int i = 0; i < 8; ++i)
		{
			int ty=temp.y+dy[i];
			int tx=temp.x+dx[i];
			if(tx<0||ty<0||tx>=mapsize||ty>=mapsize)
				continue;
			if(!visited[ty][tx]){
				visited[ty][tx]=true;
				if(ty==goalY&&tx==goalX){
					check=true;
					result=temp.count+1;
					break;
				}
				q.push({ty,tx,temp.count+1});
			}
		}
	}
}

int main(){
	int testcase;
	cin >> testcase;
	while(testcase--){
		memset(visited,false,sizeof(visited));
		int startX,startY;
		result=0;
		cin >> mapsize;
		cin >> startY >> startX;
		cin >> goalY >> goalX;
		visited[startY][startX]=true;
		bfs(startY,startX);
		cout << result <<"\n";

	}
}