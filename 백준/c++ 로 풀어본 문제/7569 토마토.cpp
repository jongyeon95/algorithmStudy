#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
struct locate
{
	int x;
	int y;
	int h;
	int count;
};


int x,y,h;
int box[100][100][100];
bool visited[100][100][100];
int dx[]={0,0,0,0,1,-1};
int dy[]={0,0,1,-1,0,0};
int dh[]={1,-1,0,0,0,0};
int result=0;
queue<locate> q;

void bfs(){

	while(!q.empty()){
		locate temp=q.front();
		q.pop();
		if(temp.count>result)
			result=temp.count;
		for (int i = 0; i < 6; ++i)
		{
			int tx=temp.x+dx[i];
			int ty=temp.y+dy[i];
			int th=temp.h+dh[i];
			if(tx<0||ty<0||th<0||tx>=x||ty>=y||th>=h)
				continue;
			if(!visited[th][ty][tx]&&box[th][ty][tx]!=-1){
				box[th][ty][tx]=1;
				visited[th][ty][tx]=true;
				q.push({tx,ty,th,temp.count+1});
			}
		}
	}

}
int main(){
	cin.tie();
	cin >> x >> y >> h;
	memset(box,0,sizeof(box));
	memset(visited,false,sizeof(visited));
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < y; ++j)
			for (int k = 0; k < x; ++k){
				cin >> box[i][j][k];
				if(box[i][j][k]==1){
					visited[i][j][k]=true;
					q.push({k,j,i,0});
				}
			}
	bfs();
				

	for (int i = 0; i < h; ++i)
			for (int j = 0; j < y; ++j)
				for (int k = 0; k < x; ++k){
					if(box[i][j][k]==0){
						cout << -1;
						return 0;
					}
				}

	cout << result;

		

}