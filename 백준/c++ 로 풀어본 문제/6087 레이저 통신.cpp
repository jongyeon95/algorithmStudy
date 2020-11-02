#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int w,h;
char map[100][100];
int visited[100][100];
int answer;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
vector<pair<int, int>> block;

struct Block
{
	int y;
	int x;
	int cnt;
	int dir;

};

void input(){
	cin >> w >> h;
	getchar();
	for (int i = 0; i < h; ++i)
	{
		for(int j =0; j<w; ++j){
			visited[i][j]=987654321;
			map[i][j]=getchar();
			if(map[i][j]=='C'){
				block.push_back({i,j});
			}
		}
		getchar();
	}
	answer=w*h;
}

void bfs(){
	queue<Block> q;
	q.push({block[0].first,block[0].second,0,-1});
	visited[block[0].first][block[0].second]=0;
	while(!q.empty()){
		Block temp=q.front();
		q.pop();
		for(int i=0; i<4; i++){
			int ty=dy[i]+temp.y;
			int tx=dx[i]+temp.x;
			int tempCnt=temp.cnt;
			if(ty<0||tx<0||ty>=h||tx>=w||map[ty][tx]=='*') continue;
			
			if(temp.dir!=i) tempCnt++;
			if(visited[ty][tx]<tempCnt) continue;
			
			visited[ty][tx]=tempCnt;

			if(map[ty][tx]=='C') continue;

			if(temp.dir!=-1) q.push({ty,tx,tempCnt,i});
			else q.push({ty,tx,temp.cnt,i});
			
		}
	}

}

int main(){
	input();
	bfs();
	cout<<visited[block[1].first][block[1].second];
}